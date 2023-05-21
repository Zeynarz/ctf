gcc test.c -o test
patchelf --replace-needed libc.so.6 ./lib/libc.so.6 test
patchelf --set-interpreter ./lib/ld-linux-x86-64.so.2 test

gdb ./test
