#!/usr/bin/env bash

# Util functions
pexec() { >&2 printf exec; >&2 printf ' %q' "$@"; >&2 printf '\n'; exec "${@:?pexec: missing command}"; }

go-Build-All() {
    cmake -B build .
    cmake --build build
}

go-run() {
    build/simple_server
}

"go-$@"
