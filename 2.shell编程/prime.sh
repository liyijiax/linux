#!/bin/bash

max_n=100

for (( i=0; i <= max_n; i++ )) do
    prime[$i]=0
done


for (( i=2; i<=max_n; i++ )) do
        if [[ prime[$i] -eq 0 ]]; then
            prime[++prime[0]]=$i
        fi
    for (( j=1; j<=prime[0]; j++ )) do
        if [[ $i*prime[$j] -gt $max_n ]]; then
            break
        fi
        prime[prime[j]*$i]=1
        if [[ $i%prime[j] -eq 0 ]]; then
            break
        fi
    done
done

for (( i=1; i <= prime[0]; i++ )) do
    echo -n ${prime[$i]}
    echo -n " "
done

echo ""
