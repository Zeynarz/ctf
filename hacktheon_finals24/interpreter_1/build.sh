#!/bin/sh

docker rm -f interpreter-1
docker rmi -f interpreter-1

docker build -t interpreter-1 .
