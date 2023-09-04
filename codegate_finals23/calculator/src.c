long evaluateExpression(void)

{
  int iVar1;
  int iVar2;
  ushort **ppuVar3;
  size_t sVar4;
  long lVar5;
  ulong uVar6;
  long local_988 [256];
  char local_188 [264];
  long local_80;
  long local_78;
  long local_70;
  char local_61;
  long local_60;
  long local_58;
  long local_50;
  char local_42;
  char local_41;
  long local_40;
  long local_38;
  long local_30;
  char local_21;
  long local_20;
  
  memset(local_188,0,0x100);
  memset(local_988,0,0x800);
  operatorTop = -1;
  operandTop = -1;
  i = 0;
  do {
    uVar6 = SEXT48(i); // uVar6 = i prob
    sVar4 = strlen(expression);
    if (sVar4 <= uVar6) {
      while (-1 < operatorTop) {
        lVar5 = (long)operatorTop;
        local_21 = local_188[lVar5];
        iVar1 = operandTop + -1;
        local_30 = local_988[operandTop];
        operandTop = operandTop + -2;
        local_38 = local_988[iVar1];
        operatorTop = operatorTop + -1;
        local_40 = calculate(local_38,local_30,(int)local_188[lVar5],local_30);
        operandTop = operandTop + 1;
        local_988[operandTop] = local_40;
      }
      return local_988[operandTop];
    }
    local_41 = expression[i]; // get char
    ppuVar3 = __ctype_b_loc();
    if (((*ppuVar3)[local_41] & 0x800) == 0) {
      if (local_41 == '(') {
        operatorTop = operatorTop + 1;
        local_188[operatorTop] = '(';
      }
      else {
        if (local_41 == ')') {
          while ((-1 < operatorTop && (local_188[operatorTop] != '('))) {
            lVar5 = (long)operatorTop;
            local_61 = local_188[lVar5];
            iVar1 = operandTop + -1;
            local_70 = local_988[operandTop];
            operandTop = operandTop + -2;
            local_78 = local_988[iVar1];
            operatorTop = operatorTop + -1;
            local_80 = calculate(local_78,local_70,(int)local_188[lVar5],local_70);
            operandTop = operandTop + 1;
            local_988[operandTop] = local_80;
          }
          if ((-1 < operatorTop) && (local_188[operatorTop] == '(')) {
            operatorTop = operatorTop + -1;
          }
        }
        else {
          if ((((local_41 == '+') || (local_41 == '-')) || (local_41 == '*')) ||
             ((local_41 == '/' || (local_41 == '^')))) {
            while (-1 < operatorTop) {
              iVar1 = getPriority((int)local_188[operatorTop]);
              iVar2 = getPriority((int)local_41);
              if (iVar1 < iVar2) break;
              lVar5 = (long)operatorTop;
              local_42 = local_188[lVar5];
              iVar1 = operandTop + -1;
              local_50 = local_988[operandTop];
              operandTop = operandTop + -2;
              local_58 = local_988[iVar1];
              operatorTop = operatorTop + -1;
              local_60 = calculate(local_58,local_50,(int)local_188[lVar5],local_50);
              operandTop = operandTop + 1;
              local_988[operandTop] = local_60;
            }
            operatorTop = operatorTop + 1;
            local_188[operatorTop] = local_41;
          }
        }
      }
    }
    else {
      local_20 = 0;
      while ((uVar6 = SEXT48(i), sVar4 = strlen(expression), uVar6 < sVar4 &&
             (ppuVar3 = __ctype_b_loc(), ((*ppuVar3)[(char)expression[i]] & 0x800) != 0))) {
        local_20 = (long)((char)expression[i] + -0x30) + local_20 * 10;
        i = i + 1;
      }
      operandTop = operandTop + 1;
      local_988[operandTop] = local_20;
      i = i + -1;
    }
    i = i + 1;
  } while( true );
}
