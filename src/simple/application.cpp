/* Copyright (c) 2017-2023, Hans Erik Thrane */

#include "simple/application.hpp"

#include <vector>

#include "simple/config.hpp"
#include "simple/strategy.hpp"

using namespace std::literals;

namespace simple {

int Application::main_helper(std::span<std::string_view> const &args) {
  assert(!std::empty(args));  // by convention, first argument is the program
  if (std::size(args) == 1)
    roq::log::fatal("Expected arguments"sv);
  auto connections = args.subspan(1);
  Config config;
  roq::client::Trader{config, connections}.dispatch<Strategy>();
  return EXIT_SUCCESS;
}

int Application::main(int argc, char **argv) {
  std::vector<std::string_view> args;
  for (int i = 0; i < argc; ++i)
    args.emplace_back(argv[i]);
  return main_helper(args);
}

}  // namespace simple
