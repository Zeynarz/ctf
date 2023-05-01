undefined4 main(void) {
  char cVar1;
  int adventurerObj;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 *randPokemonObj;
  
  adventurerObj = malloc(0x1ac);
  pcVar3 = malloc(1);
  readInput(pcVar3,"enter your name: ",0x14);
  uVar4 = strlen(pcVar3);
  memcpy(adventurerObj,pcVar3,uVar4);
  printf("hello adventurer %s\n{\n abilities = %d\n balls_used = %d\n pokemon_allowed = %d\n}\n",
         adventurerObj,*(char *)(adventurerObj + 0x10),*(adventurerObj + 0x14),100);
  setupPokemon();
  while (*(adventurerObj + 0x14) < 100) {
    printf("searching for pokemon...",pcVar3);
    randPokemonObj = getRandomPokemon();
    if ((randPokemonObj != (undefined4 *)0x0) && (randPokemonObj != (undefined4 *)0x11)) {
      printf(" found %s!\n\n",*randPokemonObj);
      cVar1 = inputByte("ynf","would you like to catch? y/n:"); // get char until its either y,n or f
      if (cVar1 == 'y') {
        catchPokemon(adventurerObj,randPokemonObj);
        pcVar3 = (char *)randPokemonObj;
      }
      else {
        if (cVar1 == 'f') break;
      }
      puts(&DAT_00014944);
    }
  }
  if (adventurerObj != 0) {
    evolve(adventurerObj);
    free(adventurerObj);
  }
  FUN_00013a3a();
  return 0;
}

undefined4 getRandomPokemon(void){
  int iVar1;

  iVar1 = rand();
  return *(pokemonListGlo + (iVar1 % 0xff + 1) * 4);

  // if iVar1 % 0xff  = 0xfe,
  // *(pokemonListGlo + (0xff*4)) is not set
}

void catchPokemon(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;

  if (param_1 == 0) {
    return;
  }
  if (param_2 != (undefined4 *)0x0) {
    iVar2 = param_2[2];
    iVar1 = rand();
    if ((iVar2 < iVar1 % 100 + 1) && (iVar2 = andByte6(param_1), iVar2 == 0)) {
      printf("%s ran away. :(\n",*param_2);
    }
    else {
      *(param_1 + 0xc + (*(param_1 + 0x18) + 4) * 4) = param_2;
      *(param_1 + 0x18) = *(param_1 + 0x18) + '\x01';
      printf("%s caught %s!\n",param_1,*param_2);
    }
    *(param_1 + 0x14) = *(param_1 + 0x14) + 1;
    printf("balls left: %d\n\n",100 - *(param_1 + 0x14));
    return;
  }
  return;
}

byte andByte6(int param_1){
  return *(byte *)(param_1 + 0x10) & 6;
}


void evolve(int param_1){
  int iVar1;
  undefined4 local_10 [2];

  iVar1 = andByte7(param_1);
  if (iVar1 != 0) {
    printf("evolving %s\'s pokemon!\n",param_1);
    local_10[0] = FUN_000113bd(param_1 + 0x1c); // starting addr of caughtPokemonObjs
    execOwnCode(local_10,*(char *)(param_1 + 0x10));
  }
  // local_10:  heapPtr     null
  return;
}

byte andByte7(int param_1){
  return *(byte *)(param_1 + 0x10) & 7;
}


int FUN_000113bd(int param_1){
  int iVar1;
  int local_10;

  iVar1 = calloc(100,1);
  local_10 = 0;
  while ((local_10 < 100 && (*(int *)(param_1 + local_10 * 4) != 0))) {
    *(iVar1 + local_10) = *(*(param_1 + local_10 * 4) + 4); // pokemonId
    local_10 = local_10 + 1;
    // if 3 pokemon, the ids are put like  0x00ac7fc4
  }
  return iVar1;
}

void execOwnCode(code **param_1,undefined4 param_2){
  int iVar1;
  uint uVar2;
  undefined4 uVar3;

  uVar3 = 0x115c3;
  iVar1 = sysconf(0x1e); 
  // not sure it asks for what system configuration, maybe pg size?
  // but $eax   : 0x1000 
  uVar2 = -iVar1 & *param_1; // turns like 0x565565aa -> 0x56556000
  iVar1 = mprotect(uVar2,*param_1 + (4 - uVar2),param_2); 
  // permission = abilities
  // only 4 bytes starting from *param_1 are rwx

  if (iVar1 == 0) {
    (**param_1)();
    // use the pokemonId to write shellcode
  }
  else {
    perror("mprotect");
  }
  return;
}

