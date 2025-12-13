/* Copyright (c) 2017-2026, Hans Erik Thrane */

#pragma once

#include "roq/args/parser.hpp"

#include "roq/client/flags/settings.hpp"

#include "roq/samples/client/flags/flags.hpp"
#include "roq/samples/client/flags/test.hpp"

namespace roq {
namespace samples {
namespace client {

struct Settings final : public roq::client::flags::Settings, public flags::Flags {
  explicit Settings(roq::args::Parser const &);

  flags::Test const test;  // note! flags/test.json uses "prefix"
};

}  // namespace client
}  // namespace samples
}  // namespace roq
