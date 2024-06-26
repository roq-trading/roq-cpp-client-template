A template project to help you get started with creating your own strategies using Roq's C++ API.

The project includes

* Bare-minimum implementation needed to support strategy development

  * Live trading
  * Simulation

* A static library (named `tools`)

  * Allows you to build testable logic separate from the actual strategy

* Test target

  * Using Catch2

* Benchmark target

  * Using Google benchmark

* Conda build recipe


## Prerequisites

> Use `stable` for (the approx. monthly) release build.
> Use `unstable` for the more regularly updated development builds.

### Initialize sub-modules

```bash
git submodule update --init --recursive
```

### Create development environment

```bash
scripts/create_conda_env unstable debug
```

### Activate environment

```bash
source opt/conda/bin/activate dev
```

## Build the project

> Sometimes you may have to delete CMakeCache.txt if CMake has already cached an incorrect configuration.

```bash
cmake . && make -j4
```
