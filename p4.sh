#!/bin/bash
find "$1" -type f -mtime -"$2" -printf "%h%f %TD\n"