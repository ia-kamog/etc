#!/usr/bin/env oksh

fn=$1;
md5=$(md5 -q -- "$fn")
typeset -i c
c=$(echo "SELECT COUNT(MD5) FROM updated WHERE MD5 = '$md5';" |
	mysql -AN books)
if [[ c -ne 0 ]]; then
    echo $md5
    exit 0
else
    exit 1
fi
