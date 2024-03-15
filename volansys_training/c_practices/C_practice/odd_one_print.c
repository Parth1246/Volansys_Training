#!/bin/bash

until [ $1 -le 100 ]
do echo "$1"
    let $1=( $1 + 1 )
done
