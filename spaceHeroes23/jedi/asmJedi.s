
jedi.bin:     file format elf64-x86-64


Disassembly of section .init:

0000000000401000 <_init>:
  401000:	48 83 ec 08          	sub    rsp,0x8
  401004:	48 8b 05 e5 35 00 00 	mov    rax,QWORD PTR [rip+0x35e5]        # 4045f0 <__gmon_start__@Base>
  40100b:	48 85 c0             	test   rax,rax
  40100e:	74 02                	je     401012 <_init+0x12>
  401010:	ff d0                	call   rax
  401012:	48 83 c4 08          	add    rsp,0x8
  401016:	c3                   	ret    

Disassembly of section .plt:

0000000000401020 <puts@plt-0x10>:
  401020:	ff 35 da 35 00 00    	push   QWORD PTR [rip+0x35da]        # 404600 <_GLOBAL_OFFSET_TABLE_+0x8>
  401026:	ff 25 dc 35 00 00    	jmp    QWORD PTR [rip+0x35dc]        # 404608 <_GLOBAL_OFFSET_TABLE_+0x10>
  40102c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

0000000000401030 <puts@plt>:
  401030:	ff 25 da 35 00 00    	jmp    QWORD PTR [rip+0x35da]        # 404610 <puts@GLIBC_2.2.5>
  401036:	68 00 00 00 00       	push   0x0
  40103b:	e9 e0 ff ff ff       	jmp    401020 <_init+0x20>

0000000000401040 <__stack_chk_fail@plt>:
  401040:	ff 25 d2 35 00 00    	jmp    QWORD PTR [rip+0x35d2]        # 404618 <__stack_chk_fail@GLIBC_2.4>
  401046:	68 01 00 00 00       	push   0x1
  40104b:	e9 d0 ff ff ff       	jmp    401020 <_init+0x20>

0000000000401050 <printf@plt>:
  401050:	ff 25 ca 35 00 00    	jmp    QWORD PTR [rip+0x35ca]        # 404620 <printf@GLIBC_2.2.5>
  401056:	68 02 00 00 00       	push   0x2
  40105b:	e9 c0 ff ff ff       	jmp    401020 <_init+0x20>

0000000000401060 <fgets@plt>:
  401060:	ff 25 c2 35 00 00    	jmp    QWORD PTR [rip+0x35c2]        # 404628 <fgets@GLIBC_2.2.5>
  401066:	68 03 00 00 00       	push   0x3
  40106b:	e9 b0 ff ff ff       	jmp    401020 <_init+0x20>

0000000000401070 <strtol@plt>:
  401070:	ff 25 ba 35 00 00    	jmp    QWORD PTR [rip+0x35ba]        # 404630 <strtol@GLIBC_2.2.5>
  401076:	68 04 00 00 00       	push   0x4
  40107b:	e9 a0 ff ff ff       	jmp    401020 <_init+0x20>

0000000000401080 <malloc@plt>:
  401080:	ff 25 b2 35 00 00    	jmp    QWORD PTR [rip+0x35b2]        # 404638 <malloc@GLIBC_2.2.5>
  401086:	68 05 00 00 00       	push   0x5
  40108b:	e9 90 ff ff ff       	jmp    401020 <_init+0x20>

0000000000401090 <fflush@plt>:
  401090:	ff 25 aa 35 00 00    	jmp    QWORD PTR [rip+0x35aa]        # 404640 <fflush@GLIBC_2.2.5>
  401096:	68 06 00 00 00       	push   0x6
  40109b:	e9 80 ff ff ff       	jmp    401020 <_init+0x20>

00000000004010a0 <fopen@plt>:
  4010a0:	ff 25 a2 35 00 00    	jmp    QWORD PTR [rip+0x35a2]        # 404648 <fopen@GLIBC_2.2.5>
  4010a6:	68 07 00 00 00       	push   0x7
  4010ab:	e9 70 ff ff ff       	jmp    401020 <_init+0x20>

00000000004010b0 <exit@plt>:
  4010b0:	ff 25 9a 35 00 00    	jmp    QWORD PTR [rip+0x359a]        # 404650 <exit@GLIBC_2.2.5>
  4010b6:	68 08 00 00 00       	push   0x8
  4010bb:	e9 60 ff ff ff       	jmp    401020 <_init+0x20>

Disassembly of section .text:

