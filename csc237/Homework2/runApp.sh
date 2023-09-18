#!/bin/bash
times=100
while [ $times -gt 0 ]
do
  ./app $1
  times=$(( $times - 1 ))
done