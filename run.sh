make clean
make

# mpirun -np (processes) ./covid.x (vaccine) (isolation) (proportionIsolated) (startOfIsolation) (percVaccination) (startOfVaccination)

# vaccines: 0 - No Vaccination; 1 - AstraZeneca; 2 - CoronaVac; 4 - Janssen; 6 - Pfizer; 8 - BR Vaccines

#######################################################################################

# 0 days to start interventions

#######################################################################################

# iso 0
mkdir -p results
mkdir -p iso0days
mkdir -p iso20days
mkdir -p iso40days

mpirun -np 4 ./covid.x 0 0 0.0 0 0.85 0
mv InfPrevalence.csv results/infPrevNOVAC.csv
mv epidemicsprevalence.csv results/epiPrevNOVAC.csv
mv InfIncidence.csv results/infIncNOVAC.csv
mv epidemicsincidence.csv results/epiIncNOVAC.csv


mpirun -np 4 ./covid.x 8 0 0.0 0 0.85 0
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


mpirun -np 4 ./covid.x 1 0 0.0 0 0.85 0
mv InfPrevalence.csv results/infPrevAZ.csv
mv epidemicsprevalence.csv results/epiPrevAZ.csv
mv InfIncidence.csv results/infIncAZ.csv
mv epidemicsincidence.csv results/epiIncAZ.csv


mpirun -np 4 ./covid.x 2 0 0.0 0 0.85 0
mv InfPrevalence.csv results/infPrevCV.csv
mv epidemicsprevalence.csv results/epiPrevCV.csv
mv InfIncidence.csv results/infIncCV.csv
mv epidemicsincidence.csv results/epiIncCV.csv


mpirun -np 4 ./covid.x 4 0 0.0 0 0.85 0
mv InfPrevalence.csv results/infPrevJJ.csv
mv epidemicsprevalence.csv results/epiPrevJJ.csv
mv InfIncidence.csv results/infIncJJ.csv
mv epidemicsincidence.csv results/epiIncJJ.csv


mpirun -np 4 ./covid.x 6 0 0.0 0 0.85 0
mv InfPrevalence.csv results/infPrevPF.csv
mv epidemicsprevalence.csv results/epiPrevPF.csv
mv InfIncidence.csv results/infIncPF.csv
mv epidemicsincidence.csv results/epiIncPF.csv


rm -rf iso0days/resultsNOISO
mv results iso0days/resultsNOISO

###########################
# iso .5

mkdir -p results
mpirun -np 4 ./covid.x 0 1 0.5 0 0.85 0
mv InfPrevalence.csv results/infPrevNOVAC.csv
mv epidemicsprevalence.csv results/epiPrevNOVAC.csv
mv InfIncidence.csv results/infIncNOVAC.csv
mv epidemicsincidence.csv results/epiIncNOVAC.csv


mpirun -np 4 ./covid.x 8 1 0.5 0 0.85 0
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


mpirun -np 4 ./covid.x 1 1 0.5 0 0.85 0
mv InfPrevalence.csv results/infPrevAZ.csv
mv epidemicsprevalence.csv results/epiPrevAZ.csv
mv InfIncidence.csv results/infIncAZ.csv
mv epidemicsincidence.csv results/epiIncAZ.csv


mpirun -np 4 ./covid.x 2 1 0.5 0 0.85 0
mv InfPrevalence.csv results/infPrevCV.csv
mv epidemicsprevalence.csv results/epiPrevCV.csv
mv InfIncidence.csv results/infIncCV.csv
mv epidemicsincidence.csv results/epiIncCV.csv


mpirun -np 4 ./covid.x 4 1 0.5 0 0.85 0
mv InfPrevalence.csv results/infPrevJJ.csv
mv epidemicsprevalence.csv results/epiPrevJJ.csv
mv InfIncidence.csv results/infIncJJ.csv
mv epidemicsincidence.csv results/epiIncJJ.csv


