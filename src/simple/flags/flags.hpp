/* Copyright (c) 2017-2023, Hans Erik Thrane */

#pragma once

#include <string_view>

namespace simple {
namespace flags {

struct Flags final {
  static bool simulation();
  static std::string_view accounts();
  static std::string_view exchange();
  static std::string_view symbols();
  static std::string_view currencies();
};

}  // namespace flags
}  // namespace simple
