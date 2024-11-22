/* Copyright (c) 2017-2025, Hans Erik Thrane */

#include <benchmark/benchmark.h>

#include "roq/samples/client/tools/simple.hpp"

using namespace roq;

void BM_tools_Simple_add(benchmark::State &state) {
  for (auto _ : state) {
    benchmark::DoNotOptimize(samples::client::tools::Simple::add(1, 2));
  }
}

BENCHMARK(BM_tools_Simple_add);
