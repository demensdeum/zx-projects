export PATH=${PATH}:${HOME}/Sources/z88dk/bin
export ZCCCFG=${HOME}/Sources/z88dk/lib/config
zcc +zx -vn -m -startup=31 -clib=sdcc_iy bigCircle.c bigCircle.asm -o bubble_masked -create-app
