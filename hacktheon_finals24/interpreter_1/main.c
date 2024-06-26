__int64 __fastcall final_check(_QWORD *a1, _QWORD *a2)
{
  int v3; // [rsp+4h] [rbp-3Ch]
  __int64 v4; // [rsp+10h] [rbp-30h]
  unsigned __int64 i; // [rsp+18h] [rbp-28h]
  char v6; // [rsp+37h] [rbp-9h]

  v4 = op_shift_right(a1);
  if ( v4 == op_shift_right(a2) ) // check for expression
  {
    for ( i = 0LL; i < 0x14; ++i )
    {
      if ( *sub_4048B0(a1, i) != *sub_4048B0(a2, i) )
      {
        v6 = 0;
        return v6 & 1;
      }
    }
    v6 = 1;
  }
  else
  {
    v6 = 0;
  }
  return v6 & 1;
}

__int64 __fastcall op_shift_right(_QWORD *a1)
{
  return (__int64)(a1[1] - *a1) >> 1;
}


__int64 __fastcall sub_4048B0(_QWORD *a1, __int64 a2)
{
  return *a1 + 2 * a2;
}

