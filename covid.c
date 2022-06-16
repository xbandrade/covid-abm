#include <stdio.h>
#include <math.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>
#include "files/define.h"
#include "files/vaccines.h"

int IsolationState;        // 0 - off, 1 - on 
int StartOfIsolation;      // days
int StartOfVaccination;     // days
double ProportionIsolated; // %
double PercVaccination;   // %


int availableVac; // available vaccines

struct Individual
{
	int Health;        // host health state
	int Swap;          // host health state  to update lattice
	int Gender;
	int AgeYears;
	int AgeDays;
	int AgeDeathYears;  
	int AgeDeathDays;	//
	int StateTime;  	// 	
	int TimeOnState;	//
	int Days;
	int Isolation;
	int Exponent;       // in case they met an infectous person
	int Checked;
	int IsVaccinated;   // 0 -> not vaccinated
}Person[L+2][L+2];

char nome[30];

/* Data files */					  
FILE *fp;
FILE *gp;
FILE *hp;
FILE *ip;
FILE *jp;

FILE *rawincidence;
FILE *rawprevalence;

double *p;

 
int S_Total;
int E_Total;               
int IP_Total;               
int IA_Total;               
int ISLight_Total;
int ISModerate_Total;    
int ISSevere_Total;                
int H_Total;                  
int ICU_Total;            
int Recovered_Total;       
int DeadCovid_Total;       
int Dead_Total;           
int Vac_Total;             

int New_S;
int New_E;               
int New_IP;               
int New_IA;              
int New_ISLight;   
int New_ISModerate;   
int New_ISSevere;   
int New_H;             
int New_ICU;            
int New_Recovered;       
int New_DeadCovid;       
int New_Dead;        
int New_Vac;      
                     
/*********************************/

double S_TotalTemp[MAXSIM+2][DAYS+2]; 
double E_TotalTemp[MAXSIM+2][DAYS+2];                
double IP_TotalTemp[MAXSIM+2][DAYS+2];                
double IA_TotalTemp[MAXSIM+2][DAYS+2];                
double ISLight_TotalTemp[MAXSIM+2][DAYS+2];    
double ISModerate_TotalTemp[MAXSIM+2][DAYS+2];   
double ISSevere_TotalTemp[MAXSIM+2][DAYS+2];            
double H_TotalTemp[MAXSIM+2][DAYS+2];                    
double ICU_TotalTemp[MAXSIM+2][DAYS+2];             
double Recovered_TotalTemp[MAXSIM+2][DAYS+2];        
double DeadCovid_TotalTemp[MAXSIM+2][DAYS+2];        
double Dead_TotalTemp[MAXSIM+2][DAYS+2];    
double Vac_TotalTemp[MAXSIM+2][DAYS+2];           
      

double S_Mean[DAYS+2];
double E_Mean[DAYS+2];               
double IP_Mean[DAYS+2];               
double IA_Mean[DAYS+2];               
double ISLight_Mean[DAYS+2];   
double ISModerate_Mean[DAYS+2];   
double ISSevere_Mean[DAYS+2];            
double H_Mean[DAYS+2];                   
double ICU_Mean[DAYS+2];            
double Recovered_Mean[DAYS+2];       
double DeadCovid_Mean[DAYS+2];       
double Dead_Mean[DAYS+2];           
double Vac_Mean[DAYS+2];            


double New_S_Temp[MAXSIM+2][DAYS+2]; 
double New_E_Temp[MAXSIM+2][DAYS+2];                
double New_IP_Temp[MAXSIM+2][DAYS+2];                
double New_IA_Temp[MAXSIM+2][DAYS+2];                
double New_ISLight_Temp[MAXSIM+2][DAYS+2];  
double New_ISModerate_Temp[MAXSIM+2][DAYS+2];  
double New_ISSevere_Temp[MAXSIM+2][DAYS+2];             
double New_H_Temp[MAXSIM+2][DAYS+2];                    
double New_ICU_Temp[MAXSIM+2][DAYS+2];             
double New_Recovered_Temp[MAXSIM+2][DAYS+2];        
double New_DeadCovid_Temp[MAXSIM+2][DAYS+2];        
double New_Dead_Temp[MAXSIM+2][DAYS+2];          
double New_Vac_Temp[MAXSIM+2][DAYS+2];              


