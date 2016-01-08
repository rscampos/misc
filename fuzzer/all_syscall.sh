#!/bin/bash
#### 1 to 444
mkdir output/
for i in `seq 1 30`;
do
	echo "Running: syscall $i" 
	echo "Syscall:$i" > ./output/$i
	date >> ./output/$i
	sh ./syscall_num.sh $i >> ./output/$i & 
	echo "Done: syscall $i" 
	echo "\n" 
done
