void generate_mcode(undefined8 p1,undefined8 p2,undefined8 p3,undefined8 p4){
  undefined uVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long in_FS_OFFSET;
  undefined local_38;
  undefined7 uStack55;
  undefined local_30;
  undefined7 uStack47;
  undefined local_28;
  undefined7 uStack39;
  undefined local_20;
  long local_10;
  local_10 = *(long *)(in_FS_OFFSET + 0x28);

  local_38 = 0;
  uStack55 = 0;
  local_30 = 0;
  uStack47 = 0;
  local_28 = 0;
  uStack39 = 0;
  local_20 = 0;
  uVar2 = getOpcType(p1);
  if (uVar2 < 0x16) {
    uVar1 = uVar2;
    switch(uVar2) {
    case 0:
      write(1,"Error: Unknown opc\n",0x13);
      err();
    default:
      // mov -> or
      uVar4 = parseRegister(p2);
      uVar5 = parseHex(p3);
      uStack55 = uVar4;
      local_30 = ((ulong)uVar4 >> 0x38);
      uStack47 = uVar5;
      local_28 = ((ulong)uVar5 >> 0x38);
      local_38 = uVar1;
      // so it becomes
      // stack+0x00: opcode
      // stack+0x08: p3 >> 0x38
      // stack+0x10: register >> 0x38
      break;
    case 10:
      uVar4 = parseRegister(p2);
      uStack55 = (undefined7)uVar4;
      local_30 = (undefined)((ulong)uVar4 >> 0x38);
      local_38 = uVar1;
      break;
    case 12:
    case 13:
    case 14:
      uVar4 = parseRegister(p2);
      uVar5 = parseRegister(p3);
      uVar3 = parseHex(p4);
      uStack55 = (undefined7)uVar4;
      local_30 = (undefined)((ulong)uVar4 >> 0x38);
      uStack47 = (undefined7)uVar5;
      local_28 = (undefined)((ulong)uVar5 >> 0x38);
      uStack39 = (undefined7)uVar3;
      local_20 = (undefined)((ulong)uVar3 >> 0x38);
      local_38 = uVar1;
      break;
    case 15:
      uVar4 = parseRegister(p2);
      uVar5 = parseHex(p3);
      uVar3 = parseHex(p4);
      uStack55 = (undefined7)uVar4;
      local_30 = (undefined)((ulong)uVar4 >> 0x38);
      uStack47 = (undefined7)uVar5;
      local_28 = (undefined)((ulong)uVar5 >> 0x38);
      uStack39 = (undefined7)uVar3;
      local_20 = (undefined)((ulong)uVar3 >> 0x38);
      local_38 = uVar1;
      break;
    case 16:
    case 17:
      local_38 = uVar1;
      break;
    case 18:
      uVar4 = parseHex(p2);
      uStack55 = (undefined7)uVar4;
      local_30 = (undefined)((ulong)uVar4 >> 0x38);
      local_38 = uVar1;
      break;
    case 19:
    case 20:
    case 21:
      uVar4 = parseRegister(p2);
      uVar5 = parseRegister(p3);
      uStack55 = (undefined7)uVar4;
      local_30 = (undefined)((ulong)uVar4 >> 0x38);
      uStack47 = (undefined7)uVar5;
      local_28 = (undefined)((ulong)uVar5 >> 0x38);
      local_38 = uVar1;
    }
  }
  push_mcode(&local_38);
  return;
}

undefined8 getOpcType(char *param_1){
  int iVar1;
  undefined8 uVar2;

essentially:
mov: 1
sub: 2
add: 3
mul: 4
sqr: 5
shl: 6
shr: 7
and: 8 // this comes first
or: 9
and: 10 // ???
alloc: 11
write: 12
read: 13
copy: 14
print: 15
pause: 16
lock: 17
unlock: 18
mov2: 19
and2: 20
or2: 21
everything_else: 0
}


long parseRegister(char *param_1){
  // returns register number
  size_t sVar1;

  if (*param_1 == 'r') {
    sVar1 = strlen(param_1);
    if (sVar1 == 2) goto LAB_0010168a;
  }
  write(1,"Error: parseRegister Error\n",0x1b);
  err();
LAB_0010168a:
  if ((param_1[1] < '0') || ('8' < param_1[1])) {
    write(1,"Error: parseRegister Error\n",0x1b);
    err();
  }
  return (long)(param_1[1] + -0x30);
}


ulonglong parseHex(char *param_1){
  // just returns hex number and checks for errors
  int *piVar1;
  long in_FS_OFFSET;
  char *local_20;
  ulonglong local_18;
  long local_10;

  if (param_1 == (char *)0x0) {
    write(1,"Error: parseHex Error\n",0x16);
    err();
  }
  piVar1 = __errno_location(); // prob is set piVar1 to ptr to errno
  *piVar1 = 0;
  local_18 = strtoull(param_1,&local_20,0x10);
  piVar1 = __errno_location();
  if ((*piVar1 == 0x22) && (local_18 == 0xffffffffffffffff)) {
    write(1,"Error: parseHex Error\n",0x16);
    err();
  }
  piVar1 = __errno_location();
  if ((*piVar1 != 0) && (local_18 == 0)) {
    write(1,"Error: parseHex Error\n",0x16);
    err();
  }
  if (param_1 == local_20) {
    write(1,"Error: parseHex Error\n",0x16);
    err();
  }
  if (*local_20 != '\0') {
    write(1,"Error: parseHex Error\n",0x16);
    err();
  }
  return local_18;
}


void push_mcode(void *param_1){
  if (0xfff0 < *(mcode_size + mcode_count * 4)) {
    write(1,"Error: push_mcode Error\n",0x18);
    err();
  }

  // cpy the mcode into corresponding thread
  memcpy((*(mcode + mcode_count * 8) + *(mcode_size + mcode_count * 4)),param_1,0x19);
  *(mcode_size + mcode_count * 4) = *(mcode_size + mcode_count * 4) + 0x19;
  return;
}
