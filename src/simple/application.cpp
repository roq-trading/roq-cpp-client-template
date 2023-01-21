/* Copyright (c) 2017-2023, Hans Erik Thrane */

#include "simple/application.hpp"

#include <stdexcept>
#include <vector>

#include "roq/exceptions.hpp"
#include "simple/strategy.hpp"

using namespace std::literals;

namespace simple {

int Application::main_helper(std::span<std::string_view> const &args) {
  if (std::size(args) < 2) roq::log::fatal("Expected at least 1 argument"sv);
  for (auto &path : args.subspan(1)) Strategy::dispatch(path);
  return EXIT_SUCCESS;
}

int Application::main(int argc, char **argv) {
  // wrap arguments (prefer to not work with raw pointers)
  std::vector<std::string_view> args;
  args.reserve(argc);
  for (int i = 0; i < argc; ++i) args.emplace_back(argv[i]);
  return main_helper(args);
}

}  // namespace simple
