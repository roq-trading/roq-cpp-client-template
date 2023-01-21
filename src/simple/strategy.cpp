/* Copyright (c) 2017-2023, Hans Erik Thrane */

#include "simple/strategy.hpp"

#include "roq/logging.hpp"

#include "simple/flags/flags.hpp"

using namespace std::literals;

namespace simple {

Strategy::Strategy(roq::client::Dispatcher &dispatcher) : dispatcher_{dispatcher} {
}

void Strategy::operator()(roq::Event<roq::Timer> const &event) {
  // note!
  //   ROQ_v is the environment variable controlling the log verbosity level
  //   ROQ_v=5 (or higher) will enable this line, otherwise there will be no logging
  roq::log::info<5>("event={}"sv, event);
}

void Strategy::operator()(roq::Event<roq::Connected> const &) {
}

void Strategy::operator()(roq::Event<roq::Disconnected> const &) {
}

void Strategy::operator()(roq::Event<roq::DownloadBegin> const &) {
}

void Strategy::operator()(roq::Event<roq::DownloadEnd> const &) {
}

void Strategy::operator()(roq::Event<roq::GatewayStatus> const &) {
}

void Strategy::operator()(roq::Event<roq::ReferenceData> const &) {
}

void Strategy::operator()(roq::Event<roq::MarketStatus> const &) {
}

void Strategy::operator()(roq::Event<roq::MarketByPriceUpdate> const &) {
}

void Strategy::operator()(roq::Event<roq::OrderAck> const &) {
}

void Strategy::operator()(roq::Event<roq::OrderUpdate> const &) {
}

void Strategy::operator()(roq::Event<roq::TradeUpdate> const &) {
}

void Strategy::operator()(roq::Event<roq::PositionUpdate> const &) {
}

void Strategy::operator()(roq::Event<roq::FundsUpdate> const &) {
}

}  // namespace simple
