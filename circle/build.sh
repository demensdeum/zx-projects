export PATH=${PATH}:${HOME}/Sources/z88dk/bin
export ZCCCFG=${HOME}/Sources/z88dk/lib/config
zcc +zx -vn -startup=31 -clib=sdcc_iy circle.c circle.asm -o circle -create-app
