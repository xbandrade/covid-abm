void Isolationfunc()
{
	int mute;
	int Randomi;
	int Randomj;
	int cont = 0;

	mute = 0;
	do{
		cont++;
		aleat();
		Randomi = rn*L + 1;
		
		aleat();
		Randomj = rn*L + 1;
       
		if(Person[Randomi][Randomj].Isolation==IsolationNo && (Person[Randomi][Randomj].Health!=H || Person[Randomi][Randomj].Health!=ICU))
		{
			Person[Randomi][Randomj].Isolation = IsolationYes;
			mute++;
		}    
	}while(mute < MaximumIsolated && cont < MaximumIsolated*10); // avoid infinite loops
}
