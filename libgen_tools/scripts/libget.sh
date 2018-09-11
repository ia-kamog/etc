#!/bin/sh
set -e
downpage='http://libgen.io/ads.php?md5='
downlink='http://download.libgen.io/get.php'
sedexpr=".*http://download\.libgen\.io/get\.php.*key='?([[:alnum:]]+)'?.*"
tr 'A-Z' 'a-z' |
while read md5
do
	if ! echo "$md5" | egrep -q '^[[:xdigit:]]{32}$'
	then
		echo $md5 is not a valid md5 sum >&2
		continue
	elif [ -e "$md5" ] && [ "$(md5 -q "$md5")" = "$md5" ]
	then
		echo "$md5 already downloaded, skipping" >&2
		continue
	else
		key=$(fetch -q -o - "$downpage$md5" | sed -En "s|$sedexpr|\1|p")
		if [ -z "$key" ]
		then
			echo "Couldn't fetch key for $md5" >&2
			exit 192
		fi
		sleep 5
		fetch -r -o "$md5" "$downlink?md5=$md5&key=$key"
	fi
done
