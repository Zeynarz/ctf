void main(void)

{
  long lVar1;
  long in_FS_OFFSET;
  undefined8 local_33;
  char local_2a [10];
  undefined8 local_20;
  
  local_20 = *(undefined8 *)(in_FS_OFFSET + 0x28);
  fill_reviews();
  puts("--------------------------------------------------------------------------------\n");
  logo();
  puts("--------------------------------------------------------------------------------\n");
  puts("\"Who\'s more foolish, the fool or the fool who follows him? Remember, a Jedi\'s ");
  puts("strength flows from the Force. But beware. Anger, fear, aggression. The dark ");
  puts("side are they. Once you start down the dark path, forever will it dominate your ");
  puts("destiny.\"");
  puts("--------------------------------------------------------------------------------\n");
  puts("Please enter your favorite jedi quote: ");
  printf(">>> ");
  fflush(stdout);
  fgets(review,1000,stdin);
  puts("Which quote number do you want to be? ");
  printf(">>> ");
  fflush(stdout);
  fgets(local_2a,10,stdin);
  lVar1 = strtol(local_2a,0x0,10);
  if ((int)lVar1 < 5) {
    puts("Which jedi said that? ");
    printf(">>> ");
    fflush(stdout);
    fgets(&local_33,9,stdin);
    **(review_names + lVar1 * 8) = local_33;
  }
  exit(0);
}

void fill_reviews(void){
  undefined8 *puVar1;

  review_names._0_8_ = malloc(0x10);
  *review_names._0_8_ = 0x61646f59; // Yoda
  *(undefined *)(review_names._0_8_ + 1) = 0;
  review_names._8_8_ = (undefined4 *)malloc(0x10);
  *review_names._8_8_ = 0x656b754c; // Luke
  *(undefined *)(review_names._8_8_ + 1) = 0;
  review_names._16_8_ = (undefined8 *)malloc(0x10);
  *review_names._16_8_ = 0x206e6f472d697551; // Qui-Gon Jinn
  *(review_names._16_8_ + 5) = 0x6e6e694a206e6f;
  review_names._24_8_ = (undefined8 *)malloc(0x10);
  *review_names._24_8_ = 0x206e61572d69624f; // Obi-Wan Kenobi
  *(undefined8 *)((long)review_names._24_8_ + 7) = 0x69626f6e654b20;
  puVar1 = (undefined8 *)malloc(0x10); 
  review_names._32_8_ = puVar1; 
  *puVar1 = 0x6156206874726144; // Darth Vader
  *(undefined4 *)(puVar1 + 1) = 0x726564;
  return;
}


// found a win function
void win(long param_1,long param_2){
  FILE *pFVar1;
  long in_FS_OFFSET;
  char acStack296 [264];
  long local_20;

  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  pFVar1 = fopen("flag.txt","r");
  if ((param_1 == 0x6461726b) && (param_2 == 0x73696465)) {
    fgets(acStack296,0xff,(FILE *)(long)(int)pFVar1);
    puts("--------------------------------------------------------------------------------\n");
    puts("\"...Power is an illusion of perception. It is what we believe is possible, or ");
    puts("what we hope might occur. It is a tool, like a lightsaber, but merely having it ");
    puts("does not make one great. Power is something to be wielded and harnessed, a means");
    puts("to an end. And that end is the only thing that matters. For those with the vision");
    puts("to see, there is only the Force, and what is required to bend it to one\'s will.\"");
    puts("--------------------------------------------------------------------------------\n");
    puts(acStack296);
    if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
  else {
    puts("\t \"No one\'s ever really gone. I have a feeling that this ");
    if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
      puts("\t is the beginning of something truly special\"");
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}
