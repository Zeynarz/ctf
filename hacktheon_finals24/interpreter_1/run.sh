#!/bin/bash

docker rm -f interpreter-1
docker run -d -p 33864:9999 --name interpreter-1 --restart unless-stopped --privileged interpreter-1
