#!/bin/bash

echo "Steins Gate Start!"

mkdir r_compile
mkdir r_input
mkdir r_output
mkdir ./../output

path=$1

for file in $(ls $path);
do 
   if test -d $file
   then
      mkdir ./r_input/$file
      mkdir ./r_compile/$file
      mkdir ./r_output/$file
done