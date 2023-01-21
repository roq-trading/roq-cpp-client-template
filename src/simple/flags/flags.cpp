/* Copyright (c) 2017-2023, Hans Erik Thrane */

#include "simple/flags/flags.hpp"

#include <absl/flags/flag.h>

ABSL_FLAG(  //
    std::string,
    accounts,
    "A1",
    "account");

ABSL_FLAG(  //
    std::string,
    exchange,
    "deribit",
    "exchange");

ABSL_FLAG(  //
    std::string,
    symbols,
    "BTC-PERPETUAL",
    "symbol (regex)");

ABSL_FLAG(  //
    std::string,
    currencies,
    "BTC|USD",
    "currencies (regex)");

namespace simple {
namespace flags {

std::string_view Flags::accounts() {
  static const std::string result = absl::GetFlag(FLAGS_accounts);
  return result;
}

std::string_view Flags::exchange() {
  static const std::string result = absl::GetFlag(FLAGS_exchange);
  return result;
}

std::string_view Flags::symbols() {
  static const std::string result = absl::GetFlag(FLAGS_symbols);
  return result;
}

std::string_view Flags::currencies() {
  static const std::string result = absl::GetFlag(FLAGS_currencies);
  return result;
}

}  // namespace flags
}  // namespace simple
