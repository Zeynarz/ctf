#!/bin/bash

docker rm -f simpllocator
docker run -d -p 17935:9999 --name simpllocator --restart unless-stopped --privileged simpllocator
