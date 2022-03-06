uint setup_seccomp(void){
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  undefined8 uVar22;
  
  uVar22 = seccomp_init(0);
  uVar1 = seccomp_rule_add(uVar22,0x7fff0000,3,0); // close
  uVar2 = seccomp_rule_add(uVar22,0x7fff0000,4,0); // stat
  uVar3 = seccomp_rule_add(uVar22,0x7fff0000,5,0); // fstat
  uVar4 = seccomp_rule_add(uVar22,0x7fff0000,6,0); // lstat
  uVar5 = seccomp_rule_add(uVar22,0x7fff0000,0x65,0); // ptrace
  uVar6 = seccomp_rule_add(uVar22,0x7fff0000,10,0); // mprotect
  uVar7 = seccomp_rule_add(uVar22,0x7fff0000,0xc,0); // brk
  uVar8 = seccomp_rule_add(uVar22,0x7fff0000,0x15,0); // access
  uVar9 = seccomp_rule_add(uVar22,0x7fff0000,0x18,0); // sched_yield
  uVar10 = seccomp_rule_add(uVar22,0x7fff0000,0x20,0); // dup
  uVar11 = seccomp_rule_add(uVar22,0x7fff0000,0x21,0); // dup2
  uVar12 = seccomp_rule_add(uVar22,0x7fff0000,0x38,0); // clone
  uVar13 = seccomp_rule_add(uVar22,0x7fff0000,0x3c,0); // exit
  uVar14 = seccomp_rule_add(uVar22,0x7fff0000,0x3e,0); // kill
  uVar15 = seccomp_rule_add(uVar22,0x7fff0000,0x50,0); // chdir
  uVar16 = seccomp_rule_add(uVar22,0x7fff0000,0x51,0); // fchdir
  uVar17 = seccomp_rule_add(uVar22,0x7fff0000,0x60,0); // gettimeofday
  uVar18 = seccomp_rule_add(uVar22,0x7fff0000,0x66,0); // getuide
  uVar19 = seccomp_rule_add(uVar22,0x7fff0000,0x68,0); // getgid
  uVar20 = seccomp_rule_add(uVar22,0x7fff0000,0xe7,0); // exit_group
  uVar21 = seccomp_load(uVar22);
  return uVar1 | uVar2 | uVar3 | uVar4 | uVar5 | uVar6 | uVar7 | uVar8 | uVar9 | uVar10 | uVar11 |
         uVar12 | uVar13 | uVar14 | uVar15 | uVar16 | uVar17 | uVar18 | uVar19 | uVar20 | uVar21;
}