00000000004010c0 <main>:
  4010c0:	55                   	push   rbp
  4010c1:	48 8d 2d 0c 21 00 00 	lea    rbp,[rip+0x210c]        # 4031d4 <_IO_stdin_used+0x11d4>
  4010c8:	53                   	push   rbx
  4010c9:	48 8d 1d 78 10 00 00 	lea    rbx,[rip+0x1078]        # 402148 <_IO_stdin_used+0x148>
  4010d0:	48 83 ec 28          	sub    rsp,0x28
  4010d4:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
  4010db:	00 00 
  4010dd:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
  4010e2:	31 c0                	xor    eax,eax
  4010e4:	e8 17 04 00 00       	call   401500 <fill_reviews>
  4010e9:	48 89 df             	mov    rdi,rbx
  4010ec:	e8 3f ff ff ff       	call   401030 <puts@plt>
  4010f1:	31 c0                	xor    eax,eax
  4010f3:	e8 c8 04 00 00       	call   4015c0 <logo>
  4010f8:	48 89 df             	mov    rdi,rbx
  4010fb:	e8 30 ff ff ff       	call   401030 <puts@plt>
  401100:	48 8d 3d 71 1f 00 00 	lea    rdi,[rip+0x1f71]        # 403078 <_IO_stdin_used+0x1078>
  401107:	e8 24 ff ff ff       	call   401030 <puts@plt>
  40110c:	48 8d 3d b5 1f 00 00 	lea    rdi,[rip+0x1fb5]        # 4030c8 <_IO_stdin_used+0x10c8>
  401113:	e8 18 ff ff ff       	call   401030 <puts@plt>
  401118:	48 8d 3d f9 1f 00 00 	lea    rdi,[rip+0x1ff9]        # 403118 <_IO_stdin_used+0x1118>
  40111f:	e8 0c ff ff ff       	call   401030 <puts@plt>
  401124:	48 8d 3d 9f 20 00 00 	lea    rdi,[rip+0x209f]        # 4031ca <_IO_stdin_used+0x11ca>
  40112b:	e8 00 ff ff ff       	call   401030 <puts@plt>
  401130:	48 89 df             	mov    rdi,rbx
  401133:	48 8d 5c 24 0e       	lea    rbx,[rsp+0xe]
  401138:	e8 f3 fe ff ff       	call   401030 <puts@plt>
  40113d:	48 8d 3d 2c 20 00 00 	lea    rdi,[rip+0x202c]        # 403170 <_IO_stdin_used+0x1170>
  401144:	e8 e7 fe ff ff       	call   401030 <puts@plt>
  401149:	48 89 ef             	mov    rdi,rbp
  40114c:	31 c0                	xor    eax,eax
  40114e:	e8 fd fe ff ff       	call   401050 <printf@plt>
  401153:	48 8b 3d 26 35 00 00 	mov    rdi,QWORD PTR [rip+0x3526]        # 404680 <stdout@@GLIBC_2.2.5>
  40115a:	e8 31 ff ff ff       	call   401090 <fflush@plt>
  40115f:	48 8b 15 2a 35 00 00 	mov    rdx,QWORD PTR [rip+0x352a]        # 404690 <stdin@@GLIBC_2.2.5>
  401166:	be e8 03 00 00       	mov    esi,0x3e8
  40116b:	48 8d 3d 6e 35 00 00 	lea    rdi,[rip+0x356e]        # 4046e0 <review>
  401172:	e8 e9 fe ff ff       	call   401060 <fgets@plt>
  401177:	48 8d 3d 1a 20 00 00 	lea    rdi,[rip+0x201a]        # 403198 <_IO_stdin_used+0x1198>
  40117e:	e8 ad fe ff ff       	call   401030 <puts@plt>
  401183:	48 89 ef             	mov    rdi,rbp
  401186:	31 c0                	xor    eax,eax
  401188:	e8 c3 fe ff ff       	call   401050 <printf@plt>
  40118d:	48 8b 3d ec 34 00 00 	mov    rdi,QWORD PTR [rip+0x34ec]        # 404680 <stdout@@GLIBC_2.2.5>
  401194:	e8 f7 fe ff ff       	call   401090 <fflush@plt>
  401199:	48 8b 15 f0 34 00 00 	mov    rdx,QWORD PTR [rip+0x34f0]        # 404690 <stdin@@GLIBC_2.2.5>
  4011a0:	be 0a 00 00 00       	mov    esi,0xa
  4011a5:	48 89 df             	mov    rdi,rbx
  4011a8:	e8 b3 fe ff ff       	call   401060 <fgets@plt>
  4011ad:	31 f6                	xor    esi,esi
  4011af:	ba 0a 00 00 00       	mov    edx,0xa
  4011b4:	48 89 df             	mov    rdi,rbx
  4011b7:	e8 b4 fe ff ff       	call   401070 <strtol@plt>
  4011bc:	83 f8 04             	cmp    eax,0x4
  4011bf:	7f 51                	jg     401212 <main+0x152>
  4011c1:	48 8d 3d 11 20 00 00 	lea    rdi,[rip+0x2011]        # 4031d9 <_IO_stdin_used+0x11d9>
  4011c8:	48 89 c3             	mov    rbx,rax
  4011cb:	e8 60 fe ff ff       	call   401030 <puts@plt>
  4011d0:	48 89 ef             	mov    rdi,rbp
  4011d3:	31 c0                	xor    eax,eax
  4011d5:	48 63 db             	movsxd rbx,ebx
  4011d8:	e8 73 fe ff ff       	call   401050 <printf@plt>
  4011dd:	48 8b 3d 9c 34 00 00 	mov    rdi,QWORD PTR [rip+0x349c]        # 404680 <stdout@@GLIBC_2.2.5>
  4011e4:	e8 a7 fe ff ff       	call   401090 <fflush@plt>
  4011e9:	48 8d 7c 24 05       	lea    rdi,[rsp+0x5]
  4011ee:	be 09 00 00 00       	mov    esi,0x9
  4011f3:	48 8b 15 96 34 00 00 	mov    rdx,QWORD PTR [rip+0x3496]        # 404690 <stdin@@GLIBC_2.2.5>
  4011fa:	e8 61 fe ff ff       	call   401060 <fgets@plt>
  4011ff:	48 8d 05 9a 34 00 00 	lea    rax,[rip+0x349a]        # 4046a0 <review_names>
  401206:	48 8b 54 24 05       	mov    rdx,QWORD PTR [rsp+0x5]
  40120b:	48 8b 04 d8          	mov    rax,QWORD PTR [rax+rbx*8]
  40120f:	48 89 10             	mov    QWORD PTR [rax],rdx
  401212:	31 ff                	xor    edi,edi
  401214:	e8 97 fe ff ff       	call   4010b0 <exit@plt>
  401219:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000401220 <_start>:
  401220:	31 ed                	xor    ebp,ebp
  401222:	49 89 d1             	mov    r9,rdx
  401225:	5e                   	pop    rsi
  401226:	48 89 e2             	mov    rdx,rsp
  401229:	48 83 e4 f0          	and    rsp,0xfffffffffffffff0
  40122d:	50                   	push   rax
  40122e:	54                   	push   rsp
  40122f:	45 31 c0             	xor    r8d,r8d
  401232:	31 c9                	xor    ecx,ecx
  401234:	48 c7 c7 c0 10 40 00 	mov    rdi,0x4010c0
  40123b:	ff 15 a7 33 00 00    	call   QWORD PTR [rip+0x33a7]        # 4045e8 <__libc_start_main@GLIBC_2.34>
  401241:	f4                   	hlt    
  401242:	66 2e 0f 1f 84 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0]
  401249:	00 00 00 
  40124c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

