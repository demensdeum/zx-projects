export PATH=${PATH}:${HOME}/Sources/z88dk/bin
export ZCCCFG=${HOME}/Sources/z88dk/lib/config
zcc +zx -vn -m -startup=31 -clib=sdcc_iy interceptor2020.c interceptor2020.asm -o interceptor2020 -create-app
