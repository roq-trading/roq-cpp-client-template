/* Copyright (c) 2017-2023, Hans Erik Thrane */

#include <benchmark/benchmark.h>

#include "tools/simple.hpp"

using namespace strategy;

void BM_tools_Simple_add(benchmark::State &state) {
  for (auto _ : state) {
    benchmark::DoNotOptimize(tools::Simple::add(1, 2));
  }
}

BENCHMARK(BM_tools_Simple_add);
