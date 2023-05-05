/* Copyright (c) 2017-2023, Hans Erik Thrane */

#include "simple/application.hpp"

#include <cassert>
#include <vector>

#include "roq/client.hpp"

#include "simple/flags/flags.hpp"

using namespace std::chrono_literals;
using namespace std::literals;

namespace simple {

// === CONSTANTS ===

namespace {
auto const SNAPSHOT_FREQUENCY = 1s;
auto const MATCHER = "simple"sv;  // note! filled when market is crossed
auto const MARKET_DATA_LATENCY = 1ms;
auto const ORDER_MANAGEMENT_LATENCY = 10ms;
}  // namespace

// === IMPLEMENTATION ===

int Application::main(int argc, char **argv) {
  std::vector<std::string_view> args;
  for (int i = 0; i < argc; ++i)
    args.emplace_back(argv[i]);
  return main_helper(args);
}

int Application::main_helper(std::span<std::string_view> const &args) {
  assert(!std::empty(args));
  if (std::size(args) == 1) {
    roq::log::warn("You must provide at least one argument!"sv);
    roq::log::warn("  For simulation: paths to event-logs (the .roq files created by gateways)"sv);
    roq::log::warn("  For live trading: paths to unix sockets (the .sock files created by gateways)"sv);
    roq::log::fatal("Unexpected"sv);
  }
  Config config;
  auto connections = args.subspan(1);  // note! drop program name
  if (flags::Flags::simulation()) {
    simulate(config, connections);
  } else {
    live(config, connections);
  }
  return EXIT_SUCCESS;
}

void Application::simulate(Config const &config, std::span<std::string_view> const &connections) {
  auto collector = roq::client::detail::SimulationFactory::create_collector(SNAPSHOT_FREQUENCY);
  auto create_generator = [&connections](auto source_id) {
    return roq::client::detail::SimulationFactory::create_generator(connections[source_id], source_id);
  };
  auto create_matcher = [](auto &dispatcher) {
    return roq::client::detail::SimulationFactory::create_matcher(dispatcher, MATCHER);
  };
  auto factory = roq::client::Simulator::Factory{
      .create_generator = create_generator,
      .create_matcher = create_matcher,
      .market_data_latency = MARKET_DATA_LATENCY,
      .order_management_latency = ORDER_MANAGEMENT_LATENCY,
  };
  roq::client::Simulator{config, factory, *collector}.dispatch<value_type>();
}

void Application::live(Config const &config, std::span<std::string_view> const &connections) {
  roq::client::Trader{config, connections}.dispatch<value_type>();
}

}  // namespace simple
