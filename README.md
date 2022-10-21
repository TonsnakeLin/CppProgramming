# Enviroment

## CPU

Architecture:          x86_64
CPU op-mode(s):        32-bit, 64-bit
Byte Order:            Little Endian
CPU(s):                8
On-line CPU(s) list:   0-7
Thread(s) per core:    1
Core(s) per socket:    2

座：                 4
NUMA 节点：         1
厂商 ID：           GenuineIntel
CPU 系列：          15
型号：              6
型号名称：        Common KVM processor
步进：              1
CPU MHz：             2199.998
BogoMIPS：            4399.99
超管理器厂商：  KVM
虚拟化类型：     完全
L1d 缓存：          32K
L1i 缓存：          32K
L2 缓存：           4096K
L3 缓存：           16384K
NUMA 节点0 CPU：    0-7
Flags:                 fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx lm constant_tsc nopl xtopology eagerfpu pni cx16 x2apic hypervisor lahf_lm

## OS

Linux CentOS76_VM 3.10.0-1127.el7.x86_64 #1 SMP Tue Mar 31 23:36:51 UTC 2020 x86_64 x86_64 x86_64 GNU/Linux



# Thread waked Up Time

we waked up thread 100 times every round.

| round | avg       | extra info                               |
| ----- | --------- | ---------------------------------------- |
| 1     | 14.520000 | 40~50us count: 9, 50~60us count: 5, over 60us: 10 <br />P80: 44us, P95: 78us, max: 132us |
| 2     | 15.285000 | 40~50us count: 9, 50~60us count: 14, over 60us: 10 <br />P80: 52us, P95: 65us, max: 112us |
| 3     | 18.500000 | 40~50us count: 16, 50~60us count: 7, over 60us: 12 <br />P80: 48us, P95: 81us, max: 488us |
| 4     | 13.095000 | 40~50us count: 12, 50~60us count: 6, over 60us: 6 <br />P80: 44us, P95: 66us, max: 80us |
| 5     | 14.180000 | 40~50us count: 16, 50~60us count: 8, over 60us: 7 <br />P80: 48us, P95: 71us, max: 85us |
|       |           |                                          |

