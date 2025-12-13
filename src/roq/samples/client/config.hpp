/* Copyright (c) 2017-2026, Hans Erik Thrane */

#pragma once

#include "roq/client/config.hpp"

#include "roq/samples/client/settings.hpp"

namespace roq {
namespace samples {
namespace client {

struct Config final : public roq::client::Config {
  explicit Config(Settings const &);

  Config(Config &&) = default;
  Config(Config const &) = delete;

 protected:
  void dispatch(Handler &) const override;

 private:
  Settings const &settings_;
};

}  // namespace client
}  // namespace samples
}  // namespace roq
