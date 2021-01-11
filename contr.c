#include "contr.h"
#include "math.h"

	float pwm_a;
	float pwm_b;
	float pwm_c;
	
float dalpha=0.0377;	
float alpha=0.0;

	
double generat_sine(){
	static double time;
	static double f=60;
	static double u_f=0;
	if(time>=1000) time=0; 
	
	alpha += dalpha*u_f;
	
	pwm_a=1*u_f*sin(alpha);
	pwm_b=1*u_f*sin(alpha+(2*3.14/3));
	pwm_c=1*u_f*sin(alpha-(2*3.14/3));	
	
	time+=0.0001;
	if (u_f<1) u_f+=0.0001;
	else u_f=1;
	
	//u_f = 2*3.14*f*u_f*time;
	
	return 2*3.14*f*u_f*time;
}


double summ_1=0;
double reg(double delta,double Ki,double Kp,double w){
	
	static double Ireg;
	
	static int flG=0;
	if ((w>1 && w<5&& delta>=10)|| (w<-1&&w>-5&& delta<=-10) ) 
summ_1-=(delta*Ki)*8;	
    else summ_1+=delta*Ki;
	
	//summ_1+=delta*Ki;
	//summ+=delta*Ki;
	Ireg=delta*Kp +summ_1;
	
	
	return Ireg;
}