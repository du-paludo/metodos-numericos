#!/bin/bash

METRICA="FLOPS_DP"
<<<<<<< HEAD
CPU=15
=======
CPU=8
>>>>>>> 9893d061f7a6626bdd765280b7eb0eaf4e9ef180

LIKWID_HOME=/home/soft/likwid

make -B
<<<<<<< HEAD

for k in $METRICA
do
    likwid-perfctr -C ${CPU} -g ${k} -m ./perfSL > ${k}_SemOtimiz.log
done

cat FLOPS_DP_SemOtimiz.log | head -n 25 | tail -n 21

cat ${k}_SemOtimiz.log | grep "DP" | awk '!/AVX/ {print $N, "\n+----------------------+--------------+"}' | sed '/^Region/ s/^/\n/'


=======
for k in $METRICA
do
    likwid-perfctr -C ${CPU} -g ${k} -m ./perfSL >${k}_SemOtimiz.log
done

>>>>>>> 9893d061f7a6626bdd765280b7eb0eaf4e9ef180

