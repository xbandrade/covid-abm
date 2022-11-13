# covidABM
### Trabalho de Conclusão de Curso de Física Computacional

Autor: Bruno Silva de Andrade

Orientador: Dr. Aquino Lauri de Espíndola

<br/>

Modelo baseado em agentes para análise do impacto de medidas de vacinação e isolamento social na prevalência da COVID-19 no Brasil.

Modelo implementado usando a linguagem C e paralelizado com MPI.

<br/>


➡️**make clean; make; mpirun -np (númeroDeProcessos) ./covid.x (vacina) (isolamentoSocial) (proporçãoIsolamento) (inícioIsolamento) (porcentagemVacinação) (inícioVacinação)**

> - vacina: 0 - Sem Vacinação; 1 - AstraZeneca; 2 - CoronaVac; 4 - Janssen; 6 - Pfizer; 8 - Conjunto de vacinas usadas no Brasil
> - isolamentoSocial: 0 - Sem isolamento social; 1 - Com isolamento social
> - proporçãoIsolamento: [0-100] - Porcentagem da população que segue as medidas de isolamento
> - inícioIsolamento: [0-400] - Dias até o início do isolamento social
> - porcentagemVacinação: [0-100] - Porcentagem da população elegível que segue as recomendações de vacinação
> - inícioVacinação: [0-400] - Dias até o início da vacinação
