
FROM ghcr.io/battleofthebots/botb-base-image:ubuntu-20.04-defcon-2023

RUN apt-get install patchelf

USER user

WORKDIR /home/user

COPY ld-2.23.so /tmp/ld-2.23.so
COPY libc.so.6 .

USER root
RUN patchelf --set-interpreter /tmp/ld-2.23.so ./libc.so.6

RUN chmod +x /tmp/ld-2.23.so
RUN chmod +x /home/user/libc.so.6

USER user
COPY offthemarket.c .
COPY Makefile .

COPY exploit.py .

RUN make
RUN rm offthemarket.c Makefile

RUN patchelf --set-rpath $PWD ./astral-avenue


EXPOSE 9002
CMD ["socat", "-T60", "TCP-LISTEN:9002,reuseaddr,fork", "EXEC:/home/user/astral-avenue"]
