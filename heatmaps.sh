#!/bin/bash
make clean
make

# mpirun -np (processes) ./covid.x (vaccine) (isolation) (proportionIsolated) (startOfIsolation) (percVaccination) (startOfVaccination)

# vaccines: 0 - No Vaccination; 1 - AstraZeneca; 2 - CoronaVac; 4 - Janssen; 6 - Pfizer; 8 - BR Vaccines

#######################################################################################

# 0 days to start interventions

#######################################################################################

# iso 0
mkdir -p iso0days

vac=85

for ((iso=0;iso<=100;iso+=5))
do
    mkdir -p results
    mpirun -np 4 ./covid.x 8 1 $iso 0 $vac 0
    mv InfPrevalence.csv results/infPrevBR.csv
    mv epidemicsprevalence.csv results/epiPrevBR.csv
    mv InfIncidence.csv results/infIncBR.csv
    mv epidemicsincidence.csv results/epiIncBR.csv

    rm -rf iso0days/results$iso
    mv results iso0days/results$iso
done

#######################################################################################
