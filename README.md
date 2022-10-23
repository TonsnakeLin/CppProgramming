

# Thread waked Up Time

## X86 Enviroment

### CPU

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

### OS

Linux CentOS76_VM 3.10.0-1127.el7.x86_64 #1 SMP Tue Mar 31 23:36:51 UTC 2020 x86_64 x86_64 x86_64 GNU/Linux



### data

we waked up thread 100 times every round.

| round | avg       | extra info                               |
| ----- | --------- | ---------------------------------------- |
| 1     | 14.520000 | 40 - 50us count: 9, 50 - 60us count: 5, over 60us: 10 <br />P80: 44us, P95: 78us, max: 132us |
| 2     | 15.285000 | 40 - 50us count: 9, 50 - 60us count: 14, over 60us: 10 <br />P80: 52us, P95: 65us, max: 112us |
| 3     | 18.500000 | 40 - 50us count: 16, 50 - 60us count: 7, over 60us: 12 <br />P80: 48us, P95: 81us, max: 488us |
| 4     | 13.095000 | 40 - 50us count: 12, 50 - 60us count: 6, over 60us: 6 <br />P80: 44us, P95: 66us, max: 80us |
| 5     | 14.180000 | 40 - 50us count: 16, 50 - 60us count: 8, over 60us: 7 <br />P80: 48us, P95: 71us, max: 85us |
|       |           |                                          |



## ARM Enviroment

### CPU

[tidb5@localhost CppProgramming]$ lscpu
Architecture:          aarch64
Byte Order:            Little Endian
CPU(s):                64
On-line CPU(s) list:   0-63
Thread(s) per core:    1
Core(s) per socket:    32
Socket(s):             2
NUMA node(s):          2
Model:                 0
BogoMIPS:              200.00
L1d cache:             64K
L1i cache:             64K
L2 cache:              512K
L3 cache:              32768K
NUMA node0 CPU(s):     0-31
NUMA node1 CPU(s):     32-63
Flags:                 fp asimd evtstrm aes pmull sha1 sha2 crc32 atomics fphp asimdhp cpuid asimdrdm jscvt fcma dcpop asimddp asimdfhm

### OS

Linux localhost.localdomain 4.18.0-305.10.2.el7.aarch64 #1 SMP Fri Jul 23 21:19:40 UTC 2021 aarch64 aarch64 aarch64 GNU/Linux

### DATA

we waked up thread 100 times every round.

| round | avg      | extra info                    |
| ----- | -------- | ----------------------------- |
| 1     | 1.765000 | P80: 4us, P95: 5us, max: 38us |
| 2     | 1.800000 | P80: 5us, P95: 6us, max: 7us  |
| 3     | 2.060000 | P80: 5us, P95: 6us, max: 9us  |
| 4     | 2.205000 | P80: 5us, P95: 7us, max: 40us |
| 5     | 1.770000 | P80: 4us, P95: 5us, max: 39us |
| 6     | 1.800000 | P80: 4us, P95: 6us, max: 7us  |
| 7     | 1.865000 | P80: 5us, P95: 6us, max: 6us  |
| 8     | 2.345000 | P80: 6us, P95: 7us, max: 10us |
|       |          |                               |



