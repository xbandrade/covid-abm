void VaccinationFunc(int i, int j, int vac, int begin, double percVaccination) 
{
    // int begin -> 1 = called from begin function, 0 = called from simulation steps
    double probVac;
    probVac = begin==1 ? 1. : percVaccination; // if VaccinationFunc is called from begin function, person will always be vaccinated
    aleat();
    //if(rn > 0.03) // vaccine hesitancy
    if(rn<=probVac) // person will be vaccinated
    {
        if(vac==BR)
        {
            aleat();
            if(rn<=R0)
                Person[i][j].IsVaccinated = AZ; // AstraZeneca
            else if(rn>R0 && rn<=R1)
                Person[i][j].IsVaccinated = CV; // CoronaVac
            else if(rn>R1 && rn<=R2)
                Person[i][j].IsVaccinated = JJ; // Janssen
            else
                Person[i][j].IsVaccinated = PF; // Pfizer
        }
        else
            Person[i][j].IsVaccinated = vac;
        New_Vac++;
    }
}