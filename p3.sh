#!/bin/bash

find "$1" -type f -print0 | xargs -0 grep "$2"