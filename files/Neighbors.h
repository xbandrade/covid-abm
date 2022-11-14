int NeighborsFunc(int i, int j)
{
	int k, l, m, n;         
	int infectedCount; // counter for infected individuals in the neighborhood
	int rContacts;     // random contacts
	int ri, rj;        // random i, random j
	int aux;
	double probContagion;
	double effVac;
	infectedCount = 0;
	Contagion = 0;

	if(Person[i][j].Isolation==IsolationNo) // isolation only for random contacts
	{
		aleat();
		rContacts = rn*(MaxRandomContacts - MinRandomContacts) +  MinRandomContacts;	
		aux = 0; /* Check random contacts */

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
			if(Person[ri][rj].Health==IP || Person[ri][rj].Health==ISLight || Person[ri][rj].Health==ISModerate ||
			   Person[ri][rj].Health==ISSevere  || Person[ri][rj].Health==IA || Person[ri][rj].Health==H || Person[ri][rj].Health==ICU)
				infectedCount++;  // infectious random agent
			aux++;
		}while(aux < rContacts);
	}

	/* Check neighbors in the lattice */  
	if(Person[i-1][j].Health==IP || Person[i-1][j].Health==ISLight || Person[i-1][j].Health==ISModerate || Person[i-1][j].Health==ISSevere  || Person[i-1][j].Health==IA || Person[i-1][j].Health==H || Person[i-1][j].Health==ICU)
		infectedCount++;
	if(Person[i+1][j].Health==IP || Person[i+1][j].Health==ISLight || Person[i+1][j].Health==ISModerate || Person[i+1][j].Health==ISSevere  || Person[i+1][j].Health==IA || Person[i+1][j].Health==H || Person[i+1][j].Health==ICU)
		infectedCount++;
	if(Person[i][j-1].Health==IP || Person[i][j-1].Health==ISLight || Person[i][j-1].Health==ISModerate || Person[i][j-1].Health==ISSevere  || Person[i][j-1].Health==IA  || Person[i][j-1].Health==H  || Person[i][j-1].Health==ICU)
		infectedCount++;
	if(Person[i][j+1].Health==IP || Person[i][j+1].Health==ISLight || Person[i][j+1].Health==ISModerate || Person[i][j+1].Health==ISSevere  || Person[i][j+1].Health==IA || Person[i][j+1].Health==H || Person[i][j+1].Health==ICU)
		infectedCount++;

	if(infectedCount > 0) // Calculate probContagion
	{
		switch(Person[i][j].IsVaccinated)
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
		probContagion = (1 - effVac)*(1.0 - pow(1.0 - BETA,(double)infectedCount));
	}
	else
		probContagion = 0.0;

	if(infectedCount==0)
		Contagion = 0; // No contagion
	else
	{
		aleat();
		if(rn<=probContagion)
			Contagion = 1;
		else
			Contagion = 0;
  	}	
	return Contagion;
}
