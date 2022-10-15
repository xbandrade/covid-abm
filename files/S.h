void Sfunc(int i, int j)
{
	if(Person[i][j].Days >= Person[i][j].AgeDeathDays) // natural death
	{
		Person[i][j].Swap = Dead;
		New_Dead++;
	}
	else
	{
		NeighborsFunc(i, j);
		if(Contagion==1)   
		{
			Person[i][j].Checked = 1; 
			Person[i][j].Swap = E;
			Person[i][j].TimeOnState = 0; // reset time in the new state
			aleat();
			Person[i][j].StateTime = rn*(MaxLatency - MinLatency) + MinLatency; // time of latency 
			New_E++;
		}
		else // no contagion, stays on S
			Person[i][j].Swap = S;
	}		
}
