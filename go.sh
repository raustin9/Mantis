#!/usr/bin/env bash

# Util functions
pexec() { >&2 printf exec; >&2 printf ' %q' "$@"; >&2 printf '\n'; exec "${@:?pexec: missing command}"; }

go-Build-All() {
    pexec cmake -B build .
    
    pexec cmake --build build
}

go-Run-Simple() {
    pexec build/simple_server
}

"go-$@"
