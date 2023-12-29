int vm(int *param_1){
  long instrs;
  ulong p2;
  void *p3;
  ulong p4;
  int iVar3;
  void *pvVar4;
  long in_FS_OFFSET;
  int i;
  void *j;
  void *regs [0x15];
  long local_10;

  instrs = *(mcode + *param_1 * 8);
  i = 0;

  while (iVar3 = *(mcode_size + *param_1 * 4), i < iVar3) {
    // while there are still instructions
   
    p2 = *(instrs + i + 1);
    p3 = *(instrs + i + 9);
    p4 = *(instrs + i + 0x11);
    if (*(instrs + i) < 0x16) {
      switch(*(instrs + i)) {
      case 0:
        iVar3 = 0;
        goto LAB_001026d0;

      case 1:
        // mov
        regs[p2] = p3;
        *(regs + (p2 + 0x10) * 4) = 0; // TODO what is this bruh
        break;
      case 2:
        // sub
        regs[p2] = (regs[p2] - p3);
        break;
      case 3:
        // add
        regs[p2] = (void *)((long)p3 + (long)regs[p2]);
        break;
      case 4:
        // mul
        regs[p2] = (void *)((long)p3 * (long)regs[p2]);
        break;
      case 5:
        // sqr
        pvVar4 = regs[p2];
        regs[p2] = p3;
        j = 0;
        while (j < pvVar4) {
          regs[p2] = (regs[p2] * regs[p2]);
          j++;
        }
        break;
      case 6:
        // shl
        regs[p2] = (regs[p2] << (p3 & 0x3f));
        break;
      case 7:
        // shr
        regs[p2] = (void *)((ulong)regs[p2] >> ((byte)p3 & 0x3f));
        break;
      case 8:
        // and
        regs[p2] = (void *)((ulong)p3 & (ulong)regs[p2]);
        break;
      case 9:
        // or
        regs[p2] = (void *)((ulong)p3 | (ulong)regs[p2]);
        break;
      case 10:
        // not?
        regs[p2] = (void *)~(ulong)regs[p2];
        break;
      case 0xb:
        // alloc
        if (p3 < (void *)0x8) {
          write(1,"Error: Runtime Error\n",0x15);
          err();
        }
        heapptr = calloc(1,p3);
        regs[p2] = heapptr;
        *(regs + (p2 + 0x10) * 4) = 1; // this means that its a ptr?
        regs[p2 + 0xc] = p3; // TODO what is this bruh, set the size prob

        if (regs[p2] == 0x0) {
          write(1,"Error: Runtime Error\n",0x15);
          err();
        }
        break;
      case 0xc:
        // write into ptr
        // so p3 is what u want to write, and p4 is index
        if ((*(regs + (p2 + 0x10) * 4) == 1) && ((p4 & 0xffffffff) < regs[p2 + 0xc] - 8U)) {
          // checks if its a ptr, and if the index is within range
          *(regs[p2] + (p4 & 0xffffffff)) = regs[p3];
        } else {
          write(1,"Error: Runtime Error\n",0x15);
          err();
        }
        break;
      case 0xd:
        // read from ptr
        if ((*(int *)((long)regs + (p2 + 0x10) * 4) == 1) &&
           ((p4 & 0xffffffff) < (long)regs[p2 + 0xc] - 8U)) {
          regs[p3] = *(void **)((long)regs[p2] + (p4 & 0xffffffff));
        } else {
          write(1,"Error: Runtime Error\n",0x15);
          err();
        }
        break;
      case 0xe:
        // copy
        if (((*(int *)((long)regs + (p2 + 0x10) * 4) == 1) &&
            (*(int *)((long)regs + ((long)p3 + 0x10U) * 4) == 1)) &&
           (((void *)(p4 & 0xffff) < regs[p2 + 0xc] &&
            ((void *)(p4 & 0xffff) < regs[(long)p3 + 0xc])))) {
          memcpy(regs[p2],regs[(long)p3],p4 & 0xffff);
          *(undefined *)(p4 + (long)regs[p2]) = 0;
        }
        else {
          write(1,"Error: Runtime Error\n",0x15);
          err();
        }
        break;
      case 0xf:
        // print
        // opcode , reg , index , len
        if (((*(regs + (p2 + 0x10) * 4) == 1) && ((p3 + p4) < regs[p2 + 0xc])) && (p3 < (p3 + p4))) {
          // check if its a ptr, and if its within size
          write(1,(p3 + regs[p2]),p4);
        }
        else {
          write(1,"Error: Runtime Error\n",0x15);
          err();
        }
        break;
      case 0x10:
        // pause
        getchar();
        break;
      case 0x11:
        // lock
        *(undefined4 *)(mcode_mutex + (long)*param_1 * 4) = 1;
        do {
        } while (*(int *)(mcode_mutex + (long)*param_1 * 4) != 0);
        break;
      case 0x12:
        // unlock
        if (p2 < 5) {
          *(undefined4 *)(mcode_mutex + p2 * 4) = 0;
        }
        else {
          write(1,"Error: Runtime Error\n",0x15);
          err();
        }
        break;
      case 0x13:
        // mov2
        regs[p2] = regs[(long)p3];
        *(undefined4 *)((long)regs + (p2 + 0x10) * 4) =
             *(undefined4 *)((long)regs + ((long)p3 + 0x10U) * 4);
        break;
      case 0x14:
        // and2
        regs[p2] = (void *)((ulong)regs[(long)p3] & (ulong)regs[p2]);
        break;
      case 0x15:
        // or2
        regs[p2] = (void *)((ulong)regs[(long)p3] | (ulong)regs[p2]);
      }
    }
    i += 0x19;
  }
  return iVar3;
}


void vmRun(void){
  long in_FS_OFFSET;
  int i;
  int i;
  int mcodeId [8];
  pthread_t threads [5];
  long local_10;
  
  i = 0;

  while (i <= mcode_count) {
    // Im pretty sure mcodeId is used to tell the vm function which mcode/thread to run
    mcodeId[i] = i;
    pthread_create(threads + i,0x0,vm,mcodeId + i);
    i = i + 1;
  }

  i = 0;
  while (i <= mcode_count) {
    pthread_join(threads[i],(void **)0x0);
    i = i + 1;
  }
  return;
}
