#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NOTE 8

unsigned short size_list[MAX_NOTE];
unsigned char *note_list[MAX_NOTE];

size_t get_val(const char *s) {
  size_t val;
  printf("%s", s);
  if (scanf("%ld%*c", &val) != 1) {
    puts("[-] I/O Error");
    exit(1);
  }
  return val;
}

size_t get_index() {
  size_t idx;
  idx = get_val("Index: ");
  // negative index doesnt work, size_t is unsigned
  // idx is checked using sizeof(size_list), so idx 0-16 works
  if (idx > sizeof(size_list)) {
    puts("[-] Invalid index");
    exit(1);
  }
  return idx;
}

size_t get_size() {
  size_t sz;
  sz = get_val("Size: ");
  if (sz > 0x100) {
    puts("[-] Invalid size");
    exit(1);
  }
  return sz;
}

int main() {
  size_t idx, sz;
  setbuf(stdin, NULL);
  setbuf(stdout, NULL);

  puts("1. Create\n"
       "2. Edit\n"
       "3. Read\n"
       "4. Delete");
  while (1) {
    switch (get_val("> ")) {
      case 1: // Create
        idx = get_index();
        if (note_list[idx]) {
          puts("[-] Slot in use");
          exit(1);
        }

        sz = get_size();
        if (!(note_list[idx] = (unsigned char*)malloc(sz)))
          exit(1);

        size_list[idx] = sz;
        memset(note_list[idx], 0, size_list[idx]);
        break;

      case 2: // Edit
        idx = get_index();
        if (!note_list[idx]) {
          puts("[-] Empty slot");
          exit(1);
        }

        printf("Content: ");
        fgets(note_list[idx], size_list[idx], stdin);
        break;

      case 3: // Read
        idx = get_index();
        if (!note_list[idx]) {
          puts("[-] Empty slot");
          exit(1);
        }

        printf("Content: ");
        fwrite(note_list[idx], size_list[idx], sizeof(unsigned char), stdout);
        break;

      case 4: // Delete
        idx = get_index();
        if (!note_list[idx]) {
          puts("[-] Empty slot");
          exit(1);
        }

        free(note_list[idx]);
        note_list[idx] = NULL;

        // didnt reset size_list
        break;

      default:
        return 0;
    }
  }
}
