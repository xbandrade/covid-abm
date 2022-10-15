void BeginFunc(int vaccine, int vacCurrentMin)
{
	int i, j, k;
	int aux;
	int maximumAge;
	int minimumAge;
 
	S_Total          = 0;
	E_Total          = Eini;
	IP_Total         = IPini;
	IA_Total         = IAini; 
	ISLight_Total    = ISLightini;
	ISModerate_Total = ISModerateini;
	ISSevere_Total   = ISSevereini;
	H_Total          = Hini;
	ICU_Total        = ICUini;
	Recovered_Total  = Recoveredini;
	DeadCovid_Total  = DeadCovidini;
	Dead_Total       = Deadini;
	Vac_Total        = Vaccinatedini;
	
	New_S          = 0;
	New_E          = 0;
	New_IP         = 0;  
	New_IA         = 0;
	New_ISLight    = 0;
	New_ISModerate = 0;
	New_ISSevere   = 0;
	New_H          = 0;
	New_ICU        = 0;
	New_Recovered  = 0;
	New_DeadCovid  = 0;
	New_Dead       = 0;
	New_Vac        = 0;

	for(i=1;i<=L;i++)  
	{
		for(j=1;j<=L;j++)  
		{
			Person[i][j].Health = S;
			Person[i][j].Isolation = IsolationNo;  // no isolation for all
			Person[i][j].Exponent = 0;
			Person[i][j].Checked = 0; 
			Person[i][j].IsVaccinated = 0;         // no vaccination

			aux = 0;
			k = 0;
			aleat();
			if(rn<=SumProbBirthAge[k])// SumProbBirthAge[k] is in agestructure.h
			{
				aux = 1;  
				maximumAge = AgeMax[k];
				minimumAge = AgeMin[k];
			}
			else
			{
				do{
					if(rn>SumProbBirthAge[k] && rn<=SumProbBirthAge[k+1])
					{
						aux = 1;
						maximumAge = AgeMax[k+1];
						minimumAge = AgeMin[k+1];
					}
					else
					{
						aux = 0;
						k++;
					}
				}while(aux < 1);
			}
        
			aleat();
			Person[i][j].AgeYears = rn*(maximumAge - minimumAge) + minimumAge;
			Person[i][j].AgeDays  = Person[i][j].AgeYears*365;
			
			aleat();
			Person[i][j].AgeDays = rn*365; // to have different birthday dates for the individual
		
			Person[i][j].TimeOnState = 0;  // how long he/she is on that health state
			Person[i][j].StateTime   = 0;  // how long he/she will be on that health state
			
			Person[i][j].Days = 0;         // set to zero the number of days a person is in the simulation  
			
			//Define age of natural death
			aux = 0;
			do{
				aleat();
				Person[i][j].AgeDeathYears = rn*100;
				aleat();
				if(rn < ProbNaturalDeath[Person[i][j].AgeDeathYears])
					aux = 1;  // accept
				else
					aux = 0;  // reject
			}while(aux<1);
			Person[i][j].AgeDeathDays = Person[i][j].AgeDeathYears*365;
			S_Total++;
		}// for j
	}// for i

   	/* Random distribution of infected individuals in t=0 */
	k=0;
	if(Eini > 0)
		do{
			aleat();
			i = rn*L + 1;
			aleat();
			j = rn*L + 1;

			if(Person[i][j].Health==S)
			{
				Person[i][j].Health = E;
				aleat();
				Person[i][j].StateTime = rn*(MaxLatency - MinLatency) + MinLatency;
				Person[i][j].Isolation = IsolationNo;

				S_Total--;
				E_Total++;
				New_E++;
				k++;
			}
		}while(k < Eini);

    /**********************************/  
    k=0;
	if(IPini > 0)
		do{
			aleat();
			i = rn*L + 1;
			aleat();
			j = rn*L + 1;
			if(Person[i][j].Health==S)
			{
				Person[i][j].Health = IP;
				aleat();
				Person[i][j].StateTime = rn*(MaxIP - MinIP) + MinIP;
				Person[i][j].Isolation = IsolationNo;
				S_Total--;
				IP_Total++;
				New_IP++;
				k++;
			}
		}while(k < IPini);

    /******************************************/
    k=0;
	if(IAini > 0)
		do{
			aleat();
			i = rn*L + 1;
			aleat();
			j = rn*L + 1;
			if(Person[i][j].Health==S)
			{
				Person[i][j].Health = IA;
				aleat();
				Person[i][j].StateTime = rn*(MaxIA - MinIA) + MinIA;
				Person[i][j].Isolation = IsolationNo;
				S_Total--;
				IA_Total++;
				New_IA++;
				k++;
			}
		}while(k < IAini);  

    /*****************************************/
	k=0;
	if(ISLightini > 0)
		do{
			aleat();
			i = rn*L + 1;
			aleat();
			j = rn*L + 1;
			if(Person[i][j].Health==S)
			{
				Person[i][j].Health = ISLight;
				aleat();
				Person[i][j].StateTime = rn*(MaxISLight - MinISLight) + MinISLight;
				Person[i][j].Isolation = IsolationNo;
				S_Total--;
				ISLight_Total++;
				New_ISLight++;
				k++;
			}
		}while(k < ISLightini);  

   	/************************************************/
   	k=0;
	if(ISModerateini > 0)
		do{
			aleat();
			i = rn*L + 1;
			aleat();
			j = rn*L + 1;
			if(Person[i][j].Health==S)
			{
				Person[i][j].Health = ISModerate;
				aleat();
				Person[i][j].StateTime = rn*(MaxISModerate - MinISModerate) + MinISModerate;
				Person[i][j].Isolation = IsolationNo;
				S_Total--;
				ISModerate_Total++;
				New_ISModerate++;
				k++;
			}
		}while(k < ISModerateini);   

  	/**************************************************/
  	k=0;
	if(ISSevereini > 0)
		do{
			aleat();
			i = rn*L + 1;
			aleat();
			j = rn*L + 1;
			if(Person[i][j].Health==S)
			{
				Person[i][j].Health = ISSevere;
				aleat();
				Person[i][j].StateTime = rn*(MaxISSevere - MinISSevere) + MinISSevere;
				Person[i][j].Isolation = IsolationNo;
				S_Total--;
				ISSevere_Total++;
				New_ISSevere++;
				k++;
			}
		}while(k < ISSevereini);    

  	/**************************************************/
  	k=0;
	if(Recoveredini > 0)
		do{
			aleat();
			i = rn*L + 1;
			aleat();
			j = rn*L + 1;
			if(Person[i][j].Health==S)
			{
				Person[i][j].Health = Recovered;
				Person[i][j].Isolation = IsolationNo;
				S_Total--;
				New_Recovered++;
				k++;
			}
		}while(k < Recoveredini);

  	/**************************************************/
  	k=0;
	if(Vaccinatedini > 0 && vaccine != 0)
		do{
			aleat();
			i = rn*L + 1;
			aleat();
			j = rn*L + 1;
			if(Person[i][j].Health==S || Person[i][j].Health==E || Person[i][j].Health==Recovered)
				if(vaccine!=0 && Person[i][j].AgeYears>=vacCurrentMin && Person[i][j].IsVaccinated==0)
				{
					Person[i][j].Isolation = IsolationNo;
					VaccinationFunc(i, j, vaccine, 1, 1.);
					//S_Total--;
					New_Vac++;
					k++;
				}
		}while(k < Vaccinatedini);    
  
  	/**************************************************/
	S_TotalTemp[Simulation][0]          = 1.0*S_Total/(1.0*N);
	E_TotalTemp[Simulation][0]          = 1.0*E_Total/(1.0*N);               
	IP_TotalTemp[Simulation][0]         = 1.0*IP_Total/(1.0*N);               
	IA_TotalTemp[Simulation][0]         = 1.0*IA_Total/(1.0*N);               
	ISLight_TotalTemp[Simulation][0]    = 1.0*ISLight_Total/(1.0*N);   
	ISModerate_TotalTemp[Simulation][0] = 1.0*ISModerate_Total/(1.0*N);    
	ISSevere_TotalTemp[Simulation][0]   = 1.0*ISSevere_Total/(1.0*N);             
	H_TotalTemp[Simulation][0]          = 1.0*H_Total/(1.0*N);                   
	ICU_TotalTemp[Simulation][0]        = 1.0*ICU_Total/(1.0*N);             
	Recovered_TotalTemp[Simulation][0]  = 1.0*Recovered_Total/(1.0*N);       
	DeadCovid_TotalTemp[Simulation][0]  = 1.0*DeadCovid_Total/(1.0*N);       
	Dead_TotalTemp[Simulation][0]       = 1.0*Dead_Total/(1.0*N);        
	Vac_TotalTemp[Simulation][0]        = 1.0*Vac_Total/(1.0*N);            
	
	New_S_Temp[Simulation][0]           = 1.0*New_S/(1.0*N);
	New_E_Temp[Simulation][0]           = 1.0*New_E/(1.0*N);    
	New_IP_Temp[Simulation][0]          = 1.0*New_IP/(1.0*N);           
	New_IA_Temp[Simulation][0]          = 1.0*New_IA/(1.0*N);         
	New_ISLight_Temp[Simulation][0]     = 1.0*New_ISLight/(1.0*N);  
	New_ISModerate_Temp[Simulation][0]  = 1.0*New_ISModerate/(1.0*N);  
	New_ISSevere_Temp[Simulation][0]    = 1.0*New_ISSevere/(1.0*N);        
	New_H_Temp[Simulation][0]           = 1.0*New_H/(1.0*N);                    
	New_ICU_Temp[Simulation][0]         = 1.0*New_ICU/(1.0*N);           
	New_Recovered_Temp[Simulation][0]   = 1.0*New_Recovered/(1.0*N);       
	New_DeadCovid_Temp[Simulation][0]   = 1.0*New_DeadCovid/(1.0*N);       
	New_Dead_Temp[Simulation][0]        = 1.0*New_Dead/(1.0*N);           
	New_Vac_Temp[Simulation][0]         = 1.0*New_Vac/(1.0*N);             

    
	S_Sum[0]         	  += S_TotalTemp[Simulation][0];
	E_Sum[0]         	  += E_TotalTemp[Simulation][0];    
	IP_Sum[0]         	  += IP_TotalTemp[Simulation][0];           
	IA_Sum[0]         	  += IA_TotalTemp[Simulation][0];         
	ISLight_Sum[0]    	  += ISLight_TotalTemp[Simulation][0];      
	ISModerate_Sum[0] 	  += ISModerate_TotalTemp[Simulation][0];      
	ISSevere_Sum[0]  	  += ISSevere_TotalTemp[Simulation][0];        
	H_Sum[0]         	  += H_TotalTemp[Simulation][0];                
	ICU_Sum[0]       	  += ICU_TotalTemp[Simulation][0];           
	Recovered_Sum[0]      += Recovered_TotalTemp[Simulation][0];       
	DeadCovid_Sum[0]      += DeadCovid_TotalTemp[Simulation][0];       
	Dead_Sum[0]           += Dead_TotalTemp[Simulation][0];           
	Vac_Sum[0]            += Vac_TotalTemp[Simulation][0];          
             
	New_S_Sum[0]          += New_S_Temp[Simulation][0];               
	New_E_Sum[0]          += New_E_Temp[Simulation][0];      
	New_IP_Sum[0]         += New_IP_Temp[Simulation][0];             
	New_IA_Sum[0]         += New_IA_Temp[Simulation][0];           
	New_ISLight_Sum[0]    += New_ISLight_Temp[Simulation][0];      
	New_ISModerate_Sum[0] += New_ISModerate_Temp[Simulation][0];      
	New_ISSevere_Sum[0]   += New_ISSevere_Temp[Simulation][0];          
	New_H_Sum[0]          += New_H_Temp[Simulation][0];                        
	New_ICU_Sum[0]        += New_ICU_Temp[Simulation][0];             
	New_Recovered_Sum[0]  += New_Recovered_Temp[Simulation][0];         
	New_DeadCovid_Sum[0]  += New_DeadCovid_Temp[Simulation][0];         
	New_Dead_Sum[0]       += New_Dead_Temp[Simulation][0];            
	New_Vac_Sum[0]        += New_Vac_Temp[Simulation][0];                 
}
