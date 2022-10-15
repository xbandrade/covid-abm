void IsolationFunc()
{
	int aux;
	int ri, rj; // random i, random j
	int cont = 0;

	aux = 0;
	do{
		cont++;
		aleat();
		ri = rn*L + 1;
		aleat();
		rj = rn*L + 1;
       
		if(Person[ri][rj].Isolation==IsolationNo && (Person[ri][rj].Health!=H || Person[ri][rj].Health!=ICU))
		{
			Person[ri][rj].Isolation = IsolationYes;
			aux++;
		}    
	}while(aux < MaximumIsolated && cont < MaximumIsolated*10); // avoid infinite loops
}
