#!/bin/bash

# This file reads the report file generaged by gcov and parses it to
# get the total percentage. It then uses shields.io to download an
# appropriate svg file.

# $1 is the path to the gov report.txt file

REPORT_FILE=$1

PERCENT=$(cat ${REPORT_FILE} | tail -n 2|  awk '{print $NF}' | head -n 1)

VALUE=${PERCENT%?}

curl "https://img.shields.io/badge/Coverage-${VALUE}%25-green.svg"
