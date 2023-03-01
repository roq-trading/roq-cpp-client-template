/* Copyright (c) 2017-2023, Hans Erik Thrane */

#include "simple/config.hpp"

#include "simple/flags/flags.hpp"

namespace simple {

using flags::Flags;

void Config::dispatch(Handler &handler) const {
  // settings
  handler(roq::client::Settings{
      .order_cancel_policy = roq::OrderCancelPolicy::BY_ACCOUNT,
      .order_management = {},
  });
  // accounts
  handler(roq::client::Account{
      .regex = Flags::accounts(),
  });
  // symbols
  handler(roq::client::Symbol{
      .regex = Flags::symbols(),
      .exchange = Flags::exchange(),
  });
  // currencies
  handler(roq::client::Symbol{
      .regex = Flags::currencies(),
      .exchange = {},
  });
}

}  // namespace simple
