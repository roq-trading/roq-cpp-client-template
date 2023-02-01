A template project for creating your own strateiges.

The project includes

* Bare-minimum implementation needed to support strategy development

  * Supports live and simulation.

* A static library (named `tools`)

  * Allows you to build testable logic separate from the actual strategy.

* Test target

  * Using Catch2

* Benchmark target

  * Using Google benchmark


## Prerequisites

> Use `stable` for (the approx. monthly) release build and `unstable` for the more regularly updated development builds.

### Create environment (Miniforge)

```bash
scripts/create_conda_env.sh stable debug
```

### Activate environment

```bash
source opt/conda/bin/activate
```

## Build the project

```bash
cmake . && make -j4
```

## Building your conda package

```bash
scripts/build_conda_package.sh stable
```
