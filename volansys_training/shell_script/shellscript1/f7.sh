#!/bin/bash
clear
pgrep $1 || echo "not running"