0000000000401250 <_dl_relocate_static_pie>:
  401250:	c3                   	ret    
  401251:	66 2e 0f 1f 84 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0]
  401258:	00 00 00 
  40125b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000401260 <deregister_tm_clones>:
  401260:	b8 68 46 40 00       	mov    eax,0x404668
  401265:	48 3d 68 46 40 00    	cmp    rax,0x404668
  40126b:	74 13                	je     401280 <deregister_tm_clones+0x20>
  40126d:	b8 00 00 00 00       	mov    eax,0x0
  401272:	48 85 c0             	test   rax,rax
  401275:	74 09                	je     401280 <deregister_tm_clones+0x20>
  401277:	bf 68 46 40 00       	mov    edi,0x404668
  40127c:	ff e0                	jmp    rax
  40127e:	66 90                	xchg   ax,ax
  401280:	c3                   	ret    
  401281:	66 66 2e 0f 1f 84 00 	data16 nop WORD PTR cs:[rax+rax*1+0x0]
  401288:	00 00 00 00 
  40128c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

0000000000401290 <register_tm_clones>:
  401290:	be 68 46 40 00       	mov    esi,0x404668
  401295:	48 81 ee 68 46 40 00 	sub    rsi,0x404668
  40129c:	48 89 f0             	mov    rax,rsi
  40129f:	48 c1 ee 3f          	shr    rsi,0x3f
  4012a3:	48 c1 f8 03          	sar    rax,0x3
  4012a7:	48 01 c6             	add    rsi,rax
  4012aa:	48 d1 fe             	sar    rsi,1
  4012ad:	74 11                	je     4012c0 <register_tm_clones+0x30>
  4012af:	b8 00 00 00 00       	mov    eax,0x0
  4012b4:	48 85 c0             	test   rax,rax
  4012b7:	74 07                	je     4012c0 <register_tm_clones+0x30>
  4012b9:	bf 68 46 40 00       	mov    edi,0x404668
  4012be:	ff e0                	jmp    rax
  4012c0:	c3                   	ret    
  4012c1:	66 66 2e 0f 1f 84 00 	data16 nop WORD PTR cs:[rax+rax*1+0x0]
  4012c8:	00 00 00 00 
  4012cc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