mpirun -np 4 ./covid.x 6 1 0.5 0 0.85 0
mv InfPrevalence.csv results/infPrevPF.csv
mv epidemicsprevalence.csv results/epiPrevPF.csv
mv InfIncidence.csv results/infIncPF.csv
mv epidemicsincidence.csv results/epiIncPF.csv


rm -rf iso0days/results50
mv results iso0days/results50


#########################
# iso .8

mkdir -p results


mpirun -np 4 ./covid.x 0 1 0.8 0 0.85 0
mv InfPrevalence.csv results/infPrevNOVAC.csv
mv epidemicsprevalence.csv results/epiPrevNOVAC.csv
mv InfIncidence.csv results/infIncNOVAC.csv
mv epidemicsincidence.csv results/epiIncNOVAC.csv


mpirun -np 4 ./covid.x 8 1 0.8 0 0.85 0
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


mpirun -np 4 ./covid.x 1 1 0.8 0 0.85 0
mv InfPrevalence.csv results/infPrevAZ.csv
mv epidemicsprevalence.csv results/epiPrevAZ.csv
mv InfIncidence.csv results/infIncAZ.csv
mv epidemicsincidence.csv results/epiIncAZ.csv


mpirun -np 4 ./covid.x 2 1 0.8 0 0.85 0
mv InfPrevalence.csv results/infPrevCV.csv
mv epidemicsprevalence.csv results/epiPrevCV.csv
mv InfIncidence.csv results/infIncCV.csv
mv epidemicsincidence.csv results/epiIncCV.csv


mpirun -np 4 ./covid.x 4 1 0.8 0 0.85 0
mv InfPrevalence.csv results/infPrevJJ.csv
mv epidemicsprevalence.csv results/epiPrevJJ.csv
mv InfIncidence.csv results/infIncJJ.csv
mv epidemicsincidence.csv results/epiIncJJ.csv


mpirun -np 4 ./covid.x 6 1 0.8 0 0.85 0
mv InfPrevalence.csv results/infPrevPF.csv
mv epidemicsprevalence.csv results/epiPrevPF.csv
mv InfIncidence.csv results/infIncPF.csv
mv epidemicsincidence.csv results/epiIncPF.csv


rm -rf iso0days/results80
mv results iso0days/results80


#########################
# iso .9

mkdir -p results


mpirun -np 4 ./covid.x 0 1 0.9 0 0.85 0
mv InfPrevalence.csv results/infPrevNOVAC.csv
mv epidemicsprevalence.csv results/epiPrevNOVAC.csv
mv InfIncidence.csv results/infIncNOVAC.csv
mv epidemicsincidence.csv results/epiIncNOVAC.csv


mpirun -np 4 ./covid.x 8 1 0.9 0 0.85 0
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


mpirun -np 4 ./covid.x 1 1 0.9 0 0.85 0
mv InfPrevalence.csv results/infPrevAZ.csv
mv epidemicsprevalence.csv results/epiPrevAZ.csv
mv InfIncidence.csv results/infIncAZ.csv
mv epidemicsincidence.csv results/epiIncAZ.csv


mpirun -np 4 ./covid.x 2 1 0.9 0 0.85 0
mv InfPrevalence.csv results/infPrevCV.csv
mv epidemicsprevalence.csv results/epiPrevCV.csv
mv InfIncidence.csv results/infIncCV.csv
mv epidemicsincidence.csv results/epiIncCV.csv


mpirun -np 4 ./covid.x 4 1 0.9 0 0.85 0
mv InfPrevalence.csv results/infPrevJJ.csv
mv epidemicsprevalence.csv results/epiPrevJJ.csv
mv InfIncidence.csv results/infIncJJ.csv
mv epidemicsincidence.csv results/epiIncJJ.csv


