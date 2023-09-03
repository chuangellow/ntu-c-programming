#!/bin/bash

problem_num=$(basename $(pwd))

start=0
end=10

for x in $(seq $start $end)
do
    url="https://judgegirl.csie.org/downloads/testdata/${problem_num}/${x}.in"
    wget $url
    url="https://judgegirl.csie.org/downloads/testdata/${problem_num}/${x}.out"
	wget $url
done
