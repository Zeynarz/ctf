#!/bin/bash

docker rm -f dict
docker run -d -p 26432:9999 --name dict --restart unless-stopped --privileged dict
