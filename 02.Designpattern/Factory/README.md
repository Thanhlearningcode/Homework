## Build project

```bash
chmod +x build.sh
./build.sh
```

File output: `build/STM32F411.bin`, `build/STM32F411.elf`.

## Run googletest to check logic code
```bash
chmod +x build_test.sh
./build_test.sh
```


```bash Chekclog
Checklog: `LOGGING/build.log`
---

## Nạp code vào STM32

```bash
make flash
```

Hoặc thủ công:

```bash
st-flash write build/STM32F411.bin 0x8000000
```
![image](https://github.com/user-attachments/assets/1670253a-54c1-489d-961d-8cd74996eafd)


---

## Debug với OpenOCD và GDB

1. Chạy OpenOCD:

```bash
openocd -f interface/stlink.cfg -f target/stm32f4x.cfg
```

2. Mở terminal khác chạy GDB:

```bash
arm-none-eabi-gdb build/STM32F411.elf
```

3. Trong GDB:

![image](https://github.com/user-attachments/assets/5f37c46f-06b0-4d48-b82d-f12add0c7cb2)

```gdb
target remote localhost:3333
load
break main
continue
```


