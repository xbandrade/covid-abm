void Hfunc(int i, int j)
{
 	Person[i][j].TimeOnState++;
	if(Person[i][j].Days >= Person[i][j].AgeDeathDays) // natural death
	{
		AvailableBeds++;
		Person[i][j].Swap = Dead;
		New_Dead++;
	}
	else //did not die (natural death)
	{
		if(Person[i][j].TimeOnState >= Person[i][j].StateTime) // time on H is over
		{
			aleat();
			if(rn < ProbRecoveryH[Person[i][j].AgeYears])
			{
				Person[i][j].Swap = Recovered;
				AvailableBeds++;
				New_Recovered++;
			}
			else
			{
				if(AvailableBedsICU > 0)
				{
					Person[i][j].Swap = ICU;
					AvailableBedsICU--;
					AvailableBeds++;
					aleat();
					Person[i][j].StateTime = rn*(MaxICU - MinICU) + MinICU; // time on state ICU
					New_ICU++;
				}
				else // no beds available
				{
					Person[i][j].Swap = DeadCovid;
					AvailableBeds++;
					New_DeadCovid++;
				}
			} // not recovered
		}
		else
			Person[i][j].Swap = H;
	}
}
