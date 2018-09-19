#!/bin/bash

name="/tmp/file.txt"

check (){
	echo 1 > "$name"
	"./ex2-$1.sh" "$name" & "./ex2-$1.sh" "$name"
	sleep 1 # wait for termination of the background job
	echo -n "Lines in the file: "
	echo $(wc -l "$name" | awk '{print $1}')
	echo -n "The last line: "
	echo $(tail -n 1 "$name")
	echo
}

echo "Wrong solution:"
check wrong
echo "Correct solution:"
check correct
