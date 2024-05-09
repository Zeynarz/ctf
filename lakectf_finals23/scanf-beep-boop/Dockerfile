FROM docker.io/library/ubuntu@sha256:2b7412e6465c3c7fc5bb21d3e6f1917c167358449fecac8176c6e496e5c1f05f as builder

RUN useradd -u 1000 jail

FROM pwn.red/jail

COPY --from=builder / /srv
COPY run /srv/app/run
COPY libc.so.6 /srv/app/libc.so.6
COPY ld-linux-x86-64.so.2 /srv/app/ld-linux-x86-64.so.2
COPY flag /srv/app/flag

RUN chmod 755 /srv/app/run /srv/app/ld-linux-x86-64.so.2
RUN chmod 744 /srv/app/flag

ENV JAIL_TIME 120
ENV JAIL_CONNS_PER_IP 5
ENV JAIL_MEM 20M
