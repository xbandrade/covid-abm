int NeighborsInfectedFunc(int i , int j)
{
	int k, l, m, n;         
	int rContacts; // random contacts
	int ri, rj; // random i, random j
	int aux;
	double probContagion;         
	double effVac;

	if(Person[i][j].Isolation==IsolationNo) // isolation for random contacts
	{
		aleat();
		rContacts = rn*(MaxRandomContacts - MinRandomContacts) + MinRandomContacts;	
		aux = 0; 
		/* Check random contacts */
		if(rContacts > 0)
		do{
			do{
				aleat();
				ri = rn*L + 1;
			}while(ri==i);
			do{
				aleat();
				rj = rn*L + 1;
			}while(rj==j); // random agent
			if(Person[ri][rj].Health==S)
				Person[ri][rj].Exponent++; 
			if(Person[ri][rj].Checked==0 && Person[ri][rj].Exponent==1)
			{
				switch(Person[ri][rj].IsVaccinated)
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
				probContagion = (1 - effVac)*(1.0 - pow(1.0 - BETA,(double)Person[ri][rj].Exponent));
				aleat();
				if(rn<=probContagion)
				{
					Person[ri][rj].Checked = 1;
					Person[ri][rj].Swap = E;
					Person[ri][rj].TimeOnState = 0; // reset time for the new state
					aleat();
					Person[ri][rj].StateTime = rn*(MaxLatency - MinLatency) + MinLatency; //time of latency 
					New_E++;
				}
				else
					Person[ri][rj].Checked = 0;
			}
       		aux++;
		}while(aux < rContacts);
	} 
}
