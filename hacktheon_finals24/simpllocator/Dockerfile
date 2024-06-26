FROM python:3.11-slim AS base

FROM disconnect3d/nsjail

COPY --from=base / /jail/

COPY simpllocator.so /jail/
COPY simpllocator.py /jail/
COPY run_py.sh /jail/
RUN chmod +x /jail/run_py.sh
COPY flag /jail/

COPY start.sh /
RUN chmod +x /start.sh

CMD [ "/start.sh" ]