double New_S_Mean[DAYS+2];
double New_E_Mean[DAYS+2];               
double New_IP_Mean[DAYS+2];               
double New_IA_Mean[DAYS+2];               
double New_ISLight_Mean[DAYS+2];     
double New_ISModerate_Mean[DAYS+2];     
double New_ISSevere_Mean[DAYS+2];            
double New_H_Mean[DAYS+2];                   
double New_ICU_Mean[DAYS+2];            
double New_Recovered_Mean[DAYS+2];       
double New_DeadCovid_Mean[DAYS+2];       
double New_Dead_Mean[DAYS+2];       
double New_Vac_Mean[DAYS+2];       


// Final sums
double S_Sum[DAYS+2];
double E_Sum[DAYS+2];              
double IP_Sum[DAYS+2];               
double IA_Sum[DAYS+2];               
double ISLight_Sum[DAYS+2];  
double ISModerate_Sum[DAYS+2]; 
double ISSevere_Sum[DAYS+2];           
double H_Sum[DAYS+2];                   
double ICU_Sum[DAYS+2];            
double Recovered_Sum[DAYS+2];       
double DeadCovid_Sum[DAYS+2];       
double Dead_Sum[DAYS+2];           
double Vac_Sum[DAYS+2];         


double New_S_Sum[DAYS+2];
double New_E_Sum[DAYS+2];               
double New_IP_Sum[DAYS+2];               
double New_IA_Sum[DAYS+2];               
double New_ISLight_Sum[DAYS+2];  
double New_ISModerate_Sum[DAYS+2];  
double New_ISSevere_Sum[DAYS+2];            
double New_H_Sum[DAYS+2];                   
double New_ICU_Sum[DAYS+2];            
double New_Recovered_Sum[DAYS+2];       
double New_DeadCovid_Sum[DAYS+2];       
double New_Dead_Sum[DAYS+2];        
double New_Vac_Sum[DAYS+2];        


// Sums for MPI Reduce
double MS_Sum[DAYS+2];
double ME_Sum[DAYS+2];              
double MIP_Sum[DAYS+2];               
double MIA_Sum[DAYS+2];               
double MISLight_Sum[DAYS+2];  
double MISModerate_Sum[DAYS+2]; 
double MISSevere_Sum[DAYS+2];           
double MH_Sum[DAYS+2];                   
double MICU_Sum[DAYS+2];            
double MRecovered_Sum[DAYS+2];       
double MDeadCovid_Sum[DAYS+2];       
double MDead_Sum[DAYS+2];         
double MVac_Sum[DAYS+2];         


double MNew_S_Sum[DAYS+2];
double MNew_E_Sum[DAYS+2];               
double MNew_IP_Sum[DAYS+2];               
double MNew_IA_Sum[DAYS+2];               
double MNew_ISLight_Sum[DAYS+2];  
double MNew_ISModerate_Sum[DAYS+2];  
double MNew_ISSevere_Sum[DAYS+2];            
double MNew_H_Sum[DAYS+2];                   
double MNew_ICU_Sum[DAYS+2];            
double MNew_Recovered_Sum[DAYS+2];       
double MNew_DeadCovid_Sum[DAYS+2];       
double MNew_Dead_Sum[DAYS+2];         
double MNew_Vac_Sum[DAYS+2];        


double ProbNaturalDeath[121];
double ProbBirthAge[21];
double SumProbBirthAge[21];

double ProbRecoveryModerate[121];
double ProbRecoverySevere[121];
double ProbRecoveryH[121];
double ProbRecoveryICU[121];

int AgeMin[21];
int AgeMax[21];

int timesim;
int Simulation;
int CountDays;
int Contagion;  

unsigned R;
unsigned mult;

double rn;

double CurrentIsolated;
double MAXISOLATED;

char cad[35];

double TotalInfectious;
double TotalInfectiousNew;

int AvailableBeds;
int AvailableBedsICU;

int MaximumIsolated;
int CountIsolated;

double valueR0;

int vaccineAgeMin;
int vaccineAgeMax;

double MaxRandomContacts;
double MinRandomContacts;

int NumberOfHospitalBeds;
int NumberOfICUBeds;

char nomeincidence[30];
char nomeprevalence[30];

//////////////////////////////////////////////////////////

