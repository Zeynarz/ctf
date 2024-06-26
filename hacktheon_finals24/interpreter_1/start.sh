#!/bin/bash

nsjail -Ml --port 9999 --user 9999 --group 9999 --time_limit 30 --chroot /jail -- interpreter_1
