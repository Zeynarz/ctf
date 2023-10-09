FROM ubuntu:22.04@sha256:b492494d8e0113c4ad3fe4528a4b5ff89faa5331f7d52c5c138196f69ce176a6 AS base

# added this myself: (refered to other challanges' docker setup)
RUN DEBIAN_FRONTEND=noninteractive
RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install gdb xinetd -y


WORKDIR /app
COPY memstream run
RUN  echo "FLAG{*** REDACTED ***}" > /flag.txt
RUN  mv /flag.txt /flag-$(md5sum /flag.txt | awk '{print $1}').txt

# deleted some stuff here

# added this line to prevent container from restarting
CMD ["/usr/sbin/xinetd", "-dontfork"]