00000000004012d0 <__do_global_dtors_aux>:
  4012d0:	f3 0f 1e fa          	endbr64 
  4012d4:	80 3d bd 33 00 00 00 	cmp    BYTE PTR [rip+0x33bd],0x0        # 404698 <completed.0>
  4012db:	75 13                	jne    4012f0 <__do_global_dtors_aux+0x20>
  4012dd:	55                   	push   rbp
  4012de:	48 89 e5             	mov    rbp,rsp
  4012e1:	e8 7a ff ff ff       	call   401260 <deregister_tm_clones>
  4012e6:	c6 05 ab 33 00 00 01 	mov    BYTE PTR [rip+0x33ab],0x1        # 404698 <completed.0>
  4012ed:	5d                   	pop    rbp
  4012ee:	c3                   	ret    
  4012ef:	90                   	nop
  4012f0:	c3                   	ret    
  4012f1:	66 66 2e 0f 1f 84 00 	data16 nop WORD PTR cs:[rax+rax*1+0x0]
  4012f8:	00 00 00 00 
  4012fc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

0000000000401300 <frame_dummy>:
  401300:	f3 0f 1e fa          	endbr64 
  401304:	eb 8a                	jmp    401290 <register_tm_clones>
  401306:	66 2e 0f 1f 84 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0]
  40130d:	00 00 00 

0000000000401310 <quote2>:
  401310:	48 83 ec 08          	sub    rsp,0x8
  401314:	48 8d 3d ed 0c 00 00 	lea    rdi,[rip+0xced]        # 402008 <_IO_stdin_used+0x8>
  40131b:	e8 10 fd ff ff       	call   401030 <puts@plt>
  401320:	49 83 c1 08          	add    r9,0x8
  401324:	41 ff 21             	jmp    QWORD PTR [r9]
  401327:	48 83 c4 08          	add    rsp,0x8
  40132b:	c3                   	ret    
  40132c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

0000000000401330 <quote1>:
  401330:	48 83 ec 08          	sub    rsp,0x8
  401334:	48 8d 3d 15 0d 00 00 	lea    rdi,[rip+0xd15]        # 402050 <_IO_stdin_used+0x50>
  40133b:	e8 f0 fc ff ff       	call   401030 <puts@plt>
  401340:	48 89 fe             	mov    rsi,rdi
  401343:	41 ff e0             	jmp    r8
  401346:	48 83 c4 08          	add    rsp,0x8
  40134a:	c3                   	ret    
  40134b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000401350 <quote3>:
  401350:	48 83 ec 08          	sub    rsp,0x8
  401354:	48 8d 3d 1d 0d 00 00 	lea    rdi,[rip+0xd1d]        # 402078 <_IO_stdin_used+0x78>
  40135b:	e8 d0 fc ff ff       	call   401030 <puts@plt>
  401360:	48 d1 e7             	shl    rdi,1
  401363:	41 ff e0             	jmp    r8
  401366:	48 83 c4 08          	add    rsp,0x8
  40136a:	c3                   	ret    
  40136b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000401370 <quote4>:
  401370:	48 83 ec 08          	sub    rsp,0x8
  401374:	48 8d 3d 25 0d 00 00 	lea    rdi,[rip+0xd25]        # 4020a0 <_IO_stdin_used+0xa0>
  40137b:	e8 b0 fc ff ff       	call   401030 <puts@plt>
  401380:	48 31 ff             	xor    rdi,rdi
  401383:	41 ff e0             	jmp    r8
  401386:	48 83 c4 08          	add    rsp,0x8
  40138a:	c3                   	ret    
  40138b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

0000000000401390 <quote5>:
  401390:	48 83 ec 08          	sub    rsp,0x8
  401394:	48 8d 3d 3d 0d 00 00 	lea    rdi,[rip+0xd3d]        # 4020d8 <_IO_stdin_used+0xd8>
  40139b:	e8 90 fc ff ff       	call   401030 <puts@plt>
  4013a0:	49 c7 c0 10 13 40 00 	mov    r8,0x401310
  4013a7:	49 c7 c1 e0 46 40 00 	mov    r9,0x4046e0
  4013ae:	49 83 c0 10          	add    r8,0x10
  4013b2:	41 ff e0             	jmp    r8
  4013b5:	48 83 c4 08          	add    rsp,0x8
  4013b9:	c3                   	ret    
  4013ba:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