mpirun -np 4 ./covid.x 6 1 0.9 0 0.85 0
mv InfPrevalence.csv results/infPrevPF.csv
mv epidemicsprevalence.csv results/epiPrevPF.csv
mv InfIncidence.csv results/infIncPF.csv
mv epidemicsincidence.csv results/epiIncPF.csv


rm -rf iso0days/results90
mv results iso0days/results90

##################################################################################

# 20 days to start interventions

##################################################################################
# iso 0

rm -rf results
mkdir -p results

mpirun -np 4 ./covid.x 0 0 0.0 20 0.85 20
mv InfPrevalence.csv results/infPrevNOVAC.csv
mv epidemicsprevalence.csv results/epiPrevNOVAC.csv
mv InfIncidence.csv results/infIncNOVAC.csv
mv epidemicsincidence.csv results/epiIncNOVAC.csv


mpirun -np 4 ./covid.x 8 0 0.0 20 0.85 20
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


mpirun -np 4 ./covid.x 1 0 0.0 20 0.85 20
mv InfPrevalence.csv results/infPrevAZ.csv
mv epidemicsprevalence.csv results/epiPrevAZ.csv
mv InfIncidence.csv results/infIncAZ.csv
mv epidemicsincidence.csv results/epiIncAZ.csv


mpirun -np 4 ./covid.x 2 0 0.0 20 0.85 20
mv InfPrevalence.csv results/infPrevCV.csv
mv epidemicsprevalence.csv results/epiPrevCV.csv
mv InfIncidence.csv results/infIncCV.csv
mv epidemicsincidence.csv results/epiIncCV.csv


mpirun -np 4 ./covid.x 4 0 0.0 20 0.85 20
mv InfPrevalence.csv results/infPrevJJ.csv
mv epidemicsprevalence.csv results/epiPrevJJ.csv
mv InfIncidence.csv results/infIncJJ.csv
mv epidemicsincidence.csv results/epiIncJJ.csv


mpirun -np 4 ./covid.x 6 0 0.0 20 0.85 20
mv InfPrevalence.csv results/infPrevPF.csv
mv epidemicsprevalence.csv results/epiPrevPF.csv
mv InfIncidence.csv results/infIncPF.csv
mv epidemicsincidence.csv results/epiIncPF.csv


rm -rf iso20days/resultsNOISO
mv results iso20days/resultsNOISO

###########################
# iso .5

mkdir -p results

mpirun -np 4 ./covid.x 0 1 0.5 20 0.85 20
mv InfPrevalence.csv results/infPrevNOVAC.csv
mv epidemicsprevalence.csv results/epiPrevNOVAC.csv
mv InfIncidence.csv results/infIncNOVAC.csv
mv epidemicsincidence.csv results/epiIncNOVAC.csv


mpirun -np 4 ./covid.x 8 1 0.5 20 0.85 20
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


mpirun -np 4 ./covid.x 1 1 0.5 20 0.85 20
mv InfPrevalence.csv results/infPrevAZ.csv
mv epidemicsprevalence.csv results/epiPrevAZ.csv
mv InfIncidence.csv results/infIncAZ.csv
mv epidemicsincidence.csv results/epiIncAZ.csv


mpirun -np 4 ./covid.x 2 1 0.5 20 0.85 20
mv InfPrevalence.csv results/infPrevCV.csv
mv epidemicsprevalence.csv results/epiPrevCV.csv
mv InfIncidence.csv results/infIncCV.csv
mv epidemicsincidence.csv results/epiIncCV.csv


mpirun -np 4 ./covid.x 4 1 0.5 20 0.85 20
mv InfPrevalence.csv results/infPrevJJ.csv
mv epidemicsprevalence.csv results/epiPrevJJ.csv
mv InfIncidence.csv results/infIncJJ.csv
mv epidemicsincidence.csv results/epiIncJJ.csv


