FROM ubuntu:22.04 AS base

FROM disconnect3d/nsjail

COPY --from=base / /jail/

COPY interpreter_1 /jail/
COPY flag /jail/

COPY start.sh /
RUN chmod +x /start.sh

CMD [ "/start.sh" ]
