/* Copyright (c) 2017-2023, Hans Erik Thrane */

#include "simple/application.hpp"

#include <cassert>
#include <vector>

#include "roq/client.hpp"
#include "roq/exceptions.hpp"

#include "simple/config.hpp"
#include "simple/flags/flags.hpp"
#include "simple/strategy.hpp"

using namespace std::chrono_literals;
using namespace std::literals;

namespace simple {

// === IMPLEMENTATION ===

int Application::main_helper(std::span<std::string_view> const &args) {
  assert(!std::empty(args));
  if (std::size(args) == 1)
    roq::log::fatal("Expected arguments"sv);
  if (std::size(args) != 2)
    roq::log::fatal("Expected exactly one argument"sv);
  Config config;
  auto connections = args.subspan(1);
  roq::client::Trader{config, connections}.dispatch<Strategy>();
  return EXIT_SUCCESS;
}

int Application::main(int argc, char **argv) {
  // wrap arguments (prefer to not work with raw pointers)
  std::vector<std::string_view> args;
  args.reserve(argc);
  for (int i = 0; i < argc; ++i)
    args.emplace_back(argv[i]);
  return main_helper(args);
}

}  // namespace simple
