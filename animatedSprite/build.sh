export PATH=${PATH}:${HOME}/Sources/z88dk/bin
export ZCCCFG=${HOME}/Sources/z88dk/lib/config
zcc +zx -vn -m -startup=31 -clib=sdcc_iy animatedSprite.c animatedSprite.asm -o animatedSprite -create-app
