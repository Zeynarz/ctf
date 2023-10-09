#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct person_t {
  int id;
  int age;
  char *name;
};

void get_value(const char *msg, void *pval) {
  printf("%s", msg);
  if (scanf("%ld%*c", (long*)pval) != 1) // read long integer, otherwise ignore it
  // wait, is the bug at reading a long into an int?  Then I can just write got address there
  // and getline will overwrite the got entry                             
    exit(1);
}

void get_string(const char *msg, char **pbuf) {
  size_t n;
  printf("%s", msg);
  getline(pbuf, &n, stdin);
  (*pbuf)[strcspn(*pbuf, "\n")] = '\0';
}

int main() {
  struct person_t employee = { 0 }; // initialize all properties to 0

  employee.id = rand() % 10000;
  get_value("Age: ", &employee.age);
  if (employee.age < 0) {
    puts("[-] Invalid age");
    exit(1);
  }
  get_string("Name: ", &employee.name);
  printf("----------------\n"
         "ID: %04d\n"
         "Name: %s\n"
         "Age: %d\n"
         "----------------\n",
         employee.id, employee.name, employee.age);

  free(employee.name);
  exit(0);
}

__attribute__((constructor))
void setup(void) {
  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);
  setvbuf(stderr, NULL, _IONBF, 0);
  srand(time(NULL));
}
