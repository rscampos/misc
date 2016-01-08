#!/bin/bash
for j in `seq 1 50`;
do
	for k in `seq 1 50`;
	do

		for l in `seq 1 50`;
		do
			echo syscall:$1 par1:$j par2:$k par3:$l
			strace ./poc $1 $j $k $l 2>&1 | grep "+++"
		done
	done
done
date >> ./output/$1
