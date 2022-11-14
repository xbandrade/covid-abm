#!/bin/bash

# mpirun -np (processes) ./covid.x (vaccine) (isolation) (proportionIsolated) (startOfIsolation) (percVaccination) (startOfVaccination)

# vaccines: 0 - No Vaccination; 1 - AstraZeneca; 2 - CoronaVac; 4 - Janssen; 6 - Pfizer; 8 - BR Vaccines

make clean
make

vac=85

for v in 0 1 2 4 6 8
do
    for((iso=0;iso<=100;iso+=5))
    do
        mkdir -p results
        mkdir -p newsim/v$v-$vac/
        # if [ $vac -gt 0 ]
        # then
        #     v=8
        # fi
        mpirun -np 4 ./covid.x $v 1 $iso 0 $vac 0
        mv InfPrevalence.csv results/infPrevBR.csv
        mv epidemicsprevalence.csv results/epiPrevBR.csv
        mv InfIncidence.csv results/infIncBR.csv
        mv epidemicsincidence.csv results/epiIncBR.csv

        rm -rf newsim/v$v-$vac/i$iso
        mv results newsim/v$v-$vac/i$iso
    done
done
