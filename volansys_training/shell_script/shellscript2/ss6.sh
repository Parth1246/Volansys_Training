#! /bin/sh
clear

ls “$1”  | fgrep -v “$2”

