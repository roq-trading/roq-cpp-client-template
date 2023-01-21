/* Copyright (c) 2017-2023, Hans Erik Thrane */

#include "simple/strategy.hpp"

#include "simple/flags/flags.hpp"

using namespace std::chrono_literals;
using namespace std::literals;

namespace strategy {

void Strategy::dispatch(std::string_view const &path) {
  Strategy strategy;
  auto reader = roq::client::EventLogReaderFactory::create(path);
  (*reader).dispatch(processor);
}

}  // namespace strategy
