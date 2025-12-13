/* Copyright (c) 2017-2026, Hans Erik Thrane */

#pragma once

#include <span>
#include <string_view>

#include "roq/service.hpp"

// note! the following are your implementations

#include "roq/samples/client/config.hpp"
#include "roq/samples/client/settings.hpp"
#include "roq/samples/client/strategy.hpp"

namespace roq {
namespace samples {
namespace client {

struct Application final : public roq::Service {
  using Service::Service;  // inherit constructors

 protected:
  int main(roq::args::Parser const &) override;

  void simulation(Settings const &, Config const &, std::span<std::string_view const> const &params);
  void trading(Settings const &, Config const &, std::span<std::string_view const> const &params);

 private:
  using value_type = Strategy;  // note!
};

}  // namespace client
}  // namespace samples
}  // namespace roq
