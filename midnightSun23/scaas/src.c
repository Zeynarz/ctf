undefined4 main(undefined4 param_1,undefined4 param_2) {
  EVP_PKEY_CTX *in_stack_fffffff0;
  
  gargc = param_1;
  gargv = param_2;
  init(in_stack_fffffff0);
  banner();
  set_timeout();
  menu();
  return 0;
}

void menu(void){
  uint uVar1;
  
  while( true ) {
    print_menu();
    uVar1 = get_int();
    if (uVar1 == 3) break;
    if (uVar1 < 4) {
      if (uVar1 == 1) {
        download_service();
      }
      else {
        if (uVar1 == 2) {
          unlock_serivce();
        }
      }
    }
  }
  exit(0);
}

void download_service(void)

{
  if (1 < gargc) {
    printf("\nHere is your SCAAS service: (\n%s)\n",*(undefined4 *)(gargv + 4));
  }
  return;
}

void unlock_serivce(void) {
  int iVar1;

  puts("\nPlease unlock the SCAAS service before you run out of credits");
  iVar1 = stage_one();
  if (iVar1 != 0) {
    iVar1 = stage_two();
    if (iVar1 != 0) {
      iVar1 = stage_three();
      if (iVar1 != 0) {
        scaas();
        return;
      }
    }
  }
  puts("[\x1b[0;31mACCESS DENIED\x1b[0m] - Incorrect password!");
  exit(0);
}


