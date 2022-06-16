#### Vaccines used in Brazil

# mpirun -np (processes) ./covid.x (vaccine) (isolation) (proportionIsolated) (startOfIsolation) (percVaccination) (startOfVaccination)

# vaccines: 0 - No Vaccination; 1 - AstraZeneca; 2 - CoronaVac; 4 - Janssen; 6 - Pfizer; 8 - BR Vaccines

#######################################################################################

# 0 days to start interventions

#######################################################################################

make clean
make

mkdir -p results
mkdir -p BR0days/resultsNOISO
mkdir -p BR0days/results50
mkdir -p BR0days/results80
mkdir -p BR0days/results90
mkdir -p BR20days/resultsNOISO
mkdir -p BR20days/results50
mkdir -p BR20days/results80
mkdir -p BR20days/results90
mkdir -p BR40days/resultsNOISO
mkdir -p BR40days/results50
mkdir -p BR40days/results80
mkdir -p BR40days/results90

# iso 0
mpirun -np 8 ./covid.x 0 0 0.0 0 0.50 0
mv InfPrevalence.csv results/infPrevNOVAC.csv
mv epidemicsprevalence.csv results/epiPrevNOVAC.csv
mv InfIncidence.csv results/infIncNOVAC.csv
mv epidemicsincidence.csv results/epiIncNOVAC.csv


mpirun -np 8 ./covid.x 8 0 0.0 0 0.50 0
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv



rm -rf BR0days/resultsNOISO/v50
mv results BR0days/resultsNOISO/v50


mkdir -p results

mpirun -np 8 ./covid.x 8 0 0.0 0 0.75 0
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR0days/resultsNOISO/v75
mv results BR0days/resultsNOISO/v75

mkdir -p results

mpirun -np 8 ./covid.x 8 0 0.0 0 0.85 0
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR0days/resultsNOISO/v85
mv results BR0days/resultsNOISO/v85

mkdir -p results

mpirun -np 8 ./covid.x 8 0 0.0 0 0.95 0
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR0days/resultsNOISO/v95
mv results BR0days/resultsNOISO/v95

############################ 
# iso .5

mkdir -p results

mpirun -np 8 ./covid.x 0 1 0.5 0 0.50 0
mv InfPrevalence.csv results/infPrevNOVAC.csv
mv epidemicsprevalence.csv results/epiPrevNOVAC.csv
mv InfIncidence.csv results/infIncNOVAC.csv
mv epidemicsincidence.csv results/epiIncNOVAC.csv


mpirun -np 8 ./covid.x 8 1 0.5 0 0.50 0
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR0days/results50/v50
mv results BR0days/results50/v50


mkdir -p results


mpirun -np 8 ./covid.x 8 1 0.5 0 0.75 0
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR0days/results50/v75
mv results BR0days/results50/v75

mkdir -p results


mpirun -np 8 ./covid.x 8 1 0.5 0 0.85 0
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR0days/results50/v85
mv results BR0days/results50/v85

mkdir -p results

mpirun -np 8 ./covid.x 8 1 0.5 0 0.95 0
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR0days/results50/v95
mv results BR0days/results50/v95


############################ 
# iso .8

mkdir -p results

mpirun -np 8 ./covid.x 0 1 0.8 0 0.50 0
mv InfPrevalence.csv results/infPrevNOVAC.csv
mv epidemicsprevalence.csv results/epiPrevNOVAC.csv
mv InfIncidence.csv results/infIncNOVAC.csv
mv epidemicsincidence.csv results/epiIncNOVAC.csv


mpirun -np 8 ./covid.x 8 1 0.8 0 0.50 0
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR0days/results80/v50
mv results BR0days/results80/v50


mkdir -p results

mpirun -np 8 ./covid.x 8 1 0.8 0 0.75 0
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR0days/results80/v75
mv results BR0days/results80/v75

mkdir -p results


mpirun -np 8 ./covid.x 8 1 0.8 0 0.85 0
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR0days/results80/v85
mv results BR0days/results80/v85

mkdir -p results


mpirun -np 8 ./covid.x 8 1 0.8 0 0.95 0
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR0days/results80/v95
mv results BR0days/results80/v95


############################ 
# iso .9

mkdir -p results

mpirun -np 8 ./covid.x 0 1 0.9 0 0.50 0
mv InfPrevalence.csv results/infPrevNOVAC.csv
mv epidemicsprevalence.csv results/epiPrevNOVAC.csv
mv InfIncidence.csv results/infIncNOVAC.csv
mv epidemicsincidence.csv results/epiIncNOVAC.csv


mpirun -np 8 ./covid.x 8 1 0.9 0 0.50 0
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR0days/results90/v50
mv results BR0days/results90/v50


mkdir -p results

