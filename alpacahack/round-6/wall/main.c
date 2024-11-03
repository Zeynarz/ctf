#include <stdio.h>
#include <stdlib.h>

char message[4096];

void get_name(void) {
  char name[128];
  printf("What is your name? ");
  scanf("%128[^\n]%*c", name);
  printf("Message from %s: \"%s\"\n", name, message);
}

int main(int argc, char **argv) {
  setbuf(stdin, NULL);
  setbuf(stdout, NULL);
  setbuf(stderr, NULL);

  printf("Message: ");
  scanf("%4096[^\n]%*c", message);
  get_name();
  return 0;
}
