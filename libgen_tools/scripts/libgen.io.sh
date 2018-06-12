#!/bin/bash
set -e

declare -i timeout=10
declare -a all_md5s

usage () {
    echo "$0 [-i INPUT FILE] -h [MD5 LIST]"
}

wget_wrap () {
    local md5=$1
    local low=$2
    local key=$3
    local link2='http://download.libgen.io/get.php'
    wget -c -q --show-progress  -O $low --progress=bar \
	 "$link2?md5=$md5&key=$key"
}

get_key () {
    local link1='http://libgen.io/ads.php'
    local md5=$1
    curl -s "$link1?md5=$md5" | fgrep "href='$link2" | sed -E 's/.*key=([0-9A-Z]+).*/\1/'
}

download () {
    local md5=$1
    local low=${md5,,}
    echo "Doing $low"
    local key=$(get_key "$md5")
    echo "Key for $low is $key"
    echo "Downloading..."
    if ! wget_wrap "$md5" "$low" "$key"; then
	echo "Failed to download $low"
	read -p "User input is required... "
    fi
}

declare arg
while getopts "i:h" arg; do
    case $arg in
	i) all_md5s=( $(cat "$OPTARG") );;
	h) usage ; exit;;
    esac
done
shift $((OPTIND-1))
all_md5s=( "${all_md5s[@]}" "$@" )

declare -i i=0
declare -i last=$((${#all_md5s[@]}-1))
while [[ $i -le $last ]]; do
    download "${all_md5s[$i]}"
    if [[ $i -ne $last ]]; then
	sleep $timeout
    fi
    let i=i+1
done
