#!/bin/sh

PROGRAM_NAME="escolher-numero"
arch=$(uname -m)
os=$(uname -o | sed s/GNU\\///)

output_name="${PROGRAM_NAME}-${os}-${arch}"

COMMON_FLAGS="-std=c23 -Isrc -Ideps"


debug() {
    gcc -Wall -g -O0 $COMMON_FLAGS ./src/main.c -o "$output_name"
}

release() {
    gcc -Wall -s -O2 $COMMON_FLAGS ./src/main.c -o "$output_name"
}

release_static() {
    gcc -Wall -s -O2 -static $COMMON_FLAGS ./src/main.c -o "$output_name"
}

for i in "$@"; do
    >&2 echo "$i"

    case "$i" in
        debug)
            debug
            ;;
        release)
            release
            ;;
        release_static)
            release_static
            ;;
    esac
done
