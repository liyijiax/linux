#!/bin/bash


max_len=0

function _max_() {
    cd $1
    for i in `ls`; do
        if [[ ${#i} -gt $max_len  ]]; then
            #echo $i
            max_len=${#i}
        fi
        if [[ -d $i ]]; then
            echo $i
            _max_ $i
            cd ..
        fi
    done
    return 
}

_max_ "/home" 

echo $max_len
