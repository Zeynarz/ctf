## Writeup (for self)   
Heapleak -> Heap overflow -> pie leak -> system("/bin/sh")

HeapLeak
----------
jemalloc chunks dont have heap metadata, all the contents stick together  
If you completely fill up nameChunk, printf will think that the ptr in object is part of the str in name (because no null byte in between)   
```  
|--------|  
|Object  |   
|--------|  
|Name    |  
|--------|  
|Object  |  
|--------|  
```

Heap Overflow
---------------
merge() will find the len of name1 using strlen() (!!!) and put name2 after name1 using the index/int returned by strlen  
"AAA" + "BBB"  = "AAABBB"  

you can trick strlen by completely filling up the nameChunk  
```
|--------|
|"AAAAAA"| <- Name1
|--------|
|"BBBBBB"| <- Random chunk
|--------|
|00000000|
|--------|
```

In reality the length of name1 is only 6, but strlen returned 12 cause there are no null bytes. Overflow!!!! The index used to concatenate the strings will be way too big  
"AAAAAA" + "CCCCCC" = "AAAAAA??????CCCCCC"

(noticed that a lot of vulns come from string functions and null bytes, so look when reading code that has string functions be particularly careful and attentive)  

Pie Leak and system("/bin/sh")
-------------------------------
Leak pie by printing functionChunk and executing system("/bin/sh") by overwriting functionChunk 

