/* Copyright (c) 2017-2025, Hans Erik Thrane */

#pragma once

#include "roq/client.hpp"

#include "roq/samples/client/settings.hpp"

namespace roq {
namespace samples {
namespace client {

struct Strategy final : public roq::client::Handler {
  Strategy(roq::client::Dispatcher &, Settings const &);

  Strategy(Strategy &&) = default;
  Strategy(Strategy const &) = delete;

 protected:
  void operator()(roq::Event<roq::Timer> const &) override;
  void operator()(roq::Event<roq::Control> const &) override;
  void operator()(roq::Event<roq::Connected> const &) override;
  void operator()(roq::Event<roq::Disconnected> const &) override;
  void operator()(roq::Event<roq::DownloadBegin> const &) override;
  void operator()(roq::Event<roq::DownloadEnd> const &) override;
  void operator()(roq::Event<roq::GatewayStatus> const &) override;
  void operator()(roq::Event<roq::ReferenceData> const &) override;
  void operator()(roq::Event<roq::MarketStatus> const &) override;
  void operator()(roq::Event<roq::MarketByPriceUpdate> const &) override;
  void operator()(roq::Event<roq::OrderAck> const &) override;
  void operator()(roq::Event<roq::OrderUpdate> const &) override;
  void operator()(roq::Event<roq::TradeUpdate> const &) override;
  void operator()(roq::Event<roq::PositionUpdate> const &) override;
  void operator()(roq::Event<roq::FundsUpdate> const &) override;

 private:
  roq::client::Dispatcher &dispatcher_;
  // demo how to use settings (flags)
  std::string_view const symbols_;
  std::chrono::nanoseconds const update_freq_;
};

}  // namespace client
}  // namespace samples
}  // namespace roq
