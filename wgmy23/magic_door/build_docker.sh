#!/bin/sh

docker build . -t wgmy2023-pwn-magic-door
docker run --rm --name=wgmy2023-pwn-magic-door -p 10001:10001 wgmy2023-pwn-magic-door
