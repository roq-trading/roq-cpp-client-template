#!/usr/bin/env bash

if [[ ! -z $CONDA_PREFIX ]]; then
  (>&2 echo -e "\033[1;31mERROR: Please deactivate your conda environment before using this script. Use 'conda deactivate'.\033[0m") && exit 1
fi

TARGET="$1"

echo "TARGET=$TARGET"

case "$TARGET" in
  stable)
    ;;
  unstable)
    ;;
  *)
    (>&2 echo -e "\033[1;31mERROR: Unknown target. Should be 'stable' or 'unstable'.\033[0m") && exit 1
    ;;
esac

echo -e "\033[1;34mBuild...\033[0m"

conda build --channel "https://roq-trading.com/conda/$TARGET"

echo -e "\033[1;34mDone!\033[0m"
echo -e "\033[1;34mYou can find the package in $CONDA_PREFIX/conda-bld'.\033[0m"
