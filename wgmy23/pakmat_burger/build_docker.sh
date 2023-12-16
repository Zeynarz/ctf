#!/bin/sh

docker build . -t wgmy2023-pwn-pakmat-burger
docker run --rm --name=wgmy2023-pwn-pakmat-burger -p 10001:10001 wgmy2023-pwn-pakmat-burger
