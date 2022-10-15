void UpdateFunc(int timeSim, int isolationState, double proportionIsolated, int startOfIsolation)
{
    int i, j;
    int aux;
	S_Total          = 0;
	E_Total          = 0;
	IP_Total         = 0;
	IA_Total         = 0; 
	ISLight_Total    = 0;
	ISModerate_Total = 0;
	ISSevere_Total   = 0;
	H_Total          = 0;
	ICU_Total        = 0;
	Recovered_Total  = 0;

    for(i=1;i<=L;i++) 
    	for(j=1;j<=L;j++)
		{
			Person[i][j].Health   = Person[i][j].Swap;   // Update the lattice
			Person[i][j].Exponent = 0;
			Person[i][j].Checked  = 0; 
			Person[i][j].AgeDays++;
			Person[i][j].Days++;

			if(Person[i][j].AgeYears >= Person[i][j].AgeDeathYears)
				Person[i][j].Health  = Dead;
				
			if(Person[i][j].Health==Dead || Person[i][j].Health==DeadCovid) // dead person is replaced by a new susceptible with random age
			{
				if(Person[i][j].Health==Dead)
				{
					New_Dead++;   
					Dead_Total++; 
				}
				Person[i][j].Health = S;
				aleat();  // random distribute age to new susceptible at t=0
				Person[i][j].AgeYears = rn*100;
				Person[i][j].AgeDays  =  Person[i][j].AgeYears*365;
				Person[i][j].Days     = 0;
				if(Person[i][j].IsVaccinated!=0) // 
				{
					Person[i][j].IsVaccinated = 0;
					Vac_Total--;
				}
				Person[i][j].Isolation     = 0;
				Person[i][j].TimeOnState   = 0;  
				Person[i][j].StateTime     = 0; 
				
				//Define age of natural death
				aux = 0;
				do
				{
					aleat();
					Person[i][j].AgeDeathYears = rn*100;
					aleat();
					if(rn < ProbNaturalDeath[Person[i][j].AgeDeathYears])
						aux = 1; // accept
					else
						aux = 0; // reject
				}while(aux<1);
				Person[i][j].AgeDeathDays = Person[i][j].AgeDeathYears*365;
			
				if(Person[i][j].AgeDeathYears < Person[i][j].AgeYears)
				{
					aux = Person[i][j].AgeDeathYears;
					Person[i][j].AgeYears = Person[i][j].AgeDeathYears;
					Person[i][j].AgeDeathYears = aux;
					Person[i][j].AgeDeathDays = Person[i][j].AgeDeathYears*365;
				}
				New_S++;
			}
		}

	for(i=1;i<=L;i++)
		for(j=1;j<=L;j++)
		{
			if(Person[i][j].Health==S)
				S_Total++;
			else if(Person[i][j].Health==E)
				E_Total++;
			else if(Person[i][j].Health==IP)
				IP_Total++;
			else if(Person[i][j].Health==IA)
				IA_Total++;
			else if(Person[i][j].Health==ISLight)
				ISLight_Total++;
			else if(Person[i][j].Health==ISModerate)
				ISModerate_Total++;
			else if(Person[i][j].Health==ISSevere)
				ISSevere_Total++;
			else if(Person[i][j].Health==H)
				H_Total++;
			else if(Person[i][j].Health==ICU)
				ICU_Total++;
			else if(Person[i][j].Health==Recovered)
				Recovered_Total++;
		}
		
		if(isolationState==1) 
		{
			MaximumIsolated = proportionIsolated*N;
			if(timeSim==startOfIsolation)
				IsolationFunc();			
		}
		
		DeadCovid_Total += New_DeadCovid;
		Vac_Total += New_Vac;
		CountDays++;
    	
      	S_TotalTemp[Simulation][CountDays]          = 1.0*S_Total/(1.0*N);
		E_TotalTemp[Simulation][CountDays]          = 1.0*E_Total/(1.0*N);    
		IP_TotalTemp[Simulation][CountDays]         = 1.0*IP_Total/(1.0*N);           
		IA_TotalTemp[Simulation][CountDays]         = 1.0*IA_Total/(1.0*N);         
		ISLight_TotalTemp[Simulation][CountDays]    = 1.0*ISLight_Total/(1.0*N);    
		ISModerate_TotalTemp[Simulation][CountDays] = 1.0*ISModerate_Total/(1.0*N);   
		ISSevere_TotalTemp[Simulation][CountDays]   = 1.0*ISSevere_Total/(1.0*N);       
		H_TotalTemp[Simulation][CountDays]          = 1.0*H_Total/(1.0*N);                     
		ICU_TotalTemp[Simulation][CountDays]        = 1.0*ICU_Total/(1.0*N);           
		Recovered_TotalTemp[Simulation][CountDays]  = 1.0*Recovered_Total/(1.0*N);      
		DeadCovid_TotalTemp[Simulation][CountDays]  = 1.0*DeadCovid_Total/(1.0*N);       
		Dead_TotalTemp[Simulation][CountDays]       = 1.0*Dead_Total/(1.0*N);        
		Vac_TotalTemp[Simulation][CountDays]        = 1.0*Vac_Total/(1.0*N);             
	 
		New_S_Temp[Simulation][CountDays]          = 1.0*New_S/(1.0*N);
		New_E_Temp[Simulation][CountDays]          = 1.0*New_E/(1.0*N);    
		New_IP_Temp[Simulation][CountDays]         = 1.0*New_IP/(1.0*N);           
		New_IA_Temp[Simulation][CountDays]         = 1.0*New_IA/(1.0*N);         
		New_ISLight_Temp[Simulation][CountDays]    = 1.0*New_ISLight/(1.0*N); 
		New_ISModerate_Temp[Simulation][CountDays] = 1.0*New_ISModerate/(1.0*N); 
		New_ISSevere_Temp[Simulation][CountDays]   = 1.0*New_ISSevere/(1.0*N);        
		New_H_Temp[Simulation][CountDays]          = 1.0*New_H/(1.0*N);                    
		New_ICU_Temp[Simulation][CountDays]        = 1.0*New_ICU/(1.0*N);           
		New_Recovered_Temp[Simulation][CountDays]  = 1.0*New_Recovered/(1.0*N);       
		New_DeadCovid_Temp[Simulation][CountDays]  = 1.0*New_DeadCovid/(1.0*N);       
		New_Dead_Temp[Simulation][CountDays]       = 1.0*New_Dead/(1.0*N);          
		New_Vac_Temp[Simulation][CountDays]        = 1.0*New_Vac/(1.0*N);           
		
		/*********************************************************/ 
		
		S_Sum[CountDays]          += S_TotalTemp[Simulation][CountDays];
		E_Sum[CountDays]          += E_TotalTemp[Simulation][CountDays];    
		IP_Sum[CountDays]         += IP_TotalTemp[Simulation][CountDays];           
		IA_Sum[CountDays]         += IA_TotalTemp[Simulation][CountDays];         
		ISLight_Sum[CountDays]    += ISLight_TotalTemp[Simulation][CountDays];   
		ISModerate_Sum[CountDays] += ISModerate_TotalTemp[Simulation][CountDays];   
		ISSevere_Sum[CountDays]   += ISSevere_TotalTemp[Simulation][CountDays];        
		H_Sum[CountDays]          += H_TotalTemp[Simulation][CountDays];                     
		ICU_Sum[CountDays]        += ICU_TotalTemp[Simulation][CountDays];           
		Recovered_Sum[CountDays]  += Recovered_TotalTemp[Simulation][CountDays];       
		DeadCovid_Sum[CountDays]  += DeadCovid_TotalTemp[Simulation][CountDays];       
		Dead_Sum[CountDays]       += Dead_TotalTemp[Simulation][CountDays];         
		Vac_Sum[CountDays]        += Vac_TotalTemp[Simulation][CountDays];             
	 
		New_S_Sum[CountDays]          += New_S_Temp[Simulation][CountDays];               
		New_E_Sum[CountDays]          += New_E_Temp[Simulation][CountDays];        
		New_IP_Sum[CountDays]         += New_IP_Temp[Simulation][CountDays];               
		New_IA_Sum[CountDays]         += New_IA_Temp[Simulation][CountDays];             
		New_ISLight_Sum[CountDays]    += New_ISLight_Temp[Simulation][CountDays];  
		New_ISModerate_Sum[CountDays] += New_ISModerate_Temp[Simulation][CountDays];  
		New_ISSevere_Sum[CountDays]   += New_ISSevere_Temp[Simulation][CountDays];            
		New_H_Sum[CountDays]          += New_H_Temp[Simulation][CountDays];                        
		New_ICU_Sum[CountDays]        += New_ICU_Temp[Simulation][CountDays];               
		New_Recovered_Sum[CountDays]  += New_Recovered_Temp[Simulation][CountDays];           
		New_DeadCovid_Sum[CountDays]  += New_DeadCovid_Temp[Simulation][CountDays];           
		New_Dead_Sum[CountDays]       += New_Dead_Temp[Simulation][CountDays];              
		New_Vac_Sum[CountDays]        += New_Vac_Temp[Simulation][CountDays];                 
	 
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
}