int FUN_001013ee(uchar *param_1,int param_2,uchar *param_3,uchar *param_4,uchar *param_5)

{
  int iVar1;
  EVP_CIPHER *cipher;
  int local_18;
  int local_14;
  EVP_CIPHER_CTX *local_10;
  
  local_10 = EVP_CIPHER_CTX_new();
  if (local_10 == (EVP_CIPHER_CTX *)0x0) {
    abort();
  }
  cipher = EVP_aes_256_cbc();
  iVar1 = EVP_DecryptInit_ex(local_10,cipher,(ENGINE *)0x0,param_3,param_4);
  if (iVar1 != 1) {
    abort();
  }
  iVar1 = EVP_DecryptUpdate(local_10,param_5,&local_18,param_1,param_2);
  if (iVar1 != 1) {
    abort();
  }
  local_14 = local_18;
  iVar1 = EVP_DecryptFinal_ex(local_10,param_5 + local_18,&local_18);
  if (iVar1 != 1) {
    abort();
  }
  local_14 = local_14 + local_18;
  EVP_CIPHER_CTX_free(local_10);
  return local_14;
}
