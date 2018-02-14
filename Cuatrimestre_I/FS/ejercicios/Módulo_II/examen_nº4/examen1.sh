#!/bin/bash

for archivo in $(ls $1)
do
	if ( test -d $archivo )
	then
		echo $archivo
	fi
done
