#!/bin/sh

docker rm -f simpllocator
docker rmi -f simpllocator

docker build -t simpllocator .
