# Greenspace SNES WLA-DX

This repository contains a minimal project template for SNES development using
the WLA-DX 65816 assembler.

It contains a demo `greenspace.asm` program that displays a simple green
background.  The `Makefile` can be used to assemble the program into a
`greenspace.smc` ROM file, which can be run in an emulator or on real hardware.

```sh
git clone https://github.com/giulioprocopio/greenspace-snes-wla-dx.git
cd greenspace-snes-wla-dx
make greenspace.smc
```
