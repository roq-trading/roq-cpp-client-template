/* Copyright (c) 2017-2026, Hans Erik Thrane */

#include "roq/samples/client/settings.hpp"

namespace roq {
namespace samples {
namespace client {

Settings::Settings(roq::args::Parser const &args) : roq::client::flags::Settings{args}, flags::Flags{flags::Flags::create()}, test{flags::Test::create()} {
}

}  // namespace client
}  // namespace samples
}  // namespace roq
