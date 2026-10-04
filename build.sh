#!/bin/sh

PROGRAM_NAME="escolher-numero"
arch=$(uname -m)
os=$(uname -o | sed s/GNU\\///)

output_name="${PROGRAM_NAME}-${os}-${arch}"

COMMON_FLAGS="-std=c23 -Isrc -Ideps"

FILES="src/*.c"


debug() {
    gcc -Wall -g -O0 $COMMON_FLAGS $FILES -o "$output_name"
}

release() {
    gcc -Wall -s -O2 $COMMON_FLAGS $FILES -o "$output_name"
}

release_static_musl() {
    output_name="${PROGRAM_NAME}-${os}-static-musl-${arch}"

    x86_64-linux-musl-gcc -Wall -s -O2 -static $COMMON_FLAGS $FILES -o "$output_name"
}

release_static_cross_aarch64_linux_musl() {
    output_name="${PROGRAM_NAME}-${os}-static-musl-aarch64"

    aarch64-linux-musl-gcc -Wall -s -O2 -static $COMMON_FLAGS $FILES -o "$output_name"
}

release_cross_x86_64_mingw32ucrt() {
    output_name="${PROGRAM_NAME}-Windows-ucrt-${arch}.exe"

    x86_64-w64-mingw32ucrt-gcc -Wall -s -O2 $COMMON_FLAGS $FILES -o "$output_name"
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
        release_static_musl)
            release_static_musl
            ;;
        release_static_cross_aarch64_linux_musl)
            release_static_cross_aarch64_linux_musl
            ;;
        release_cross_x86_64_mingw32ucrt)
            release_cross_x86_64_mingw32ucrt
            ;;
    esac
done
