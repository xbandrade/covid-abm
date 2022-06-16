int Neighborsfunc(int i , int j)
{

	int k, l, m, n;         
	int KI; /* counter for infected individuals in the neighborhood */
	int RandomContacts;
	int Randomi;
	int Randomj;
	int mute;
	double ProbContagion;
	double effVac;
	Contagion = 0;
	KI = 0;

	if(Person[i][j].Isolation==IsolationNo) // isolation only for random contacts
	{
		aleat();
		RandomContacts = rn*(MaxRandomContacts - MinRandomContacts) +  MinRandomContacts;	
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
		
			if(Person[Randomi][Randomj].Health==IP || Person[Randomi][Randomj].Health==ISLight || Person[Randomi][Randomj].Health==ISModerate  ||
				Person[Randomi][Randomj].Health==ISSevere  || Person[Randomi][Randomj].Health==IA || Person[Randomi][Randomj].Health==H || Person[Randomi][Randomj].Health==ICU)
				KI++;  // infectious random agent
					
			mute++;
		}while(mute < RandomContacts);
	}

	/* Check 8 neighbors in the lattice */    
		for(k=-1;k<=1;k++) 	
			for(l=-1;l<=1;l++)
				if(Person[i+k][j+l].Health==IP || Person[i+k][j+l].Health==ISLight || Person[i+k][j+l].Health==ISModerate || Person[i+k][j+l].Health==ISSevere  ||
					Person[i+k][j+l].Health==IA || Person[i+k][j+l].Health==H || Person[i+k][j+l].Health==ICU)
					KI++;


	if(KI > 0) // Calculate ProbContagion
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
		ProbContagion = (1 - effVac)*(1.0 - pow(1.0 - Beta,(double)KI));
	}
	else
		ProbContagion = 0.0;

	if(KI==0)
		Contagion = 0; // No contagion
	else
	{
		aleat();
		if(rn<=ProbContagion)
			Contagion = 1;
		else
			Contagion = 0;
  	}	
	return Contagion;
}
