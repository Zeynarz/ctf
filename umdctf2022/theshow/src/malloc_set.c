void * malloc_set(size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  __memset_avx2_unaligned(pvVar1,0,param_1);
  return pvVar1;
}
