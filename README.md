A template project

## Prerequisites

The project is primarily designed to be compatible with the conda package manager.

### Create environment (Miniforge)

```bash
scripts/create_conda_env.sh debug
```

### Activate environment

```bash
source opt/conda/bin/activate
```

### Install Dependencies (for this project)

```bash
conda install -y --channel https://roq-trading.com/conda/stable roq-client 
```

## Building

```bash
cmake . && make -j4
```