double *calcProb(double MaxRandomContacts) // 
{
	int k, n;
	n = 9 + (int)MaxRandomContacts;   // max infectious neighbors + max random contacts rounded up = 8 + MaxRandomContacts + 1
	p = malloc(n*sizeof(double));     // 
	for(k=0;k<n;k++)                  //
		p[k] = 1.0 - pow(1.0 - Beta,(double)k);
	//return p;
}

double aleat()
{
    R*= mult;
    rn = (double)R/MAXNUM;    /* gerenerate random number [0.0,1.0] */
}


#include "files/vaccination.h"
#include "files/begin.h"
#include "files/death.h"
#include "files/agestructure.h"
#include "files/probsrecovery.h"
#include "files/Neighbors.h"
#include "files/Neighborsinfected.h"
#include "files/S.h"
#include "files/E.h"                                                              
#include "files/IP.h"    
#include "files/IS.h"    
#include "files/H.h"                                           
#include "files/ICU.h"
#include "files/isolation.h"
#include "files/Update.h"

/////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    int i, j, t, tag=1;
    int seed, master, ierr, size, rank;
	int start, end, step;
	double t1, t2;
	int maxsim;
	int vaccination = 0; // 0 - no vaccination
	int vaccine;
	int count;
    
    gp = fopen("parameters.out","w");
    fp = fopen("epidemicsprevalence.csv", "w");
    ip = fopen("epidemicsincidence.csv", "w");
    hp = fopen("InfPrevalence.csv","w");
    jp = fopen("InfIncidence.csv","w");
    
  	// R = 893221891;
    
    mult = 888121;  // for 32 bits compilers

    MPI_Status rstatus; // 
    ierr = MPI_Init(&argc, &argv);
    ierr = MPI_Comm_size(MPI_COMM_WORLD, &size);
    ierr = MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
    
	t1 = MPI_Wtime(); // 

	vaccine = atoi(argv[1]); // gets vaccine from command line arguments
	IsolationState = atoi(argv[2]);
	ProportionIsolated = atof(argv[3]);
	StartOfIsolation = atoi(argv[4]);
	PercVaccination = atof(argv[5]);
	StartOfVaccination = atoi(argv[6]);
	

	availableVac = PercVaccination*N;

	master = 0;
    seed = 2;
    seed *= rank + 2; // random seed for each process
    

	if(rank==master)
	{
		printf("\n\n****Running in parallel with %d processes****\n", size);
		printf("Population Density: %s\n", Density == HIGH ? "High" : "Low");
		if(vaccine!=0)
		{
			printf("Begin of Vaccination: %d days\n", StartOfVaccination);
			printf("Proportion Vaccinated: %f \n", PercVaccination);

		}
		if(IsolationState==ON)
		{
			printf("Begin of Isolation: %d days\n", StartOfIsolation);
			printf("Proportion Isolated: %f \n", ProportionIsolated);
		}
		else
			puts("No Isolation");
		switch(vaccine)
		{
			case 0:
				printf("No vaccination\n\n");
				break;
			case 1:
				printf("Vaccine: AstraZeneca\n\n");
				break;
			case 2:
				printf("Vaccine: CoronaVac\n\n");
				break;
			case 3:
				printf("Vaccine: Covaxin\n\n");
				break;
			case 4:
				printf("Vaccine: Janssen\n\n");
				break;
			case 5:
				printf("Vaccine: Moderna\n\n");
				break;
			case 6:
				printf("Vaccine: Pfizer\n\n");
				break;
			case 7:
				printf("Vaccine: Sinopharm\n\n");
				break;
			case 8:
				printf("Vaccines used in Brazil\n\n");
				break;
			default:
				printf("Incorrect vaccine argument\n\n");
				exit(1);
		}
		printf("Simulations: %d\n", MAXSIM);
	}
	
    MPI_Barrier(MPI_COMM_WORLD);
    Agestructure(); 
    NaturalDeathfunc(); // call the values for natural death probability
    ProbsRecovery();
       
	for(t=0;t<=DAYS;t++)
	{ 
		S_Sum[t]          = 0.0;
		E_Sum[t]          = 0.0;               
		IP_Sum[t]         = 0.0;               
		IA_Sum[t]         = 0.0;               
		ISLight_Sum[t]    = 0.0;  
		ISModerate_Sum[t] = 0.0;  
		ISSevere_Sum[t]   = 0.0;            
		H_Sum[t]          = 0.0;                
		ICU_Sum[t]        = 0.0;            
		Recovered_Sum[t]  = 0.0;       
		DeadCovid_Sum[t]  = 0.0;       
		Dead_Sum[t]       = 0.0;      
		Vac_Sum[t]        = 0.0;             

		New_S_Sum[t]          = 0.0;
		New_E_Sum[t]          = 0.0;               
		New_IP_Sum[t]         = 0.0;               
		New_IA_Sum[t]         = 0.0;               
		New_ISLight_Sum[t]    = 0.0;  
		New_ISModerate_Sum[t] = 0.0;  
		New_ISSevere_Sum[t]   = 0.0;            
		New_H_Sum[t]          = 0.0;                
		New_ICU_Sum[t]        = 0.0;            
		New_Recovered_Sum[t]  = 0.0;       
		New_DeadCovid_Sum[t]  = 0.0;       
		New_Dead_Sum[t]       = 0.0;      
		New_Vac_Sum[t]        = 0.0;               	
	}
    
	if(rank == master)
		for(t=0;t<=DAYS;t++)
		{ 
			MS_Sum[t]          = 0.0;
			ME_Sum[t]          = 0.0;               
			MIP_Sum[t]         = 0.0;               
			MIA_Sum[t]         = 0.0;               
			MISLight_Sum[t]    = 0.0;  
			MISModerate_Sum[t] = 0.0;  
			MISSevere_Sum[t]   = 0.0;            
			MH_Sum[t]          = 0.0;                 
			MICU_Sum[t]        = 0.0;            
			MRecovered_Sum[t]  = 0.0;       
			MDeadCovid_Sum[t]  = 0.0;       
			MDead_Sum[t]       = 0.0;       
			MVac_Sum[t]        = 0.0;             

			MNew_S_Sum[t]          = 0.0;
			MNew_E_Sum[t]          = 0.0;               
			MNew_IP_Sum[t]         = 0.0;               
			MNew_IA_Sum[t]         = 0.0;               
			MNew_ISLight_Sum[t]    = 0.0;  
			MNew_ISModerate_Sum[t] = 0.0;  
			MNew_ISSevere_Sum[t]   = 0.0;            
			MNew_H_Sum[t]          = 0.0;               
			MNew_ICU_Sum[t]        = 0.0;            
			MNew_Recovered_Sum[t]  = 0.0;       
			MNew_DeadCovid_Sum[t]  = 0.0;       
			MNew_Dead_Sum[t]       = 0.0;       
			MNew_Vac_Sum[t]        = 0.0;               	
		}

	#if(Density==LOW) // low demographic density
	{
		//printf("LOW demographic density\n");
		
		MaxRandomContacts = 2.5;
		MinRandomContacts = 2.5;
		
		NumberOfHospitalBeds = 716;  
		NumberOfICUBeds      = 66;
	}
	#elif(Density==HIGH)
	{
		//printf("HIGH demographic density\n");
		
		MaxRandomContacts = 120.5;
		MinRandomContacts = 2.5;
		
		NumberOfHospitalBeds = 38;  
		NumberOfICUBeds      = 10;
	}
	#else // Density == BRAZIL
	{
		// https://www.gove.digital/wp-content/uploads/2020/03/Leitos.pdf
		MaxRandomContacts = 5.0;
		MinRandomContacts = 2.5;
		
		NumberOfHospitalBeds = 836;  
		NumberOfICUBeds      = 69;
	}
	#endif

	/*
	#if(StartOfIsolation==NO)
		MaximumIsolated = ProportionIsolated*N;	
	#else
		MaximumIsolated = 0;
	#endif	*/

	if(IsolationState==ON)
		MaximumIsolated = ProportionIsolated*N;	
	else
		MaximumIsolated = 0;

	//if(rank == master)
	//	calcProb(MaxRandomContacts);
	//MPI_Bcast(&p, 9 + (int)MaxRandomContacts, MPI_DOUBLE, master, MPI_COMM_WORLD); // broadcasts array p to everyone

	//step = size == 1 ? 1 : MAXSIM/size;
	start = 1 + rank;
	end = start + MAXSIM - size;

	for(Simulation=start; Simulation<=end; Simulation+=size)
    {
		seed = Simulation+2*rank;
		R = 893221891*seed*10000;
		
		/*
		if(rank == 1)
			printf("Sim %d started - seed = %d - R = %u\n", Simulation, seed, R);
		*/
		
		//printf("Rank %d - Sim %d - R = %u\n", rank, Simulation, R);
		beginfunc(vaccine);
		CountDays = 0;

		/**** RAW FILES  ****
		sprintf(nomeincidence,"output/incidence_%i.csv", Simulation);
		rawincidence = fopen(nomeincidence,"a+");
		fprintf(rawincidence,"%d,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf\n",CountDays,New_S_Temp[Simulation][CountDays],New_E_Temp[Simulation][CountDays],New_IP_Temp[Simulation][CountDays],
		New_IA_Temp[Simulation][CountDays],New_ISLight_Temp[Simulation][CountDays],New_ISModerate_Temp[Simulation][CountDays],New_ISSevere_Temp[Simulation][CountDays],New_H_Temp[Simulation][CountDays],
		New_ICU_Temp[Simulation][CountDays],New_Recovered_Temp[Simulation][CountDays],New_DeadCovid_Temp[Simulation][CountDays],New_Vac_Temp[Simulation][CountDays]);           
		fclose(rawincidence);   
	
		sprintf(nomeprevalence,"output/prevalence_%i.csv", Simulation);
		rawprevalence = fopen(nomeprevalence,"a+");
		fprintf(rawprevalence,"%d,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf\n",CountDays,S_TotalTemp[Simulation][CountDays],E_TotalTemp[Simulation][CountDays],IP_TotalTemp[Simulation][CountDays],
		IA_TotalTemp[Simulation][CountDays],ISLight_TotalTemp[Simulation][CountDays],ISModerate_TotalTemp[Simulation][CountDays],ISSevere_TotalTemp[Simulation][CountDays],H_TotalTemp[Simulation][CountDays],
		ICU_TotalTemp[Simulation][CountDays],Recovered_TotalTemp[Simulation][CountDays],DeadCovid_TotalTemp[Simulation][CountDays],Vac_TotalTemp[Simulation][CountDays]);           
		fclose(rawprevalence); 
		
		************************************************/

		AvailableBeds = NumberOfHospitalBeds - NumberOfHospitalBeds*AverageOcupationRateBeds; // Considering beds occupied due to other diseases	
		AvailableBedsICU = NumberOfICUBeds - NumberOfICUBeds*AverageOcupationRateBedsICU;
	
		// before vaccination
		for(timesim=0; timesim<StartOfVaccination; timesim++)  
		{  
			for(i=1;i<=L;i++) /* Periodic boudandry conditions */
			{
				Person[0][i].Health   = Person[L][i].Health;
				Person[L+1][i].Health = Person[1][i].Health;
				Person[i][0].Health   = Person[i][L].Health;
				Person[i][L+1].Health = Person[i][1].Health;
			}
			
			Person[0][0].Health     = Person[L][L].Health;  /* Periodic boudandry conditions in the borders */
			Person[0][L+1].Health   = Person[L][1].Health;
			Person[L+1][0].Health   = Person[1][L].Health;
			Person[L+1][L+1].Health = Person[1][1].Health;
		
			for(i=1;i<=L;i++)
				for(j=1;j<=L;j++)
				{
					if(Person[i][j].Health==S)
						Sfunc(i, j);
					else if(Person[i][j].Health==E)
						Efunc(i, j);
					else if(Person[i][j].Health==IP)
						IPfunc(i, j);
					else if(Person[i][j].Health==IA || Person[i][j].Health==ISLight || Person[i][j].Health==ISModerate || Person[i][j].Health==ISSevere)
						ISfunc(i, j);
					else if(Person[i][j].Health==H)
						Hfunc(i, j);
					else if(Person[i][j].Health==ICU)
						ICUfunc(i, j);
					else if(Person[i][j].Health==Recovered)
						Person[i][j].Swap = Recovered;
				}

			//if(timesim == 150 || timesim == 300)
			//	printf("\n%d - Rank %d - day %d", Simulation, rank, timesim);
			//if(rank==master)
			//	printf("dia %d\n", timesim);
			Updatefunc();   /* Update lattice */
		} // for time

		vaccineAgeMax = 121;
		vaccineAgeMin = 90;
		count = 1;

		// Everyone is vaccinated at once
		/*vaccineAgeMin = 95;
		  for(i=1;i<=L;i++)
			for(j=1;j<=L;j++)
				if(vaccine!=0 && Person[i][j].AgeYears>=vaccineAgeMin && Person[i][j].IsVaccinated==0) // not vaccinated yet
					if(Person[i][j].Health==S || Person[i][j].Health==E) // susceptible and latent can be vaccinated
						Vaccination(i, j, vaccine);*/

		// vaccination
		for(timesim=StartOfVaccination; timesim<=DAYS; timesim++)  
		{  
			for(i=1;i<=L;i++) /* Periodic boudandry conditions */
			{
				Person[0][i].Health   = Person[L][i].Health;
				Person[L+1][i].Health = Person[1][i].Health;
				Person[i][0].Health   = Person[i][L].Health;
				Person[i][L+1].Health = Person[i][1].Health;
			}
			
			Person[0][0].Health     = Person[L][L].Health;  /* Periodic boundary conditions in the borders */
			Person[0][L+1].Health   = Person[L][1].Health;
			Person[L+1][0].Health   = Person[1][L].Health;
			Person[L+1][L+1].Health = Person[1][1].Health;
		
			for(i=1;i<=L;i++)
				for(j=1;j<=L;j++)
				{
					if(vaccine!=0 && Person[i][j].AgeYears>=vaccineAgeMin && Person[i][j].AgeYears<vaccineAgeMax && Person[i][j].IsVaccinated==0) // not vaccinated yet
						if(Person[i][j].Health==S || Person[i][j].Health==E || Person[i][j].Health==Recovered) // susceptible and latent can be vaccinated
							Vaccination(i, j, vaccine, 0);
					if(Person[i][j].Health==S)
						Sfunc(i,j);
					else if(Person[i][j].Health==E)
						Efunc(i,j);
					else if(Person[i][j].Health==IP)
						IPfunc(i,j);
					else if(Person[i][j].Health==IA || Person[i][j].Health==ISLight || Person[i][j].Health==ISModerate || Person[i][j].Health==ISSevere)
						ISfunc(i,j);
					else if(Person[i][j].Health==H)
						Hfunc(i,j);
					else if(Person[i][j].Health==ICU)
						ICUfunc(i,j);
					else if(Person[i][j].Health==Recovered)
						Person[i][j].Swap = Recovered;
				}
			if(count<DAYS_LOWER_AGE) // days to lower min age for vaccination
				count++;
			else
			{
				if(vaccineAgeMin>VACCINE_AGE_MIN) 
				{
					vaccineAgeMax = vaccineAgeMin;
					vaccineAgeMin -= LOWER_MIN_AGE;
					count = 1;
				}
				else
				{
					vaccineAgeMax = VACCINE_AGE_MIN+1;
					vaccineAgeMin = VACCINE_AGE_MIN;
				}
			}
			Updatefunc();   /* Update lattice */
			//if(rank==master)
				//printf("S TOTAL = %d\n", S_Total);
		} // for time
		printf(">Rank %d - Sim %d done\n", rank, Simulation);
    } // for simulation
    

	// Prevalence headers
	fprintf(hp, "Time,PreSymptomatic,Asymptomatic,Light,Moderate,Severe,Total\n");
	fprintf(fp, "Time,Susceptible,Exposed,InfPresymptomatic,InfAsymptomatic,Infectious,Hospitalized,ICU,Recovered,CovidDead,Vaccinated\n");

	// Incidence headers
	fprintf(jp, "Time,NewPreSymptomatic,NewAsymptomatic,NewLight,NewModerate,NewSevere,NewTotal\n"); 
	fprintf(ip, "Time,NewSusceptible,NewExposed,NewInfPresymptomatic,NewInfAsymptomatic,NewInfectious,NewHospitalized,NewICU,NewRecovered,NewCovidDead,NewVaccinated\n");

	// Reduces all sums
	MPI_Reduce(S_Sum, MS_Sum, DAYS+2, MPI_DOUBLE, MPI_SUM, master, MPI_COMM_WORLD);
	MPI_Reduce(E_Sum, ME_Sum, DAYS+2, MPI_DOUBLE, MPI_SUM, master, MPI_COMM_WORLD);
	MPI_Reduce(IP_Sum, MIP_Sum, DAYS+2, MPI_DOUBLE, MPI_SUM, master, MPI_COMM_WORLD);
	MPI_Reduce(IA_Sum, MIA_Sum, DAYS+2, MPI_DOUBLE, MPI_SUM, master, MPI_COMM_WORLD);
	MPI_Reduce(ISLight_Sum, MISLight_Sum, DAYS+2, MPI_DOUBLE, MPI_SUM, master, MPI_COMM_WORLD);
	MPI_Reduce(ISModerate_Sum, MISModerate_Sum, DAYS+2, MPI_DOUBLE, MPI_SUM, master, MPI_COMM_WORLD);
	MPI_Reduce(ISSevere_Sum, MISSevere_Sum, DAYS+2, MPI_DOUBLE, MPI_SUM, master, MPI_COMM_WORLD);
	MPI_Reduce(H_Sum, MH_Sum, DAYS+2, MPI_DOUBLE, MPI_SUM, master, MPI_COMM_WORLD);
	MPI_Reduce(Recovered_Sum, MRecovered_Sum, DAYS+2, MPI_DOUBLE, MPI_SUM, master, MPI_COMM_WORLD);
	MPI_Reduce(DeadCovid_Sum, MDeadCovid_Sum, DAYS+2, MPI_DOUBLE, MPI_SUM, master, MPI_COMM_WORLD);
	MPI_Reduce(Dead_Sum, MDead_Sum, DAYS+2, MPI_DOUBLE, MPI_SUM, master, MPI_COMM_WORLD);
	MPI_Reduce(Vac_Sum, MVac_Sum, DAYS+2, MPI_DOUBLE, MPI_SUM, master, MPI_COMM_WORLD);

	MPI_Reduce(New_S_Sum, MNew_S_Sum, DAYS+2, MPI_DOUBLE, MPI_SUM, master, MPI_COMM_WORLD);
	MPI_Reduce(New_E_Sum, MNew_E_Sum, DAYS+2, MPI_DOUBLE, MPI_SUM, master, MPI_COMM_WORLD);
	MPI_Reduce(New_IP_Sum, MNew_IP_Sum, DAYS+2, MPI_DOUBLE, MPI_SUM, master, MPI_COMM_WORLD);
	MPI_Reduce(New_IA_Sum, MNew_IA_Sum, DAYS+2, MPI_DOUBLE, MPI_SUM, master, MPI_COMM_WORLD);
	MPI_Reduce(New_ISLight_Sum, MNew_ISLight_Sum, DAYS+2, MPI_DOUBLE, MPI_SUM, master, MPI_COMM_WORLD);
	MPI_Reduce(New_ISModerate_Sum, MNew_ISModerate_Sum, DAYS+2, MPI_DOUBLE, MPI_SUM, master, MPI_COMM_WORLD);
	MPI_Reduce(New_ISSevere_Sum, MNew_ISSevere_Sum, DAYS+2, MPI_DOUBLE, MPI_SUM, master, MPI_COMM_WORLD);
	MPI_Reduce(New_H_Sum, MNew_H_Sum, DAYS+2, MPI_DOUBLE, MPI_SUM, master, MPI_COMM_WORLD);
	MPI_Reduce(New_Recovered_Sum, MNew_Recovered_Sum, DAYS+2, MPI_DOUBLE, MPI_SUM, master, MPI_COMM_WORLD);
	MPI_Reduce(New_DeadCovid_Sum, MNew_DeadCovid_Sum, DAYS+2, MPI_DOUBLE, MPI_SUM, master, MPI_COMM_WORLD);
	MPI_Reduce(New_Dead_Sum, MNew_Dead_Sum, DAYS+2, MPI_DOUBLE, MPI_SUM, master, MPI_COMM_WORLD);
	MPI_Reduce(New_Vac_Sum, MNew_Vac_Sum, DAYS+2, MPI_DOUBLE, MPI_SUM, master, MPI_COMM_WORLD);

	if(rank == master)
	{
		for(t=0;t<=DAYS;t++)
		{	
			S_Mean[t]          = MS_Sum[t]/((double)MAXSIM);
			E_Mean[t]          = ME_Sum[t]/((double)MAXSIM);
			IP_Mean[t]         = MIP_Sum[t]/((double)MAXSIM);  
			IA_Mean[t]         = MIA_Sum[t]/((double)MAXSIM);        
			ISLight_Mean[t]    = MISLight_Sum[t]/((double)MAXSIM);
			ISModerate_Mean[t] = MISModerate_Sum[t]/((double)MAXSIM);      
			ISSevere_Mean[t]   = MISSevere_Sum[t]/((double)MAXSIM);             
			H_Mean[t]          = MH_Sum[t]/((double)MAXSIM);         
			ICU_Mean[t]        = MICU_Sum[t]/((double)MAXSIM);     
			Recovered_Mean[t]  = MRecovered_Sum[t]/((double)MAXSIM); 
			DeadCovid_Mean[t]  = MDeadCovid_Sum[t]/((double)MAXSIM); 
			Dead_Mean[t]       = MDead_Sum[t]/((double)MAXSIM);   
			Vac_Mean[t]        = MVac_Sum[t]/((double)MAXSIM);   
		
			New_S_Mean[t]          = MNew_S_Sum[t]/((double)MAXSIM);
			New_E_Mean[t]          = MNew_E_Sum[t]/((double)MAXSIM);    
			New_IP_Mean[t]         = MNew_IP_Sum[t]/((double)MAXSIM);      
			New_IA_Mean[t]         = MNew_IA_Sum[t]/((double)MAXSIM);  
			New_ISLight_Mean[t]    = MNew_ISLight_Sum[t]/((double)MAXSIM); 
			New_ISModerate_Mean[t] = MNew_ISModerate_Sum[t]/((double)MAXSIM); 
			New_ISSevere_Mean[t]   = MNew_ISSevere_Sum[t]/((double)MAXSIM); 
			New_H_Mean[t]          = MNew_H_Sum[t]/((double)MAXSIM);     
			New_ICU_Mean[t]        = MNew_ICU_Sum[t]/((double)MAXSIM);     
			New_Recovered_Mean[t]  = MNew_Recovered_Sum[t]/((double)MAXSIM); 
			New_DeadCovid_Mean[t]  = MNew_DeadCovid_Sum[t]/((double)MAXSIM);   
			New_Dead_Mean[t]       = MNew_Dead_Sum[t]/((double)MAXSIM);       
			New_Vac_Mean[t]        = MNew_Vac_Sum[t]/((double)MAXSIM);          

			TotalInfectious = IP_Mean[t] + IA_Mean[t] + ISLight_Mean[t] + ISModerate_Mean[t] + ISSevere_Mean[t]; //
			fprintf(hp,"%d,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf\n",t,IP_Mean[t],IA_Mean[t],ISLight_Mean[t],ISModerate_Mean[t],ISSevere_Mean[t], TotalInfectious); // prevalence of infectious
			
			TotalInfectiousNew = New_IP_Mean[t] + New_IA_Mean[t] + New_ISLight_Mean[t] + New_ISModerate_Mean[t] + New_ISSevere_Mean[t];
			fprintf(jp,"%d,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf\n",t,New_IP_Mean[t],New_IA_Mean[t],New_ISLight_Mean[t],New_ISModerate_Mean[t],New_ISSevere_Mean[t], TotalInfectiousNew); // incidence of infectious
			
			/* incidence */
			fprintf(ip,"%d,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf\n",t,New_S_Mean[t],New_E_Mean[t],New_IP_Mean[t],New_IA_Mean[t],TotalInfectiousNew,New_H_Mean[t],New_ICU_Mean[t],New_Recovered_Mean[t],New_DeadCovid_Mean[t],New_Vac_Mean[t]);           
				
			//printf("%i\t%.10lf\n",t,N*DeadCovid_Mean[t]);
	
			/* prevalence */
			fprintf(fp,"%d,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf\n",t,S_Mean[t],E_Mean[t],IP_Mean[t],IA_Mean[t],TotalInfectious,H_Mean[t],ICU_Mean[t],Recovered_Mean[t],DeadCovid_Mean[t],Vac_Mean[t]); 
				
		} // t=0,t<DAYS
		t2 = MPI_Wtime();
		printf("\nElapsed time: %f seconds\n", t2 - t1);
		printf("Done!\n\n");
	}
    MPI_Finalize(); 
    return 0;
}