mpirun -np 8 ./covid.x 8 1 0.9 0 0.75 0
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR0days/results90/v75
mv results BR0days/results90/v75

mkdir -p results


mpirun -np 8 ./covid.x 8 1 0.9 0 0.85 0
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR0days/results90/v85
mv results BR0days/results90/v85

mkdir -p results


mpirun -np 8 ./covid.x 8 1 0.9 0 0.95 0
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR0days/results90/v95
mv results BR0days/results90/v95


#######################################################################################

# 20 days to start interventions

#######################################################################################
# iso 0
mkdir -p results

mpirun -np 8 ./covid.x 0 0 0.0 20 0.50 20
mv InfPrevalence.csv results/infPrevNOVAC.csv
mv epidemicsprevalence.csv results/epiPrevNOVAC.csv
mv InfIncidence.csv results/infIncNOVAC.csv
mv epidemicsincidence.csv results/epiIncNOVAC.csv


mpirun -np 8 ./covid.x 8 0 0.0 20 0.50 20
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv



rm -rf BR20days/resultsNOISO/v50
mv results BR20days/resultsNOISO/v50


mkdir -p results

mpirun -np 8 ./covid.x 8 0 0.0 20 0.75 20
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR20days/resultsNOISO/v75
mv results BR20days/resultsNOISO/v75

mkdir -p results

mpirun -np 8 ./covid.x 8 0 0.0 20 0.85 20
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR20days/resultsNOISO/v85
mv results BR20days/resultsNOISO/v85

mkdir -p results

mpirun -np 8 ./covid.x 8 0 0.0 20 0.95 20
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR20days/resultsNOISO/v95
mv results BR20days/resultsNOISO/v95

############################ 
# iso .5
mkdir -p results

mpirun -np 8 ./covid.x 0 1 0.5 20 0.50 20
mv InfPrevalence.csv results/infPrevNOVAC.csv
mv epidemicsprevalence.csv results/epiPrevNOVAC.csv
mv InfIncidence.csv results/infIncNOVAC.csv
mv epidemicsincidence.csv results/epiIncNOVAC.csv


mpirun -np 8 ./covid.x 8 1 0.5 20 0.50 20
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR20days/results50/v50
mv results BR20days/results50/v50


mkdir -p results


mpirun -np 8 ./covid.x 8 1 0.5 20 0.75 20
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR20days/results50/v75
mv results BR20days/results50/v75

mkdir -p results


mpirun -np 8 ./covid.x 8 1 0.5 20 0.85 20
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR20days/results50/v85
mv results BR20days/results50/v85

mkdir -p results

mpirun -np 8 ./covid.x 8 1 0.5 20 0.95 20
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR20days/results50/v95
mv results BR20days/results50/v95


############################ 
# iso .8

mkdir -p results

mpirun -np 8 ./covid.x 0 1 0.8 20 0.50 20
mv InfPrevalence.csv results/infPrevNOVAC.csv
mv epidemicsprevalence.csv results/epiPrevNOVAC.csv
mv InfIncidence.csv results/infIncNOVAC.csv
mv epidemicsincidence.csv results/epiIncNOVAC.csv


mpirun -np 8 ./covid.x 8 1 0.8 20 0.50 20
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR20days/results80/v50
mv results BR20days/results80/v50


mkdir -p results

mpirun -np 8 ./covid.x 8 1 0.8 20 0.75 20
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR20days/results80/v75
mv results BR20days/results80/v75

mkdir -p results


mpirun -np 8 ./covid.x 8 1 0.8 20 0.85 20
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR20days/results80/v85
mv results BR20days/results80/v85

mkdir -p results


mpirun -np 8 ./covid.x 8 1 0.8 20 0.95 20
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR20days/results80/v95
mv results BR20days/results80/v95


############################ 
# iso .9

mkdir -p results

mpirun -np 8 ./covid.x 0 1 0.9 20 0.50 20
mv InfPrevalence.csv results/infPrevNOVAC.csv
mv epidemicsprevalence.csv results/epiPrevNOVAC.csv
mv InfIncidence.csv results/infIncNOVAC.csv
mv epidemicsincidence.csv results/epiIncNOVAC.csv


mpirun -np 8 ./covid.x 8 1 0.9 20 0.50 20
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR20days/results90/v50
mv results BR20days/results90/v50


mkdir -p results

mpirun -np 8 ./covid.x 8 1 0.9 20 0.75 20
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR20days/results90/v75
mv results BR20days/results90/v75

mkdir -p results


mpirun -np 8 ./covid.x 8 1 0.9 20 0.85 20
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR20days/results90/v85
mv results BR20days/results90/v85

mkdir -p results


mpirun -np 8 ./covid.x 8 1 0.9 20 0.95 20
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR20days/results90/v95
mv results BR20days/results90/v95


