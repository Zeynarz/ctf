#!/bin/sh

docker build . -t wgmy2023-pwn-free-juice
docker run --rm --name=wgmy2023-pwn-free-juice -p 10001:10001 wgmy2023-pwn-free-juice