mpirun -np 4 ./covid.x 6 1 0.5 20 0.85 20
mv InfPrevalence.csv results/infPrevPF.csv
mv epidemicsprevalence.csv results/epiPrevPF.csv
mv InfIncidence.csv results/infIncPF.csv
mv epidemicsincidence.csv results/epiIncPF.csv


rm -rf iso20days/results50
mv results iso20days/results50


#########################
# iso .8

mkdir -p results

mpirun -np 4 ./covid.x 0 1 0.8 20 0.85 20
mv InfPrevalence.csv results/infPrevNOVAC.csv
mv epidemicsprevalence.csv results/epiPrevNOVAC.csv
mv InfIncidence.csv results/infIncNOVAC.csv
mv epidemicsincidence.csv results/epiIncNOVAC.csv


mpirun -np 4 ./covid.x 8 1 0.8 20 0.85 20
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


mpirun -np 4 ./covid.x 1 1 0.8 20 0.85 20
mv InfPrevalence.csv results/infPrevAZ.csv
mv epidemicsprevalence.csv results/epiPrevAZ.csv
mv InfIncidence.csv results/infIncAZ.csv
mv epidemicsincidence.csv results/epiIncAZ.csv


mpirun -np 4 ./covid.x 2 1 0.8 20 0.85 20
mv InfPrevalence.csv results/infPrevCV.csv
mv epidemicsprevalence.csv results/epiPrevCV.csv
mv InfIncidence.csv results/infIncCV.csv
mv epidemicsincidence.csv results/epiIncCV.csv


mpirun -np 4 ./covid.x 4 1 0.8 20 0.85 20
mv InfPrevalence.csv results/infPrevJJ.csv
mv epidemicsprevalence.csv results/epiPrevJJ.csv
mv InfIncidence.csv results/infIncJJ.csv
mv epidemicsincidence.csv results/epiIncJJ.csv


mpirun -np 4 ./covid.x 6 1 0.8 20 0.85 20
mv InfPrevalence.csv results/infPrevPF.csv
mv epidemicsprevalence.csv results/epiPrevPF.csv
mv InfIncidence.csv results/infIncPF.csv
mv epidemicsincidence.csv results/epiIncPF.csv


rm -rf iso20days/results80
mv results iso20days/results80


##########################
# iso .9

mkdir -p results


mpirun -np 4 ./covid.x 0 1 0.9 20 0.85 20
mv InfPrevalence.csv results/infPrevNOVAC.csv
mv epidemicsprevalence.csv results/epiPrevNOVAC.csv
mv InfIncidence.csv results/infIncNOVAC.csv
mv epidemicsincidence.csv results/epiIncNOVAC.csv


mpirun -np 4 ./covid.x 8 1 0.9 20 0.85 20
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


mpirun -np 4 ./covid.x 1 1 0.9 20 0.85 20
mv InfPrevalence.csv results/infPrevAZ.csv
mv epidemicsprevalence.csv results/epiPrevAZ.csv
mv InfIncidence.csv results/infIncAZ.csv
mv epidemicsincidence.csv results/epiIncAZ.csv


mpirun -np 4 ./covid.x 2 1 0.9 20 0.85 20
mv InfPrevalence.csv results/infPrevCV.csv
mv epidemicsprevalence.csv results/epiPrevCV.csv
mv InfIncidence.csv results/infIncCV.csv
mv epidemicsincidence.csv results/epiIncCV.csv


mpirun -np 4 ./covid.x 4 1 0.9 20 0.85 20
mv InfPrevalence.csv results/infPrevJJ.csv
mv epidemicsprevalence.csv results/epiPrevJJ.csv
mv InfIncidence.csv results/infIncJJ.csv
mv epidemicsincidence.csv results/epiIncJJ.csv


mpirun -np 4 ./covid.x 6 1 0.9 20 0.85 20
mv InfPrevalence.csv results/infPrevPF.csv
mv epidemicsprevalence.csv results/epiPrevPF.csv
mv InfIncidence.csv results/infIncPF.csv
mv epidemicsincidence.csv results/epiIncPF.csv


