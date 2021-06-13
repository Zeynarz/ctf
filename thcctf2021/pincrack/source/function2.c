void FUN_001012bb(void *param_1,uchar *param_2)
{
  SHA_CTX local_68;
  
  SHA1_Init(&local_68);
  SHA1_Update(&local_68,param_1,6);
  SHA1_Final(param_2,&local_68);
  return;
}