undefined4 stage_one(void) {
  undefined4 uVar1;
  int local_10;

  puts("Enter passwords for Stage 1");
  local_10 = 0;
  while (local_10 < 5) {
    printf("Enter password %d: ",local_10);
    uVar1 = get_int();
    *(password_one + local_10 * 4) = uVar1;
    local_10 = local_10 + 1;
  }
  if ((((password_one._0_4_ == 0x916d00) && (password_one._4_4_ == 0x707817)) &&
      (password_one._8_4_ != 0)) &&
     ((password_one._12_4_ == 0x840bc2 && (password_one._16_4_ == 0x89228a)))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

undefined4 stage_two(void) {
  undefined4 uVar1;
  int local_10;

  puts("Enter passwords for Stage 2");
  local_10 = 0;
  while (local_10 < 5) {
    printf("Enter password %d: ",local_10);
    uVar1 = get_int();
    *(undefined4 *)(password_two + local_10 * 4) = uVar1;
    local_10 = local_10 + 1;
  }
  if (((((uint)(password_two._0_4_ * 0x526) % 0x31ef03 == 0x1149) &&
       (password_two._4_4_ == 0x2f5ac6)) && (password_two._8_4_ + 0x1c8 == password_two._12_4_)) &&
     ((password_two._12_4_ == 0x40169 && (password_two._16_4_ % 0x2b6 == 1)))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


undefined4 stage_three(void){
  undefined4 uVar1;
  int local_10;

  puts("Enter passwords for Stage 3");
  local_10 = 0;
  while (local_10 < 5) {
    printf("Enter password %d: ",local_10);
    uVar1 = get_int();
    *(undefined4 *)(password_three + local_10 * 4) = uVar1;
    local_10 = local_10 + 1;
  }
  if (((((uint)(password_three._0_4_ * 0x213f) % 0x2b27ea == 0x5fa6) &&
       (password_three._4_4_ == 0x96ac81)) &&
      (password_three._8_4_ + -0x1278 == password_three._12_4_ + 0xcca)) &&
     ((password_three._12_4_ == 0x5fd4d5 &&
      (password_three._16_4_ == (password_three._16_4_ / 0x5a5) * 0x5a5)))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


void scaas(void)

{
  undefined4 uVar1;
  code *pcVar2;
  char cVar3;
  size_t sVar4;
  undefined *puVar5;
  int in_GS_OFFSET;
  undefined auStack44 [8];
  undefined4 local_24;
  undefined4 local_20;
  undefined *local_1c;
  code *local_18;
  code *local_14;
  int local_10;

  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = 500;
  local_20 = 499;
  puVar5 = auStack44;
  while (puVar5 != auStack44) {
    *(puVar5 + -4) = *(undefined4 *)(puVar5 + -4);
    puVar5 = puVar5 + -0x1000;
  }
  *(puVar5 + -4) = *(undefined4 *)(puVar5 + -4);
  local_1c = puVar5 + -0x200;
  *(puVar5 + -0x210) = "Run SCAAS (alphanumeric shellcode, max 500 bytes): ";
  *(puVar5 + -0x214) = 0x11779;
  printf(*(puVar5 + -0x210));
  uVar1 = local_24;
  *(puVar5 + -0x208) = stdin;
  *(puVar5 + -0x20c) = uVar1;
  *(puVar5 + -0x210) = local_1c;
  *(puVar5 + -0x214) = 0x11794;
  fgets(*(puVar5 + -0x210),*(puVar5 + -0x20c),*(puVar5 + -0x208));
  *(puVar5 + -0x20c) = &DAT_000120cc;
  *(puVar5 + -0x210) = local_1c;
  *(puVar5 + -0x214) = 0x117a9;
  sVar4 = strcspn(*(puVar5 + -0x210),*(puVar5 + -0x20c));
  local_1c[sVar4] = 0;
  *(puVar5 + -0x210) = local_1c;
  *(puVar5 + -0x214) = 0x117be;
  cVar3 = is_alphanumeric();
  if (cVar3 == '\x01') {
    *(puVar5 + -0x20c) = 0;
    *(puVar5 + -0x210) = 0xffffffff;
    *(puVar5 + -0x214) = 0x22;
    *(puVar5 + -0x218) = 7;
    *(puVar5 + -0x21c) = local_24;
    *(puVar5 + -0x220) = 0;
    *(puVar5 + -0x224) = 0x117f1;
    local_18 = mmap(*(puVar5 + -0x220),*(puVar5 + -0x21c),
                            *(puVar5 + -0x218),*(puVar5 + -0x214),
                            *(puVar5 + -0x210),*(puVar5 + -0x20c));
    if (local_18 == 0xffffffff) {
      *(puVar5 + -0x210) = &DAT_000120f6;
      *(puVar5 + -0x214) = 0x1180c;
      perror(*(puVar5 + -0x210));
    }
    else {
      *(puVar5 + -0x210) = local_1c;
      *(puVar5 + -0x214) = 0x1181c;
      sVar4 = strlen(*(puVar5 + -0x210));
      *(puVar5 + -0x208) = sVar4;
      *(puVar5 + -0x20c) = local_1c;
      *(puVar5 + -0x210) = local_18;
      *(puVar5 + -0x214) = 0x1182e;
      memcpy(*(puVar5 + -0x210),*(void **)(puVar5 + -0x20c),*(size_t *)(puVar5 + -0x208));
      pcVar2 = local_18;
      local_14 = local_18;
      *(puVar5 + -0x204) = 0x1183c;
      (*pcVar2)();
    }
  }
  else {
    *(puVar5 + -0x210) = "Error: shellcode must be alphanumeric";
    *(puVar5 + -0x214) = 0x117d7;
    puts(*(puVar5 + -0x210));
  }
  if (local_10 != *(in_GS_OFFSET + 0x14)) {
    __stack_chk_fail_local();
  }
  return;
}



undefined4 is_alphanumeric(byte *param_1) {
  ushort **ppuVar1;
  byte *local_10;

  local_10 = param_1;
  while( true ) {
    if (*local_10 == 0) {
      return 1;
    }
    ppuVar1 = __ctype_b_loc();
    if (((*ppuVar1)[*local_10] & 8) == 0) break;
    local_10 = local_10 + 1;
  }
  return 0;
}


