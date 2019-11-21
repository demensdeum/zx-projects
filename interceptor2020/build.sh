export PATH=${PATH}:${HOME}/Sources/z88dk/bin
export ZCCCFG=${HOME}/Sources/z88dk/lib/config
cd build
zcc +zx -vn -O3 -m -startup=31 -clib=new ../src/*.c ../src/*.asm -o interceptor2020 -create-app
if [[ $1 == "run" ]]
    then
    cd ~/Apps/speccy/
    ./speccy -128 /home/demensdeum/Sources/zx-projects/interceptor2020/build/interceptor2020.tap
fi
