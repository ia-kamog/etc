#!/bin/bash
# Move registered in Libgen database files between two directories
from_dir=$1
to_dir=$2
if [[ ! -d $from_dir || ! -d $to_dir ]]
then
    echo "$dir doesn't exist" >&2
    exit 192
fi

for file in "$from_dir"/*
do
    if [[ -f $file ]]; then
	printf "%50.50s\t" "$file"
	md5=$(libgen-test "$file")
	if [[ -n $md5 ]]; then
	    mv -- "$file" "$to_dir/$md5"
	    printf "MOVED\n"
	else
	    printf "NOT REG\n"
	fi
    fi
done
