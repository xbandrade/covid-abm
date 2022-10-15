void IPfunc(int i, int j)
{
	int infProtection = 0; // 0 - person can still be infected // 1 - person won't get infected
 	Person[i][j].TimeOnState++;
	if(Person[i][j].Days >= Person[i][j].AgeDeathDays) // natural death
	{
		Person[i][j].Swap = Dead;
		New_Dead++;
	}
	else //did not die (natural death)
	{
		if(Person[i][j].TimeOnState >= Person[i][j].StateTime) // time on IP state is over
		{
			aleat();
			if(rn < ProbIPtoIA) // move to IA state
			{
				Person[i][j].Swap = IA;
				aleat();
				Person[i][j].StateTime = rn*(MaxIA - MinIA) + MinIA; //time on state IA
				New_IA++;	
			}
			else  // move to some type of IS
			{
				aleat();
				if(rn < ProbToBecomeISLight)
				{
					Person[i][j].Swap = ISLight;
					aleat();
					Person[i][j].StateTime = rn*(MaxISLight - MinISLight) + MinISLight; //time on state ISLight
					New_ISLight++;	
				}
				else if((rn>=ProbToBecomeISLight) && (rn<=(ProbToBecomeISLight + ProbToBecomeISModerate)))
				{
					Person[i][j].Swap = ISModerate;
					aleat();
					Person[i][j].StateTime = rn*(MaxISModerate - MinISModerate) + MinISModerate; //time on state ISModerate
					New_ISModerate++;
				}
				else // checks for vaccination
				{
					if(Person[i][j].IsVaccinated != 0) // person was vaccinated
					{
						switch(Person[i][j].IsVaccinated)
						{
							case AZ:
								aleat();
								if(rn<=AZ_Eff_S) // person won't get severe COVID-19
									infProtection = 1;
								break;
							case CV:
								aleat();
								if(rn<=CV_Eff_S)
									infProtection = 1;
								break;
							case CX:
								aleat();
								if(rn<=CX_Eff_S) 
									infProtection = 1;
								break;
							case JJ:
								aleat();
								if(rn<=JJ_Eff_S) 
									infProtection = 1;
								break;
							case MD:
								aleat();
								if(rn<=MD_Eff_S)
									infProtection = 1;
								break;
							case PF:
								aleat();
								if(rn<=PF_Eff_S)
									infProtection = 1;
								break;
							case SP:
								aleat();
								if(rn<=SP_Eff_S)
									infProtection = 1;
								break;
							default:
								puts("Value error\n");
								break;
						}
					}
					if(infProtection==0) // gets severe COVID-19
					{
						Person[i][j].Swap = ISSevere;
						aleat();
						Person[i][j].StateTime = rn*(MaxISSevere - MinISSevere) + MinISSevere; //time on state ISSevere
						New_ISSevere++;
					}
					else // protected from severe disease by vaccine - goes to light COVID instead
					{
						Person[i][j].Swap = ISLight;
						aleat();
						Person[i][j].StateTime = rn*(MaxISLight - MinISLight) + MinISLight; //time on state ISLight
						New_ISLight++;	
					}
				}
			}
		}
		else
		{
			NeighborsInfectedFunc(i,j);
			Person[i][j].Swap = IP;
		}
	}
}
		