rm -rf iso20days/results90
mv results iso20days/results90

##################################################################################

# 40 days to start interventions

##################################################################################
# iso 0

rm -rf results
mkdir -p results

mpirun -np 4 ./covid.x 0 0 0.0 40 0.85 40
mv InfPrevalence.csv results/infPrevNOVAC.csv
mv epidemicsprevalence.csv results/epiPrevNOVAC.csv
mv InfIncidence.csv results/infIncNOVAC.csv
mv epidemicsincidence.csv results/epiIncNOVAC.csv


mpirun -np 4 ./covid.x 8 0 0.0 40 0.85 40
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


mpirun -np 4 ./covid.x 1 0 0.0 40 0.85 40
mv InfPrevalence.csv results/infPrevAZ.csv
mv epidemicsprevalence.csv results/epiPrevAZ.csv
mv InfIncidence.csv results/infIncAZ.csv
mv epidemicsincidence.csv results/epiIncAZ.csv


mpirun -np 4 ./covid.x 2 0 0.0 40 0.85 40
mv InfPrevalence.csv results/infPrevCV.csv
mv epidemicsprevalence.csv results/epiPrevCV.csv
mv InfIncidence.csv results/infIncCV.csv
mv epidemicsincidence.csv results/epiIncCV.csv


mpirun -np 4 ./covid.x 4 0 0.0 40 0.85 40
mv InfPrevalence.csv results/infPrevJJ.csv
mv epidemicsprevalence.csv results/epiPrevJJ.csv
mv InfIncidence.csv results/infIncJJ.csv
mv epidemicsincidence.csv results/epiIncJJ.csv


mpirun -np 4 ./covid.x 6 0 0.0 40 0.85 40
mv InfPrevalence.csv results/infPrevPF.csv
mv epidemicsprevalence.csv results/epiPrevPF.csv
mv InfIncidence.csv results/infIncPF.csv
mv epidemicsincidence.csv results/epiIncPF.csv


rm -rf iso40days/resultsNOISO
mv results iso40days/resultsNOISO

###########################
# iso .5

mkdir -p results

mpirun -np 4 ./covid.x 0 1 0.5 40 0.85 40
mv InfPrevalence.csv results/infPrevNOVAC.csv
mv epidemicsprevalence.csv results/epiPrevNOVAC.csv
mv InfIncidence.csv results/infIncNOVAC.csv
mv epidemicsincidence.csv results/epiIncNOVAC.csv


mpirun -np 4 ./covid.x 8 1 0.5 40 0.85 40
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


mpirun -np 4 ./covid.x 1 1 0.5 40 0.85 40
mv InfPrevalence.csv results/infPrevAZ.csv
mv epidemicsprevalence.csv results/epiPrevAZ.csv
mv InfIncidence.csv results/infIncAZ.csv
mv epidemicsincidence.csv results/epiIncAZ.csv


mpirun -np 4 ./covid.x 2 1 0.5 40 0.85 40
mv InfPrevalence.csv results/infPrevCV.csv
mv epidemicsprevalence.csv results/epiPrevCV.csv
mv InfIncidence.csv results/infIncCV.csv
mv epidemicsincidence.csv results/epiIncCV.csv


mpirun -np 4 ./covid.x 4 1 0.5 40 0.85 40
mv InfPrevalence.csv results/infPrevJJ.csv
mv epidemicsprevalence.csv results/epiPrevJJ.csv
mv InfIncidence.csv results/infIncJJ.csv
mv epidemicsincidence.csv results/epiIncJJ.csv


mpirun -np 4 ./covid.x 6 1 0.5 40 0.85 40
mv InfPrevalence.csv results/infPrevPF.csv
mv epidemicsprevalence.csv results/epiPrevPF.csv
mv InfIncidence.csv results/infIncPF.csv
mv epidemicsincidence.csv results/epiIncPF.csv


