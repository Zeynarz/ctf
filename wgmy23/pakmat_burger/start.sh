#!/bin/sh

# Generate a new random SECRET_MESSAGE for each connection
export SECRET_MESSAGE=$(openssl rand -hex 4 2>/dev/null)

# Start socat
exec socat -T 30 TCP-LISTEN:10001,reuseaddr,fork EXEC:/home/pakmat_burger/pakmat_burger