00000000004013c0 <quote6>:
  4013c0:	48 83 ec 08          	sub    rsp,0x8
  4013c4:	48 8d 3d 55 0d 00 00 	lea    rdi,[rip+0xd55]        # 402120 <_IO_stdin_used+0x120>
  4013cb:	e8 60 fc ff ff       	call   401030 <puts@plt>
  4013d0:	48 83 c7 01          	add    rdi,0x1
  4013d4:	41 ff e0             	jmp    r8
  4013d7:	48 83 c4 08          	add    rsp,0x8
  4013db:	c3                   	ret    
  4013dc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

00000000004013e0 <win>:
  4013e0:	55                   	push   rbp
  4013e1:	48 89 f5             	mov    rbp,rsi
  4013e4:	48 8d 35 d4 1d 00 00 	lea    rsi,[rip+0x1dd4]        # 4031bf <_IO_stdin_used+0x11bf>
  4013eb:	53                   	push   rbx
  4013ec:	48 89 fb             	mov    rbx,rdi
  4013ef:	48 8d 3d cb 1d 00 00 	lea    rdi,[rip+0x1dcb]        # 4031c1 <_IO_stdin_used+0x11c1>
  4013f6:	48 81 ec 18 01 00 00 	sub    rsp,0x118
  4013fd:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
  401404:	00 00 
  401406:	48 89 84 24 08 01 00 	mov    QWORD PTR [rsp+0x108],rax
  40140d:	00 
  40140e:	31 c0                	xor    eax,eax
  401410:	e8 8b fc ff ff       	call   4010a0 <fopen@plt>
  401415:	48 81 fb 6b 72 61 64 	cmp    rbx,0x6461726b
  40141c:	0f 85 9e 00 00 00    	jne    4014c0 <win+0xe0>
  401422:	48 81 fd 65 64 69 73 	cmp    rbp,0x73696465
  401429:	0f 85 91 00 00 00    	jne    4014c0 <win+0xe0>
  40142f:	48 89 e3             	mov    rbx,rsp
  401432:	48 63 d0             	movsxd rdx,eax
  401435:	be ff 00 00 00       	mov    esi,0xff
  40143a:	48 89 df             	mov    rdi,rbx
  40143d:	48 8d 2d 04 0d 00 00 	lea    rbp,[rip+0xd04]        # 402148 <_IO_stdin_used+0x148>
  401444:	e8 17 fc ff ff       	call   401060 <fgets@plt>
  401449:	48 89 ef             	mov    rdi,rbp
  40144c:	e8 df fb ff ff       	call   401030 <puts@plt>
  401451:	48 8d 3d 48 0d 00 00 	lea    rdi,[rip+0xd48]        # 4021a0 <_IO_stdin_used+0x1a0>
  401458:	e8 d3 fb ff ff       	call   401030 <puts@plt>
  40145d:	48 8d 3d 8c 0d 00 00 	lea    rdi,[rip+0xd8c]        # 4021f0 <_IO_stdin_used+0x1f0>
  401464:	e8 c7 fb ff ff       	call   401030 <puts@plt>
  401469:	48 8d 3d d8 0d 00 00 	lea    rdi,[rip+0xdd8]        # 402248 <_IO_stdin_used+0x248>
  401470:	e8 bb fb ff ff       	call   401030 <puts@plt>
  401475:	48 8d 3d 24 0e 00 00 	lea    rdi,[rip+0xe24]        # 4022a0 <_IO_stdin_used+0x2a0>
  40147c:	e8 af fb ff ff       	call   401030 <puts@plt>
  401481:	48 8d 3d 70 0e 00 00 	lea    rdi,[rip+0xe70]        # 4022f8 <_IO_stdin_used+0x2f8>
  401488:	e8 a3 fb ff ff       	call   401030 <puts@plt>
  40148d:	48 89 ef             	mov    rdi,rbp
  401490:	e8 9b fb ff ff       	call   401030 <puts@plt>
  401495:	48 89 df             	mov    rdi,rbx
  401498:	e8 93 fb ff ff       	call   401030 <puts@plt>
  40149d:	48 8b 84 24 08 01 00 	mov    rax,QWORD PTR [rsp+0x108]
  4014a4:	00 
  4014a5:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
  4014ac:	00 00 
  4014ae:	75 44                	jne    4014f4 <win+0x114>
  4014b0:	48 81 c4 18 01 00 00 	add    rsp,0x118
  4014b7:	5b                   	pop    rbx
  4014b8:	5d                   	pop    rbp
  4014b9:	c3                   	ret    
  4014ba:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
  4014c0:	48 8d 3d 89 0e 00 00 	lea    rdi,[rip+0xe89]        # 402350 <_IO_stdin_used+0x350>
  4014c7:	e8 64 fb ff ff       	call   401030 <puts@plt>
  4014cc:	48 8b 84 24 08 01 00 	mov    rax,QWORD PTR [rsp+0x108]
  4014d3:	00 
  4014d4:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
  4014db:	00 00 
  4014dd:	75 15                	jne    4014f4 <win+0x114>
  4014df:	48 81 c4 18 01 00 00 	add    rsp,0x118
  4014e6:	48 8d 3d a3 0e 00 00 	lea    rdi,[rip+0xea3]        # 402390 <_IO_stdin_used+0x390>
  4014ed:	5b                   	pop    rbx
  4014ee:	5d                   	pop    rbp
  4014ef:	e9 3c fb ff ff       	jmp    401030 <puts@plt>
  4014f4:	e8 47 fb ff ff       	call   401040 <__stack_chk_fail@plt>
  4014f9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000401500 <fill_reviews>:
  401500:	48 83 ec 08          	sub    rsp,0x8
  401504:	bf 10 00 00 00       	mov    edi,0x10
  401509:	e8 72 fb ff ff       	call   401080 <malloc@plt>
  40150e:	bf 10 00 00 00       	mov    edi,0x10
  401513:	c7 00 59 6f 64 61    	mov    DWORD PTR [rax],0x61646f59
  401519:	c6 40 04 00          	mov    BYTE PTR [rax+0x4],0x0
  40151d:	48 89 05 7c 31 00 00 	mov    QWORD PTR [rip+0x317c],rax        # 4046a0 <review_names>
  401524:	e8 57 fb ff ff       	call   401080 <malloc@plt>
  401529:	bf 10 00 00 00       	mov    edi,0x10
  40152e:	c7 00 4c 75 6b 65    	mov    DWORD PTR [rax],0x656b754c
  401534:	c6 40 04 00          	mov    BYTE PTR [rax+0x4],0x0
  401538:	48 89 05 69 31 00 00 	mov    QWORD PTR [rip+0x3169],rax        # 4046a8 <review_names+0x8>
  40153f:	e8 3c fb ff ff       	call   401080 <malloc@plt>
  401544:	bf 10 00 00 00       	mov    edi,0x10
  401549:	48 b9 6f 6e 20 4a 69 	movabs rcx,0x6e6e694a206e6f
  401550:	6e 6e 00 
  401553:	48 ba 51 75 69 2d 47 	movabs rdx,0x206e6f472d697551
  40155a:	6f 6e 20 
  40155d:	48 89 10             	mov    QWORD PTR [rax],rdx
  401560:	48 89 48 05          	mov    QWORD PTR [rax+0x5],rcx
  401564:	48 89 05 45 31 00 00 	mov    QWORD PTR [rip+0x3145],rax        # 4046b0 <review_names+0x10>
  40156b:	e8 10 fb ff ff       	call   401080 <malloc@plt>
  401570:	bf 10 00 00 00       	mov    edi,0x10
  401575:	48 be 4f 62 69 2d 57 	movabs rsi,0x206e61572d69624f
  40157c:	61 6e 20 
  40157f:	48 ba 20 4b 65 6e 6f 	movabs rdx,0x69626f6e654b20
  401586:	62 69 00 
  401589:	48 89 30             	mov    QWORD PTR [rax],rsi
  40158c:	48 89 50 07          	mov    QWORD PTR [rax+0x7],rdx
  401590:	48 89 05 21 31 00 00 	mov    QWORD PTR [rip+0x3121],rax        # 4046b8 <review_names+0x18>
  401597:	e8 e4 fa ff ff       	call   401080 <malloc@plt>
  40159c:	48 b9 44 61 72 74 68 	movabs rcx,0x6156206874726144
  4015a3:	20 56 61 
  4015a6:	48 89 05 13 31 00 00 	mov    QWORD PTR [rip+0x3113],rax        # 4046c0 <review_names+0x20>
  4015ad:	48 89 08             	mov    QWORD PTR [rax],rcx
  4015b0:	c7 40 08 64 65 72 00 	mov    DWORD PTR [rax+0x8],0x726564
  4015b7:	48 83 c4 08          	add    rsp,0x8
  4015bb:	c3                   	ret    
  4015bc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

