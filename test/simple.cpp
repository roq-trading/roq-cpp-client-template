/* Copyright (c) 2017-2026, Hans Erik Thrane */

#include <catch2/catch_test_macros.hpp>

#include "roq/samples/client/tools/simple.hpp"

using namespace roq;

TEST_CASE("add", "[simple]") {
  CHECK(samples::client::tools::Simple::add(1, 2) == 3);
}
