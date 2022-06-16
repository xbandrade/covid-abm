int Neighborsinfectedfunc(int i , int j)
{
	int k, l, m, n;         
	int RandomContacts;
	int Randomi;
	int Randomj;
	int mute;
	
	double ProbContagion;         
	double effVac;

	if(Person[i][j].Isolation==IsolationNo) // isolation only for random contacts
	{
		aleat();
		RandomContacts = rn*(MaxRandomContacts - MinRandomContacts) + MinRandomContacts;	
		mute = 0; /* Check random contacts */
		if(RandomContacts > 0)
		do
		{
			do
			{
				aleat();
				Randomi = rn*L + 1;
			}while(Randomi==i);
			do
			{
				aleat();
				Randomj = rn*L + 1;
			}while(Randomj==j); // random agent
       
			if(Person[Randomi][Randomj].Health==S)
				Person[Randomi][Randomj].Exponent++; 
	
			if(Person[Randomi][Randomj].Checked==0 && Person[Randomi][Randomj].Exponent==1)
			{
				switch(Person[Randomi][Randomj].IsVaccinated)
				{
					case 0:
						effVac = 0.0;
						break;
					case AZ:
						effVac = AZ_Eff_I;
						break;
					case CV:
						effVac = CV_Eff_I;
						break;
					case CX:
						effVac = CX_Eff_I;
						break;
					case JJ:
						effVac = JJ_Eff_I;
						break;
					case MD:
						effVac = MD_Eff_I;
						break;
					case PF:
						effVac = PF_Eff_I;
						break;
					case SP:
						effVac = SP_Eff_I;
						break;
					default:
						puts("Value error\n");
						effVac = -2.0;
						break;
				}

				ProbContagion = (1 - effVac)*(1.0 - pow(1.0 - Beta,(double)Person[Randomi][Randomj].Exponent));
				
				aleat();
				if(rn<=ProbContagion)
				{
					Person[Randomi][Randomj].Checked = 1;
					Person[Randomi][Randomj].Swap = E;
					Person[Randomi][Randomj].TimeOnState = 0; // reset time in the new state
						
					aleat();
					Person[Randomi][Randomj].StateTime = rn*(MaxLatency - MinLatency) + MinLatency; //time of latency 
					
					New_E++;
				}
				else
					Person[Randomi][Randomj].Checked = 0;
			}
       		mute++;
		}while(mute < RandomContacts);
	} 
}
