/* Copyright (c) 2017-2023, Hans Erik Thrane */

#include "simple/flags/flags.hpp"

#include <absl/flags/flag.h>

ABSL_FLAG(  //
    double, quantity, 1.0, "vwap quantity");

namespace simple {
namespace flags {

double Flags::quantity() {
  static double const result = absl::GetFlag(FLAGS_quantity);
  return result;
}

}  // namespace flags
}  // namespace simple
