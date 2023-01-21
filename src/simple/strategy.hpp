/* Copyright (c) 2017-2023, Hans Erik Thrane */

#pragma once

#include "roq/client/event_log_reader.hpp"

namespace simple {

struct Processor final : public roq::client::EventLogReader::Handler {
  static void dispatch(std::string_view const &path);

 protected:
  Processor() = default;

  void operator()(roq::Event<roq::GatewayStatus> const &) override {}
  void operator()(roq::Event<roq::ReferenceData> const &) override {}
  void operator()(roq::Event<roq::MarketStatus> const &) override {}
  void operator()(roq::Event<roq::TopOfBook> const &) override {}
};

}  // namespace simple
