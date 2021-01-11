#include "contr.h"
#include "math.h"

yst_pwm sine_1;
yst_pwm generat_sine(double f){
	static float time;
	typedef yst_pwm sine;
	sine.pwm_a=320*sin(2*3.14*f*time);
	sine.pwm_b=320*sin(2*3.14*f*time+(2*3.14/3));
	sine.pwm_c=320*sin(2*3.14*f*time-(2*3.14/3));	
	
	time+=0.00001;
	return sine;
}


double summ_1=0;
double reg(double delta,double Ki,double Kp,double w){
	
	static double Ireg;
	
	static int flG=0;
	if ((w>1 && w<5&& delta>=10)|| (w<-1&&w>-5&& delta<=-10) ) summ_1-=(delta*Ki)*8;	
    else summ_1+=delta*Ki;
	
	//summ_1+=delta*Ki;
	//summ+=delta*Ki;
	Ireg=delta*Kp +summ_1;
	
	
	return Ireg;
}