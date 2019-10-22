#!/bin/bash
#shell 默认变量都是全局的

#max
#maxstring
#maxfile
#line

function find_in_file(){
    words=`cat $1 | tr -s -c 'A-Za-z' "\n"`
    for i in ${words}; do
        t_len=`echo ${#i}`
        if [[ ${t_len} -gt ${max} ]]; then
            max=${t_len}
            maxstring=$i
            maxfile=$1
        fi
    done
}

function find_in_dir() {
    for i in 'ls -A'; do            #忽略"." ".." 防止进入无限死循环
        if [[ -d $1/$i  ]]; then
        find_in_dir $1/$i
        else 
        find_in_file $1/$i
        fi
    done
}
