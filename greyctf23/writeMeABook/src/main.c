void main(void) {
  setup();
  puts("Welcome to the library of hopes and dreams!");
  puts("\nWe heard about your journey...");
  puts("and we want you to share about your experiences!");
  puts("\nWhat would you like your author signature to be?");
  printf("> ");
  author_signature._0_4_ = 0x207962;
  __isoc99_scanf("%12s",0x4040d3);
  puts("\nGreat! We would like you to write no more than 10 books :)");
  puts("Please feel at home.");
  secure_library();
  write_books();
  puts("Goodbye!");
  return;
}

void secure_library(void){
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  int local_18;

  uVar6 = seccomp_init(0);

  // only these syscalls are allowed
  uVar1 = seccomp_rule_add(uVar6,SCMP_ACT_ALLOW,2,0); // read
  uVar2 = seccomp_rule_add(uVar6,SCMP_ACT_ALLOW,0,0); // write
  uVar3 = seccomp_rule_add(uVar6,SCMP_ACT_ALLOW,1,0); // open
  uVar4 = seccomp_rule_add(uVar6,SCMP_ACT_ALLOW,0xe7,0); // exit_group
  uVar5 = seccomp_rule_add(uVar6,SCMP_ACT_ALLOW,0x3c,0); // exit
  if ((uVar1 | uVar2 | uVar3 | uVar4 | uVar5) != 0) {
    puts("Something went wrong! Contact an administrator.");
    exit_library();
  }
  seccomp_load(uVar6);
  local_18 = 0;
  while (local_18 < 0x20) {
    malloc(0x10);
    malloc(0x20);
    malloc(0x30);
    malloc(0x40);
    local_18 = local_18 + 1;
  }
  return;
}
