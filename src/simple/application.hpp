/* Copyright (c) 2017-2023, Hans Erik Thrane */

#pragma once

#include <span>

#include "roq/tool.hpp"

namespace simple {

class Application final : public roq::Tool {
 public:
  using roq::Tool::Tool;

 protected:
  int main_helper(std::span<std::string_view> const &args);
  int main(int argc, char **argv) override;
};

}  // namespace simple
