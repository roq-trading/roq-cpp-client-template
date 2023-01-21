/* Copyright (c) 2017-2023, Hans Erik Thrane */

#include <catch2/catch_all.hpp>

#include "tools/simple.hpp"

using namespace strategy;

TEST_CASE("add", "[simple]") {
  CHECK(tools::Simple::add(1, 2) == 3);
}
