#!/bin/bash

rng_source_file=./unique_integers.c
rng_exec_file=./unique_integers
push_swap_file=./push_swap
checker=./checker

if [ ! -f "$push_swap_file" ]
	then
		echo push_swap program must be in current directory. Exiting...
		exit 1
fi
if [ ! -f "$checker" ]
	then
		echo "$checker" program must be in current directory. Exiting...
		exit 1
fi

if [ ! -f "$rng_exec_file" ]
	then
		if [ ! -f "$rng_source_file" ]
			then
				echo Source file "$rng_source_file" does not exist. Exiting...
				exit 1
		fi
		gcc -Wall -Wextra -Werror "$rng_source_file" -o "$rng_exec_file"
		echo Random generator number program compiled. Executing tests...
fi

if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <list_size> <n_trials>"
    exit 1
fi
best=1000000
worst=0
kos=0
n_list_prev=
for (( i = 1; i <= $2; i++ ))
	do
		n_list=$("$rng_exec_file" "$1")
		while [ "$n_list" = "$n_list_prev" ]
			do
				n_list=$("$rng_exec_file" "$1")
			done
		n_list_prev=$n_list
		#echo n_list: $n_list
		op_list=$("$push_swap_file" $n_list)
		#echo op_list: $op_list
		if [ -z "$op_list" ]
			then
				op_count=0
			else
				op_count=$(echo "$op_list" | wc -l | tr -d " ")
		fi
		#echo op_count: $op_count
		if [ -z "$op_list" ]
			then
				result=$("$push_swap_file" $n_list | "$checker" $n_list)
			else
				result=$(echo "$op_list" | "$checker" $n_list)
		fi
		#echo result: $result
		if [[ "$result" == "KO" ]]
			then
				kos=$((kos + 1))
				continue
		fi
		if (( "$op_count" < "$best" ))
			then
				best="$op_count"
		fi
		if (( "$op_count" > "$worst" ))
			then
				worst="$op_count"
		fi
		echo Test $i: Sorted "$1" integers with "$op_count" operations. Result is "$result"
	done
echo Executed $2 trials with "$kos" KOs.
echo Best result was "$best" moves.
echo Worst result was "$worst" moves.

