#!/bin/bash

for i in {1..10}
do
	while ! ln "$1" "$1.lock" 2> /dev/null; do :; done # busy waiting
	str=$(tail -n 1 "$1")
	((str++))
	echo $str >> "$1"
	rm "$1.lock"
done
