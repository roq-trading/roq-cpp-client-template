/* Copyright (c) 2017-2023, Hans Erik Thrane */

#pragma once

#include "roq/args/parser.hpp"

#include "roq/client/flags/settings.hpp"

#include "simple/flags/flags.hpp"

namespace simple {

struct Settings final : public roq::client::flags::Settings, public flags::Flags {
  explicit Settings(roq::args::Parser const &);
};

}  // namespace simple
