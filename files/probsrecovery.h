void ProbsRecovery()
{
	int i;
	/* Probs Recovery for IS Moderate - age dependent */
	for(i=0;i<60;i++)
		ProbRecoveryModerate[i] = ProbRecoveryModerateYounger;
	for(i=60;i<70;i++)
		ProbRecoveryModerate[i] = ProbRecoveryModerate_60_70;
	for(i=70;i<80;i++)
		ProbRecoveryModerate[i] = ProbRecoveryModerate_70_80;
	for(i=80;i<90;i++)
		ProbRecoveryModerate[i] = ProbRecoveryModerate_80_90;
	for(i=90;i<120;i++)
		ProbRecoveryModerate[i] = ProbRecoveryModerate_Greater90;

	/* Probs Recovery for IS Severe - age dependent */
	for(i=0;i<60;i++)
		ProbRecoverySevere[i] = ProbRecoverySevereYounger;
	for(i=60;i<70;i++)
		ProbRecoverySevere[i] = ProbRecoverySevere_60_70;
	for(i=70;i<80;i++)
		ProbRecoverySevere[i] = ProbRecoverySevere_70_80;
	for(i=80;i<90;i++)
		ProbRecoverySevere[i] = ProbRecoverySevere_80_90;
	for(i=90;i<120;i++)
		ProbRecoverySevere[i] = ProbRecoverySevere_Greater90;

	/* Probs Recovery for H - age dependent */
	for(i=0;i<20;i++)
		ProbRecoveryH[i] = ProbRecoveryHYounger;
    for(i=20;i<30;i++)
		ProbRecoveryH[i] = ProbRecoveryH_20_30;
	for(i=30;i<40;i++)
		ProbRecoveryH[i] = ProbRecoveryH_30_40;
	for(i=40;i<50;i++)
        ProbRecoveryH[i] = ProbRecoveryH_40_50;
	for(i=50;i<60;i++)
		ProbRecoveryH[i] = ProbRecoveryH_50_60;
	for(i=60;i<70;i++)
		ProbRecoveryH[i] = ProbRecoveryH_60_70;
	for(i=70;i<80;i++)
		ProbRecoveryH[i] = ProbRecoveryH_70_80;
	for(i=80;i<90;i++)
		ProbRecoveryH[i] = ProbRecoveryH_80_90;
	for(i=90;i<120;i++)
		ProbRecoveryH[i] = ProbRecoverySevere_Greater90;

	/* Probs Recovery for ICU - age dependent */
	for(i=0;i<60;i++)
		ProbRecoveryICU[i] = ProbRecoveryICUYounger;
	for(i=60;i<70;i++)
		ProbRecoveryICU[i] = ProbRecoveryICU_60_70;
	for(i=70;i<80;i++)
		ProbRecoveryICU[i] = ProbRecoveryICU_70_80;
	for(i=80;i<90;i++)
		ProbRecoveryICU[i] = ProbRecoveryICU_80_90;
	for(i=90;i<120;i++)
		ProbRecoveryICU[i] = ProbRecoverySevere_Greater90;
}
