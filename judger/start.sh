#!/bin/bash
echo "Steins Gate Start!"

mkdir compiled
cd compiled

path=$1

for file in $(ls $path);
do 
    if [ "${file##*.}" = "cpp" ]; then
        echo "Now compile ${file}\n"
        file_a=(basename $file .cpp)
        echo "$file_a" >> filelist.txt
        echo "\n" >> filelist.txt
        g++ $f -o ./"${i%.cpp}"
    fi
done