00000000004015c0 <logo>:
  4015c0:	53                   	push   rbx
  4015c1:	48 8d 1d f8 0d 00 00 	lea    rbx,[rip+0xdf8]        # 4023c0 <_IO_stdin_used+0x3c0>
  4015c8:	48 89 df             	mov    rdi,rbx
  4015cb:	e8 60 fa ff ff       	call   401030 <puts@plt>
  4015d0:	48 89 df             	mov    rdi,rbx
  4015d3:	e8 58 fa ff ff       	call   401030 <puts@plt>
  4015d8:	48 8d 3d 39 0e 00 00 	lea    rdi,[rip+0xe39]        # 402418 <_IO_stdin_used+0x418>
  4015df:	e8 4c fa ff ff       	call   401030 <puts@plt>
  4015e4:	48 8d 3d 85 0e 00 00 	lea    rdi,[rip+0xe85]        # 402470 <_IO_stdin_used+0x470>
  4015eb:	e8 40 fa ff ff       	call   401030 <puts@plt>
  4015f0:	48 8d 3d d1 0e 00 00 	lea    rdi,[rip+0xed1]        # 4024c8 <_IO_stdin_used+0x4c8>
  4015f7:	e8 34 fa ff ff       	call   401030 <puts@plt>
  4015fc:	48 8d 3d 1d 0f 00 00 	lea    rdi,[rip+0xf1d]        # 402520 <_IO_stdin_used+0x520>
  401603:	e8 28 fa ff ff       	call   401030 <puts@plt>
  401608:	48 8d 3d 69 0f 00 00 	lea    rdi,[rip+0xf69]        # 402578 <_IO_stdin_used+0x578>
  40160f:	e8 1c fa ff ff       	call   401030 <puts@plt>
  401614:	48 8d 3d b5 0f 00 00 	lea    rdi,[rip+0xfb5]        # 4025d0 <_IO_stdin_used+0x5d0>
  40161b:	e8 10 fa ff ff       	call   401030 <puts@plt>
  401620:	48 8d 3d 01 10 00 00 	lea    rdi,[rip+0x1001]        # 402628 <_IO_stdin_used+0x628>
  401627:	e8 04 fa ff ff       	call   401030 <puts@plt>
  40162c:	48 8d 3d 4d 10 00 00 	lea    rdi,[rip+0x104d]        # 402680 <_IO_stdin_used+0x680>
  401633:	e8 f8 f9 ff ff       	call   401030 <puts@plt>
  401638:	48 8d 3d 99 10 00 00 	lea    rdi,[rip+0x1099]        # 4026d8 <_IO_stdin_used+0x6d8>
  40163f:	e8 ec f9 ff ff       	call   401030 <puts@plt>
  401644:	48 8d 3d e5 10 00 00 	lea    rdi,[rip+0x10e5]        # 402730 <_IO_stdin_used+0x730>
  40164b:	e8 e0 f9 ff ff       	call   401030 <puts@plt>
  401650:	48 8d 3d 31 11 00 00 	lea    rdi,[rip+0x1131]        # 402788 <_IO_stdin_used+0x788>
  401657:	e8 d4 f9 ff ff       	call   401030 <puts@plt>
  40165c:	48 8d 3d 7d 11 00 00 	lea    rdi,[rip+0x117d]        # 4027e0 <_IO_stdin_used+0x7e0>
  401663:	e8 c8 f9 ff ff       	call   401030 <puts@plt>
  401668:	48 8d 3d c9 11 00 00 	lea    rdi,[rip+0x11c9]        # 402838 <_IO_stdin_used+0x838>
  40166f:	e8 bc f9 ff ff       	call   401030 <puts@plt>
  401674:	48 8d 3d 15 12 00 00 	lea    rdi,[rip+0x1215]        # 402890 <_IO_stdin_used+0x890>
  40167b:	e8 b0 f9 ff ff       	call   401030 <puts@plt>
  401680:	48 8d 3d 61 12 00 00 	lea    rdi,[rip+0x1261]        # 4028e8 <_IO_stdin_used+0x8e8>
  401687:	e8 a4 f9 ff ff       	call   401030 <puts@plt>
  40168c:	48 8d 3d ad 12 00 00 	lea    rdi,[rip+0x12ad]        # 402940 <_IO_stdin_used+0x940>
  401693:	e8 98 f9 ff ff       	call   401030 <puts@plt>
  401698:	48 8d 3d f9 12 00 00 	lea    rdi,[rip+0x12f9]        # 402998 <_IO_stdin_used+0x998>
  40169f:	e8 8c f9 ff ff       	call   401030 <puts@plt>
  4016a4:	48 8d 3d 45 13 00 00 	lea    rdi,[rip+0x1345]        # 4029f0 <_IO_stdin_used+0x9f0>
  4016ab:	e8 80 f9 ff ff       	call   401030 <puts@plt>
  4016b0:	48 8d 3d 91 13 00 00 	lea    rdi,[rip+0x1391]        # 402a48 <_IO_stdin_used+0xa48>
  4016b7:	e8 74 f9 ff ff       	call   401030 <puts@plt>
  4016bc:	48 8d 3d dd 13 00 00 	lea    rdi,[rip+0x13dd]        # 402aa0 <_IO_stdin_used+0xaa0>
  4016c3:	e8 68 f9 ff ff       	call   401030 <puts@plt>
  4016c8:	48 8d 3d 29 14 00 00 	lea    rdi,[rip+0x1429]        # 402af8 <_IO_stdin_used+0xaf8>
  4016cf:	e8 5c f9 ff ff       	call   401030 <puts@plt>
  4016d4:	48 8d 3d 75 14 00 00 	lea    rdi,[rip+0x1475]        # 402b50 <_IO_stdin_used+0xb50>
  4016db:	e8 50 f9 ff ff       	call   401030 <puts@plt>
  4016e0:	48 8d 3d c1 14 00 00 	lea    rdi,[rip+0x14c1]        # 402ba8 <_IO_stdin_used+0xba8>
  4016e7:	e8 44 f9 ff ff       	call   401030 <puts@plt>
  4016ec:	48 8d 3d 0d 15 00 00 	lea    rdi,[rip+0x150d]        # 402c00 <_IO_stdin_used+0xc00>
  4016f3:	e8 38 f9 ff ff       	call   401030 <puts@plt>
  4016f8:	48 8d 3d 59 15 00 00 	lea    rdi,[rip+0x1559]        # 402c58 <_IO_stdin_used+0xc58>
  4016ff:	e8 2c f9 ff ff       	call   401030 <puts@plt>
  401704:	48 8d 3d a5 15 00 00 	lea    rdi,[rip+0x15a5]        # 402cb0 <_IO_stdin_used+0xcb0>
  40170b:	e8 20 f9 ff ff       	call   401030 <puts@plt>
  401710:	48 8d 3d f1 15 00 00 	lea    rdi,[rip+0x15f1]        # 402d08 <_IO_stdin_used+0xd08>
  401717:	e8 14 f9 ff ff       	call   401030 <puts@plt>
  40171c:	48 8d 3d 3d 16 00 00 	lea    rdi,[rip+0x163d]        # 402d60 <_IO_stdin_used+0xd60>
  401723:	e8 08 f9 ff ff       	call   401030 <puts@plt>
  401728:	48 8d 3d 89 16 00 00 	lea    rdi,[rip+0x1689]        # 402db8 <_IO_stdin_used+0xdb8>
  40172f:	e8 fc f8 ff ff       	call   401030 <puts@plt>
  401734:	48 8d 3d d5 16 00 00 	lea    rdi,[rip+0x16d5]        # 402e10 <_IO_stdin_used+0xe10>
  40173b:	e8 f0 f8 ff ff       	call   401030 <puts@plt>
  401740:	48 8d 3d 21 17 00 00 	lea    rdi,[rip+0x1721]        # 402e68 <_IO_stdin_used+0xe68>
  401747:	e8 e4 f8 ff ff       	call   401030 <puts@plt>
  40174c:	48 8d 3d 6d 17 00 00 	lea    rdi,[rip+0x176d]        # 402ec0 <_IO_stdin_used+0xec0>
  401753:	e8 d8 f8 ff ff       	call   401030 <puts@plt>
  401758:	48 8d 3d b9 17 00 00 	lea    rdi,[rip+0x17b9]        # 402f18 <_IO_stdin_used+0xf18>
  40175f:	e8 cc f8 ff ff       	call   401030 <puts@plt>
  401764:	48 8d 3d 05 18 00 00 	lea    rdi,[rip+0x1805]        # 402f70 <_IO_stdin_used+0xf70>
  40176b:	e8 c0 f8 ff ff       	call   401030 <puts@plt>
  401770:	48 8d 3d 51 18 00 00 	lea    rdi,[rip+0x1851]        # 402fc8 <_IO_stdin_used+0xfc8>
  401777:	e8 b4 f8 ff ff       	call   401030 <puts@plt>
  40177c:	48 8d 3d 9d 18 00 00 	lea    rdi,[rip+0x189d]        # 403020 <_IO_stdin_used+0x1020>
  401783:	e8 a8 f8 ff ff       	call   401030 <puts@plt>
  401788:	48 89 df             	mov    rdi,rbx
  40178b:	e8 a0 f8 ff ff       	call   401030 <puts@plt>
  401790:	48 89 df             	mov    rdi,rbx
  401793:	5b                   	pop    rbx
  401794:	e9 97 f8 ff ff       	jmp    401030 <puts@plt>

Disassembly of section .fini:

000000000040179c <_fini>:
  40179c:	48 83 ec 08          	sub    rsp,0x8
  4017a0:	48 83 c4 08          	add    rsp,0x8
  4017a4:	c3                   	ret    
