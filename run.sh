#!/bin/bash

# mpirun -np (processes) ./covid.x (vaccine) (isolation) (proportionIsolated) (startOfIsolation) (percVaccination) (startOfVaccination)

# vaccines: 0 - No Vaccination; 1 - AstraZeneca; 2 - CoronaVac; 4 - Janssen; 6 - Pfizer; 8 - BR Vaccines

make clean
make

<<com
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
        mpirun -np 8 ./covid.x $v 1 $iso 0 $vac 0
        mv InfPrevalence.csv results/infPrev.csv
        mv epidemicsprevalence.csv results/epiPrev.csv
        mv InfIncidence.csv results/infInc.csv
        mv epidemicsincidence.csv results/epiInc.csv

        rm -rf newsim/v$v-$vac/i$iso
        mv results newsim/v$v-$vac/i$iso
    done
done

for iso in 0 50
do
    for v in 0 1 2 4 6 8
    do
        for((vac=0;vac<=100;vac+=5))
        do
            mkdir -p results
            mkdir -p newsim2/i$iso/v$v/v$vac/

            mpirun -np 8 ./covid.x $v 1 $iso 0 $vac 0
            mv InfPrevalence.csv results/infPrev.csv
            mv epidemicsprevalence.csv results/epiPrev.csv
            mv InfIncidence.csv results/infInc.csv
            mv epidemicsincidence.csv results/epiInc.csv

            rm -rf newsim2/i$iso/v$v/v$vac
            mv results newsim2/i$iso/v$v/v$vac
        done
    done
done
com

for v in 0 1 2 4 6 8
do
    for vac in 0 25 50 75 100
    do
        for((iso=0;iso<=100;iso+=5))
        do
            if ([ $v -eq 0 ] && [ $vac -gt 0 ]) || ([ $vac -eq 0 ] && [ $v -gt 0 ])
            then
                break
            fi

            mkdir -p results
            mkdir -p newsim3/v$v/$vac/

            mpirun -np 8 ./covid.x $v 1 $iso 0 $vac 0
            mv InfPrevalence.csv results/infPrev.csv
            mv epidemicsprevalence.csv results/epiPrev.csv
            mv InfIncidence.csv results/infInc.csv
            mv epidemicsincidence.csv results/epiInc.csv

            rm -rf newsim3/v$v/$vac/i$iso
            mv results newsim3/v$v/$vac/i$iso
        done
    done
done
