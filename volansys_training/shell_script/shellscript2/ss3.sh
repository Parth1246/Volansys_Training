#! /bin/sh
clear

echo -e "enter the name of the file : \c"
read file_name

if [ -d $file_name ]
then
	echo "file exist"
else
	echo "file not found"
fi
