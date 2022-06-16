int latency()
{
	int latencytime;
	aleat();
	if(rn<=0.103040)
		latencytime = 1;
	else if(rn>0.103040 && rn<=0.743689)
		latencytime = 2;
	else if(rn>0.743689 && rn<=0.931072)
		latencytime = 3;
	else if(rn>0.931072 && rn<=0.959070)
		latencytime = 4;
	else if(rn>0.959070 && rn<=0.962629)
		latencytime = 5;
	else if(rn>0.962629 && rn<=0.963079)
		latencytime = 6;
	else if(rn>0.963079 && rn<=0.963139)
		latencytime = 7;
	else if(rn>0.963139 && rn<=0.963148)
		latencytime = 8;
	else if(rn>0.963148 && rn<=0.963149)
		latencytime = 9;
	else 
		latencytime = 10; 
 	return latencytime;
}
