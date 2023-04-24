undefined8 main(void) {
  logo();
  puts("You have to stop this crash.");
  menu();
  return 0;
}

void menu(void)

{
  int local_10;
  int local_c;
  
LAB_004012d7:
  puts("\n\nChoose an option:");
  puts("1) Connect");
  puts("2) What\'s in the database");
  puts("3) Shell");
  puts("4) Exit");
  __isoc99_scanf("%d",&local_c);
  if (local_c == 4) {
    puts("Exiting program...");
    return;
  }
  if (local_c < 5) {
    if (local_c == 3) {
      puts("/bin/sh not found. System crashed.");
      goto LAB_004012d7;
    }
    if (local_c < 4) {
      if (local_c == 1) {
        puts("\n\nChoose an option:");
        puts("1) Back to Earth");
        puts("2) Satellite");
        __isoc99_scanf(&DAT_00402386,&local_10);
        if (local_10 == 1) {
          vuln("write a msg you want to send >>> ");
        }
        else {
          if (local_10 == 2) {
            puts("Connecting to satellite......");
            sleep(3);
            printf("connection failed......");
            sleep(1);
          }
          else {
            puts("Invalid option.");
          }
        }
      }
      else {
        if (local_c != 2) goto LAB_0040146f;
        printf("Coordinates: %p\n",puts);
      }
      goto LAB_004012d7;
    }
  }
LAB_0040146f:
  puts("Invalid option.");
  goto LAB_004012d7;
}

void vuln(char *param_1) {
  char local_28 [32];

  puts(param_1);
  gets(local_28);
  gets(local_28);
  return;
}
