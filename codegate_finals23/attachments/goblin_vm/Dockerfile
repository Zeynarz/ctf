FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install xinetd patchelf -y

RUN useradd -ms /bin/bash ctf

ADD ./share/ /home/ctf

RUN chown -R root:ctf /home/ctf
RUN chmod -R 750 /home/ctf

ADD ./goblin_vm.xinetd /etc/xinetd.d/goblin_vm

RUN patchelf --replace-needed libc.so.6 /home/ctf/libc.so.6 /home/ctf/goblin_vm
RUN patchelf --set-interpreter /home/ctf/ld-linux-x86-64.so.2 /home/ctf/goblin_vm

CMD ["/usr/sbin/xinetd", "-dontfork"]
