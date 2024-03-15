#! /bin/sh
clear

find . dummy -type d -name "$1" | xargs rm -rf

