#!/usr/bin/env bash
# 
# Common shell functions for the devtools directory.
#
# Usage:
#   source devtools/common.sh

# Copied from test/unit.sh
banner() {
  echo -----
  echo "$@"
  echo -----
}

mypy_() {
  local system=mypy
  local pip_global=/usr/local/bin/mypy
  local pip_user=~/.local/bin/mypy

  if test -x $pip_user; then
    $pip_user "$@"
  elif test -x $pip_global; then
    $pip_global "$@"
  else
    $system "$@"
  fi
}

typecheck() {
  # we 'import libc' but the source is pyext/libc.{c,pyi}

  echo "MYPY $@"

  MYPYPATH='.:pyext' PYTHONPATH='.' mypy_ --py2 "$@"
}

main() {
  if [ $# -eq 0 ]; then
    echo "usage: $0 <function name>"
    exit 1
  fi

  "$@"
}

readonly MYPY_FLAGS='--strict --no-strict-optional'
readonly COMMENT_RE='^[ ]*#'

