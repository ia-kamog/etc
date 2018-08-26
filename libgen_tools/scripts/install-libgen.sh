#!/usr/bin/env oksh

set -e

first2 () {
	echo "$1" | sed 's/^\(..\).*$/\1/'
}

add_file () {
    local md5=$(libgen-test "$1") fn
    if [[ -n $md5 ]]
	then
		fn="$BOOK_DIR/md5/$(first2 $md5)/$md5"
		mv -- "$1" "$fn"
		chmod 444 "$fn"
    else
		echo "Can't add $1" >&2
    fi
}

main () {
	local f arg
	arg="$1"
	if [[ -L $arg ]]
	then
		arg="$(readlink "$arg")"
	fi
    if [[ -f $arg ]]
	then
		add_file "$1"
    elif [[ -d $arg ]]
	then
		cd "$arg"
		for f in *
		do
			[[ -f $f ]] && add_file "$f"
		done
    else
		echo "Bad argument: $arg" >&2
		exit 192
    fi
}

zfs set readonly=off zm/ak/books
main "$1"
index-books
zfs set readonly=on zm/ak/books
