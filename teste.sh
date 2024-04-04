#!/bin/bash

METRICA="FLOPS_DP"

CPU=15

CPU=8

LIKWID_HOME=/home/soft/likwid

make -B

for k in $METRICA
do
    likwid-perfctr -C ${CPU} -g ${k} -m ./perfSL > ${k}_SemOtimiz.log
done

cat FLOPS_DP_SemOtimiz.log | head -n 25 | tail -n 21

cat ${k}_SemOtimiz.log | grep "DP" | awk '!/AVX/ {print $N, "\n+----------------------+--------------+"}' | sed '/^Region/ s/^/\n/'