rm -rf iso40days/results50
mv results iso40days/results50


#########################
# iso .8

mkdir -p results

mpirun -np 4 ./covid.x 0 1 0.8 40 0.85 40
mv InfPrevalence.csv results/infPrevNOVAC.csv
mv epidemicsprevalence.csv results/epiPrevNOVAC.csv
mv InfIncidence.csv results/infIncNOVAC.csv
mv epidemicsincidence.csv results/epiIncNOVAC.csv


mpirun -np 4 ./covid.x 8 1 0.8 40 0.85 40
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


mpirun -np 4 ./covid.x 1 1 0.8 40 0.85 40
mv InfPrevalence.csv results/infPrevAZ.csv
mv epidemicsprevalence.csv results/epiPrevAZ.csv
mv InfIncidence.csv results/infIncAZ.csv
mv epidemicsincidence.csv results/epiIncAZ.csv


mpirun -np 4 ./covid.x 2 1 0.8 40 0.85 40
mv InfPrevalence.csv results/infPrevCV.csv
mv epidemicsprevalence.csv results/epiPrevCV.csv
mv InfIncidence.csv results/infIncCV.csv
mv epidemicsincidence.csv results/epiIncCV.csv


mpirun -np 4 ./covid.x 4 1 0.8 40 0.85 40
mv InfPrevalence.csv results/infPrevJJ.csv
mv epidemicsprevalence.csv results/epiPrevJJ.csv
mv InfIncidence.csv results/infIncJJ.csv
mv epidemicsincidence.csv results/epiIncJJ.csv


mpirun -np 4 ./covid.x 6 1 0.8 40 0.85 40
mv InfPrevalence.csv results/infPrevPF.csv
mv epidemicsprevalence.csv results/epiPrevPF.csv
mv InfIncidence.csv results/infIncPF.csv
mv epidemicsincidence.csv results/epiIncPF.csv


rm -rf iso40days/results80
mv results iso40days/results80


##########################
# iso .9

mkdir -p results


mpirun -np 4 ./covid.x 0 1 0.9 40 0.85 40
mv InfPrevalence.csv results/infPrevNOVAC.csv
mv epidemicsprevalence.csv results/epiPrevNOVAC.csv
mv InfIncidence.csv results/infIncNOVAC.csv
mv epidemicsincidence.csv results/epiIncNOVAC.csv


mpirun -np 4 ./covid.x 8 1 0.9 40 0.85 40
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


mpirun -np 4 ./covid.x 1 1 0.9 40 0.85 40
mv InfPrevalence.csv results/infPrevAZ.csv
mv epidemicsprevalence.csv results/epiPrevAZ.csv
mv InfIncidence.csv results/infIncAZ.csv
mv epidemicsincidence.csv results/epiIncAZ.csv


mpirun -np 4 ./covid.x 2 1 0.9 40 0.85 40
mv InfPrevalence.csv results/infPrevCV.csv
mv epidemicsprevalence.csv results/epiPrevCV.csv
mv InfIncidence.csv results/infIncCV.csv
mv epidemicsincidence.csv results/epiIncCV.csv


mpirun -np 4 ./covid.x 4 1 0.9 40 0.85 40
mv InfPrevalence.csv results/infPrevJJ.csv
mv epidemicsprevalence.csv results/epiPrevJJ.csv
mv InfIncidence.csv results/infIncJJ.csv
mv epidemicsincidence.csv results/epiIncJJ.csv


mpirun -np 4 ./covid.x 6 1 0.9 40 0.85 40
mv InfPrevalence.csv results/infPrevPF.csv
mv epidemicsprevalence.csv results/epiPrevPF.csv
mv InfIncidence.csv results/infIncPF.csv
mv epidemicsincidence.csv results/epiIncPF.csv


rm -rf iso40days/results90
mv results iso40days/results90


###################################################################################

mkdir -p data
mv iso0days iso20days iso40days data
