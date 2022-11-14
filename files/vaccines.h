/* 
https://www.healthdata.org/covid/covid-19-vaccine-efficacy-summary

-original virus-
Vaccines            - SevereDisease - Infection
AstraZeneca         - 94%           - 63%
CoronaVac           - 50%           - 47%
Covaxin             - 78%           - 73%
Johnson&Johnson     - 86%           - 72%
Moderna             - 97%           - 92%
Pfizer              - 95%           - 86%
Sinopharm           - 73%           - 68%

1 - AZ - AstraZeneca 
2 - CV - CoronaVac
3 - CX - Covaxin
4 - JJ - Johnson&Johnson
5 - MD - Moderna
6 - PF - Pfizer
7 - SP - Sinopharm
*/

// Vaccine id for Person[i][j].IsVaccinated

//         0 // no vaccine
#define AZ 1 // AstraZeneca
#define CV 2 // CoronaVac
#define CX 3 // Covaxin
#define JJ 4 // Johnson&Johnson
#define MD 5 // Moderna
#define PF 6 // Pfizer
#define SP 7 // Sinopharm
#define BR 8 // Vaccines received in Brazil

// Vaccine efficacy against severe COVID-19
#define AZ_Eff_S .94 // 
#define CV_Eff_S .50 //
#define CX_Eff_S .78
#define JJ_Eff_S .86
#define MD_Eff_S .97
#define PF_Eff_S .95
#define SP_Eff_S .73

// Vaccine efficacy against COVID-19 infection
#define AZ_Eff_I .63 // 
#define CV_Eff_I .47
#define CX_Eff_I .73
#define JJ_Eff_I .72
#define MD_Eff_I .92
#define PF_Eff_I .86
#define SP_Eff_I .68

// Percentage of doses received - Brazil
#define AZ_Rec .353
#define CV_Rec .202
#define JJ_Rec .080
#define PF_Rec .365

// Vaccination range - Brazil
#define R0 AZ_Rec          //   0  - .353  -> AZ
#define R1 (R0+CV_Rec)     // .353 - .555  -> CV
#define R2 (R1+JJ_Rec)     // .555 - .635  -> JJ
//#define R3 1.            // .635 -   1   -> PF

#define DAYS_LOWER_AGE     1 // days to lower min age for vaccination
#define LOWER_MIN_AGE      3 // lowers min age in LOWER_MIN_AGE years every DAYS_LOWER_AGE days
#define VACCINE_AGE_MIN    5  
