/* Copyright (c) 2017-2023, Hans Erik Thrane */

#include <catch2/catch_all.hpp>

#include "tools/simple.hpp"

using namespace tools;

TEST_CASE("add", "[simple]") {
  CHECK(Simple::add(1, 2) == 3);
}
