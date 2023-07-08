/* Copyright (c) 2017-2023, Hans Erik Thrane */

#include "simple/settings.hpp"

namespace simple {

Settings::Settings() : flags::Flags{flags::Flags::create()} {
}

}  // namespace simple
