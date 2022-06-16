void ISfunc(int i, int j)
{
	int infProtection = 0; // 0 - person can still be infected // 1 - person won't be infected
 	Person[i][j].TimeOnState++;
	if(Person[i][j].Days >= Person[i][j].AgeDeathDays) // natural death
	{
		Person[i][j].Swap = Dead;
		New_Dead++;
	}
	else //did not die (natural death)
	{
		if(Person[i][j].Health==IA)
		{
			if(Person[i][j].TimeOnState >= Person[i][j].StateTime) // time on IA state is over
			{
				Person[i][j].Swap = Recovered;
				New_Recovered++;
			}
			else
			{
				Neighborsinfectedfunc(i,j); // can still infect other people
				Person[i][j].Swap = IA;
			}
		}
		else if(Person[i][j].Health==ISLight)
		{
			if(Person[i][j].TimeOnState >= Person[i][j].StateTime) // time on ISLight state is over
			{	
				aleat();
				if(rn < ProbISLightToISModerate) 
				{
					Person[i][j].Swap = ISModerate;
					aleat();
					Person[i][j].StateTime = rn*(MaxISModerate - MinISModerate) + MinISModerate; // time on state ISModerate
					New_ISModerate++;
				}
				else
				{
					Person[i][j].Swap = Recovered;
					New_Recovered++;
				}
			}
			else
			{
				Neighborsinfectedfunc(i,j);
				Person[i][j].Swap = ISLight;
			}
		}
		else if(Person[i][j].Health==ISModerate)
		{
			if(Person[i][j].TimeOnState >= Person[i][j].StateTime) // time on ISModerate state is over
			{
				aleat();
				if(rn < ProbRecoveryModerate[Person[i][j].AgeYears])
				{
					Person[i][j].Swap = Recovered;
					infProtection = 1;
					New_Recovered++;
				}
				else if(Person[i][j].IsVaccinated != 0) // person was vaccinated
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
					if(infProtection == 1)
					{
						//Person[i][j].Swap = ISModerate;
						Person[i][j].Swap = Recovered;
						New_Recovered++;
					}
				}
				if(infProtection==0 && Person[i][j].Swap != Recovered) //else// gets severe COVID-19
				{
					Person[i][j].Swap = ISSevere;
					aleat();
					Person[i][j].StateTime = rn*(MaxISSevere - MinISSevere) + MinISSevere; //time on state IS severe
					New_ISSevere++;
				}
			}
			else
			{
				Neighborsinfectedfunc(i,j);
				Person[i][j].Swap = ISModerate;
			}
		} // end if (ISModerate)
		else if(Person[i][j].Health==ISSevere)
		{
			if(Person[i][j].TimeOnState >= Person[i][j].StateTime) // time on ISsevere state is over
			{
				aleat();
				if(rn < ProbRecoverySevere[Person[i][j].AgeYears])
				{
					Person[i][j].Swap = Recovered;
					infProtection = 1;
					New_Recovered++;
				}
				else if(Person[i][j].IsVaccinated != 0) // person was vaccinated
				{
					switch(Person[i][j].IsVaccinated)
					{
						case AZ:
							aleat();
							if(rn<=AZ_Eff_S) // person won't get worse
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
					if(infProtection == 1)
					{
						//Person[i][j].Swap = ISModerate;
						Person[i][j].Swap = Recovered;
						New_Recovered++;
					}
				}
				if(infProtection==0 && Person[i][j].Swap != Recovered) // hospitalization
				{
					if(AvailableBeds > 0)
					{
						AvailableBeds--;
						Person[i][j].Swap = H;
						aleat();
						Person[i][j].StateTime = rn*(MaxH - MinH) + MinH; //time in hospital	
						New_H++;		
					}
					else   // no beds available
					{
						Person[i][j].Swap = DeadCovid;
						New_DeadCovid++;
						//New_HDead++;
					}
				} // not recovered
			}
			else // time in IS (severe) state is running
				Person[i][j].Swap = ISSevere; 
		}
	}
}
