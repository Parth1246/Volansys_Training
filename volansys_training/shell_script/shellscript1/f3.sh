#!/bin/bash
clear

ls "$1" | grep -v "$2"
