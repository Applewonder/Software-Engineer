#!/bin/bash
echo "Steins Gate Start!"

rm -rf r_compile
rm -rf r_input
rm -rf r_output
rm -rf ./../output

mkdir r_compile
mkdir r_input
mkdir r_output
mkdir ./../output
for file in ./../input/*
do
   if test -d $file
   then
      mkdir ./r_input/${file##*/}
      mkdir ./r_compile/${file##*/}
      mkdir ./r_output/${file##*/}
   fi
done