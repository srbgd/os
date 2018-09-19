#!/bin/bash

for i in {1..10}
do
	str=$(tail -n 1 "$1")
	((str++))
	echo $str >> "$1"
done

