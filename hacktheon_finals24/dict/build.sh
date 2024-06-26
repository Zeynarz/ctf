#!/bin/sh

docker rm -f dict
docker rmi -f dict

docker build -t dict .
