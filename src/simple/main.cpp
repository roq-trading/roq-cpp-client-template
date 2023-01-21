/* Copyright (c) 2017-2023, Hans Erik Thrane */

#include "roq/api.hpp"

#include "simple/application.hpp"

using namespace std::literals;

namespace {
auto const DESCRIPTION = "Simple Strategy"sv;
}  // namespace

int main(int argc, char **argv) {
  return simple::Application(
             argc,
             argv,
             {
                 .description = DESCRIPTION,
                 .package_name = ROQ_PACKAGE_NAME,
                 .build_version = ROQ_VERSION,
             })
      .run();
}