#######################################################################################

# 40 days to start interventions

#######################################################################################
# iso 0
mkdir -p results

mpirun -np 8 ./covid.x 0 0 0.0 40 0.50 40
mv InfPrevalence.csv results/infPrevNOVAC.csv
mv epidemicsprevalence.csv results/epiPrevNOVAC.csv
mv InfIncidence.csv results/infIncNOVAC.csv
mv epidemicsincidence.csv results/epiIncNOVAC.csv


mpirun -np 8 ./covid.x 8 0 0.0 40 0.50 40
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv



rm -rf BR40days/resultsNOISO/v50
mv results BR40days/resultsNOISO/v50


mkdir -p results

mpirun -np 8 ./covid.x 8 0 0.0 40 0.75 40
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR40days/resultsNOISO/v75
mv results BR40days/resultsNOISO/v75

mkdir -p results

mpirun -np 8 ./covid.x 8 0 0.0 40 0.85 40
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR40days/resultsNOISO/v85
mv results BR40days/resultsNOISO/v85

mkdir -p results

mpirun -np 8 ./covid.x 8 0 0.0 40 0.95 40
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR40days/resultsNOISO/v95
mv results BR40days/resultsNOISO/v95

############################ 
# iso .5
mkdir -p results

mpirun -np 8 ./covid.x 0 1 0.5 40 0.50 40
mv InfPrevalence.csv results/infPrevNOVAC.csv
mv epidemicsprevalence.csv results/epiPrevNOVAC.csv
mv InfIncidence.csv results/infIncNOVAC.csv
mv epidemicsincidence.csv results/epiIncNOVAC.csv


mpirun -np 8 ./covid.x 8 1 0.5 40 0.50 40
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR40days/results50/v50
mv results BR40days/results50/v50


mkdir -p results


mpirun -np 8 ./covid.x 8 1 0.5 40 0.75 40
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR40days/results50/v75
mv results BR40days/results50/v75

mkdir -p results


mpirun -np 8 ./covid.x 8 1 0.5 40 0.85 40
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR40days/results50/v85
mv results BR40days/results50/v85

mkdir -p results

mpirun -np 8 ./covid.x 8 1 0.5 40 0.95 40
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR40days/results50/v95
mv results BR40days/results50/v95


############################ 
# iso .8

mkdir -p results

mpirun -np 8 ./covid.x 0 1 0.8 40 0.50 40
mv InfPrevalence.csv results/infPrevNOVAC.csv
mv epidemicsprevalence.csv results/epiPrevNOVAC.csv
mv InfIncidence.csv results/infIncNOVAC.csv
mv epidemicsincidence.csv results/epiIncNOVAC.csv


mpirun -np 8 ./covid.x 8 1 0.8 40 0.50 40
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR40days/results80/v50
mv results BR40days/results80/v50


mkdir -p results

mpirun -np 8 ./covid.x 8 1 0.8 40 0.75 40
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR40days/results80/v75
mv results BR40days/results80/v75

mkdir -p results


mpirun -np 8 ./covid.x 8 1 0.8 40 0.85 40
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR40days/results80/v85
mv results BR40days/results80/v85

mkdir -p results


mpirun -np 8 ./covid.x 8 1 0.8 40 0.95 40
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR40days/results80/v95
mv results BR40days/results80/v95


############################ 
# iso .9

mkdir -p results

mpirun -np 8 ./covid.x 0 1 0.9 40 0.50 40
mv InfPrevalence.csv results/infPrevNOVAC.csv
mv epidemicsprevalence.csv results/epiPrevNOVAC.csv
mv InfIncidence.csv results/infIncNOVAC.csv
mv epidemicsincidence.csv results/epiIncNOVAC.csv


mpirun -np 8 ./covid.x 8 1 0.9 40 0.50 40
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR40days/results90/v50
mv results BR40days/results90/v50


mkdir -p results

mpirun -np 8 ./covid.x 8 1 0.9 40 0.75 40
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR40days/results90/v75
mv results BR40days/results90/v75

mkdir -p results


mpirun -np 8 ./covid.x 8 1 0.9 40 0.85 40
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR40days/results90/v85
mv results BR40days/results90/v85

mkdir -p results


mpirun -np 8 ./covid.x 8 1 0.9 40 0.95 40
mv InfPrevalence.csv results/infPrevBR.csv
mv epidemicsprevalence.csv results/epiPrevBR.csv
mv InfIncidence.csv results/infIncBR.csv
mv epidemicsincidence.csv results/epiIncBR.csv


rm -rf BR40days/results90/v95
mv results BR40days/results90/v95


###################################################################################

mkdir -p data
mv BR0days BR20days BR40days data
