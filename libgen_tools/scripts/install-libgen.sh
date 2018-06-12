#!/bin/bash

set -e

add_file () {
    local md5=$(libgen-test "$1")
    if [[ -n $md5 ]]; then
	mv -- "$1" "$BOOK_DIR/md5/$md5"
    else
	echo "Can't add $1" >&2
    fi
}

main () {
    if [[ -f $1 ]]; then
	add_file "$1"
    elif [[ -d $1 ]]; then
	local f
	for f in "$1/*"; do
	    add_file "$f"
	done
    else
	echo "Bad argument: $1" >&2
	exit 192
    fi
}

btrfs property set $BOOK_DIR ro false
main "$1"
index-books
btrfs property set $BOOK_DIR ro true