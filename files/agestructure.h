void Agestructure() // Brazil
{
  ProbBirthAge[1]  	=	0.06960000; // 0–4 years
  ProbBirthAge[2]  	=	0.06920000; // 5–9
  ProbBirthAge[3]  	=	0.06990000; // 10–14
  ProbBirthAge[4]  	=	0.07460000; // 15–19
  ProbBirthAge[5]  	=	0.08140000; // 20–24
  ProbBirthAge[6]  	=	0.08020000; // 25–29
  ProbBirthAge[7]  	=	0.08130000; // 30–34
  ProbBirthAge[8]  	=	0.08040000; // 35–39
  ProbBirthAge[9]  	=	0.07370000; // 40–44
  ProbBirthAge[10] 	=	0.06450000; // 45–49
  ProbBirthAge[11] 	=	0.05960000; // 50–54
  ProbBirthAge[12] 	=	0.05320000; // 55–59
  ProbBirthAge[13] 	=	0.04430000; // 60–64
  ProbBirthAge[14] 	=	0.03470000; // 65–69
  ProbBirthAge[15] 	=	0.02550000; // 70–74
  ProbBirthAge[16] 	=	0.01710000; // 75–79
  ProbBirthAge[17] 	=	0.01120000; // 80–84
  ProbBirthAge[18] 	=	0.00590000; // 85–89
  ProbBirthAge[19] 	=	0.00380000; // 90+
	

  SumProbBirthAge[0]  = ProbBirthAge[1];
  SumProbBirthAge[1]  = SumProbBirthAge[0]  + ProbBirthAge[2];
  SumProbBirthAge[2]  = SumProbBirthAge[1]  + ProbBirthAge[3];
  SumProbBirthAge[3]  = SumProbBirthAge[2]  + ProbBirthAge[4];
  SumProbBirthAge[4]  = SumProbBirthAge[3]  + ProbBirthAge[5];
  SumProbBirthAge[5]  = SumProbBirthAge[4]  + ProbBirthAge[6];
  SumProbBirthAge[6]  = SumProbBirthAge[5]  + ProbBirthAge[7];
  SumProbBirthAge[7]  = SumProbBirthAge[6]  + ProbBirthAge[8];
  SumProbBirthAge[8]  = SumProbBirthAge[7]  + ProbBirthAge[9];
  SumProbBirthAge[9]  = SumProbBirthAge[8]  + ProbBirthAge[10];
  SumProbBirthAge[10] = SumProbBirthAge[9]  + ProbBirthAge[11];
  SumProbBirthAge[11] = SumProbBirthAge[10] + ProbBirthAge[12];
  SumProbBirthAge[12] = SumProbBirthAge[11] + ProbBirthAge[13];
  SumProbBirthAge[13] = SumProbBirthAge[12] + ProbBirthAge[14];
  SumProbBirthAge[14] = SumProbBirthAge[13] + ProbBirthAge[15];
  SumProbBirthAge[15] = SumProbBirthAge[14] + ProbBirthAge[16];
  SumProbBirthAge[16] = SumProbBirthAge[15] + ProbBirthAge[17];
  SumProbBirthAge[17] = SumProbBirthAge[16] + ProbBirthAge[18];
  SumProbBirthAge[18] = SumProbBirthAge[17] + ProbBirthAge[19];

  AgeMin[0] = 0;
  AgeMax[0] = 4;

  AgeMin[1] = 5;
  AgeMax[1] = 9;

  AgeMin[2] = 10;
  AgeMax[2] = 14;

  AgeMin[3] = 15;
  AgeMax[3] = 19;

  AgeMin[4] = 20;
  AgeMax[4] = 24;

  AgeMin[5] = 25;
  AgeMax[5] = 29;

  AgeMin[6] = 30;
  AgeMax[6] = 34;

  AgeMin[7] = 35;
  AgeMax[7] = 39;

  AgeMin[8] = 40;
  AgeMax[8] = 44;

  AgeMin[9] = 45;
  AgeMax[9] = 49;

  AgeMin[10] = 50;
  AgeMax[10] = 54;

  AgeMin[11] = 55;
  AgeMax[11] = 59;

  AgeMin[12] = 60;
  AgeMax[12] = 64;

  AgeMin[13] = 65;
  AgeMax[13] = 69;

  AgeMin[14] = 70;
  AgeMax[14] = 74;

  AgeMin[15] = 75;
  AgeMax[15] = 79;

  AgeMin[16] = 80;
  AgeMax[16] = 84;

  AgeMin[17] = 85;
  AgeMax[17] = 89;

  AgeMin[18] = 90;
  AgeMax[18] = 100;
}
