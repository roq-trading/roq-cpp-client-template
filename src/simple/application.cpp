/* Copyright (c) 2017-2025, Hans Erik Thrane */

#include "simple/application.hpp"

#include <cassert>
#include <vector>

#include "roq/client.hpp"

#include "simple/settings.hpp"

using namespace std::literals;
using namespace std::chrono_literals;  // NOLINT

namespace simple {

// === IMPLEMENTATION ===

int Application::main(roq::args::Parser const &args) {
  auto params = args.params();
  if (std::empty(params)) {
    roq::log::warn("You must provide at least one argument!"sv);
    roq::log::warn("  For simulation: paths to event-logs (the .roq files created by gateways)"sv);
    roq::log::warn("  For live trading: paths to unix sockets (the .sock files created by gateways)"sv);
    roq::log::fatal("Unexpected"sv);
  }
  Settings settings{args};
  Config config{settings};
  roq::client::Trader{settings, config, params}.dispatch<value_type>(settings);
  return EXIT_SUCCESS;
}

}  // namespace simple
