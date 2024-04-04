#!/bin/bash

METRICA="FLOPS_DP"
CPU=8

LIKWID_HOME=/home/soft/likwid

make -B
for k in $METRICA
do
    likwid-perfctr -C ${CPU} -g ${k} -m ./perfSL >${k}_SemOtimiz.log
done


