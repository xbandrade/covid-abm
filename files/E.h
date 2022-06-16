void Efunc(int i, int j)
{
	Person[i][j].TimeOnState++;
	
	if(Person[i][j].Days >= Person[i][j].AgeDeathDays) // natural death
	{
		Person[i][j].Swap = Dead;
		New_Dead++;
	}
	else //did not die (natural death)
	{
		if(Person[i][j].TimeOnState >=  Person[i][j].StateTime)  // time on E state is over
		{
			Person[i][j].Swap = IP;
			aleat();
			Person[i][j].StateTime = rn*(MaxIP - MinIP) + MinIP; // time on state IP
			New_IP++;	
		}
		else
			Person[i][j].Swap = E;
	}
}
		