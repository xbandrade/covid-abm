void pbc()
{    
    int i;
    for(i=1;i<=L;i++) /* Periodic boundary conditions */
    {
        Person[0][i].Health   = Person[L][i].Health;
        Person[L+1][i].Health = Person[1][i].Health;
        Person[i][0].Health   = Person[i][L].Health;
        Person[i][L+1].Health = Person[i][1].Health;
    }
    
    Person[0][0].Health     = Person[L][L].Health;  /* Periodic boundary conditions on the borders */
    Person[0][L+1].Health   = Person[L][1].Health;
    Person[L+1][0].Health   = Person[1][L].Health;
    Person[L+1][L+1].Health = Person[1][1].Health;
}
