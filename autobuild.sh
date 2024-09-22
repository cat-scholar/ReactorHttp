#! /bin/bash

set -e
# 如果没有build目录，则创建该目录
if  [ ! -d `pwd`/build ]; then
    mkdir `pwd`/build
fi

rm -rf `pwd`/build/*

cd `pwd` &&
    cmake -B build &&
    cmake --build build

# 把头文件拷贝到 /usr/include/reactorhttp.so库拷贝到 /usr/lib  PATH

if [ ! -d /usr/include/reactorhttp ]; then
    mkdir /usr/include/reactorhttp
fi

for header in `ls *.h`
do 
    cp $header /usr/include/reactorhttp
done

sudo cp `pwd`/lib/libreactorhttp.so /usr/lib

ldconfig
