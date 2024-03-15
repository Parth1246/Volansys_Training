#!/bin/bash
clear

if [ -d $1 ]
then
    echo cd "$1"
else
    mkdir $1 && cd "$1"

fi

