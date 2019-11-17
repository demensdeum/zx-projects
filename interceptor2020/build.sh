export PATH=${PATH}:${HOME}/Sources/z88dk/bin
export ZCCCFG=${HOME}/Sources/z88dk/lib/config
cd build
zcc +zx -vn -m -startup=31 -clib=sdcc_iy ../src/*.c ../src/*.asm -o interceptor2020 -create-app
