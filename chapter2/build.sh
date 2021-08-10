#!/bin/bash

FILE=$1
NO_EXTENSION=${FILE%.*}

gcc -std=c89 -lm $FILE -o $NO_EXTENSION

