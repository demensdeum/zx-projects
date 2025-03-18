export PATH=${PATH}:${HOME}/Sources/z88dk/bin
export ZCCCFG=${HOME}/Sources/z88dk/lib/config
zcc +zx -lndos -lm -create-app -o helloworld helloworld.c
