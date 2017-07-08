#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define a 0.0 //x的初始取值
#define b 1.0 //x的终值
#define N 20
#define alpha 1.0 //y的初值
double function(double x,double y);
int main()
{
    double x[2],y[2],h,k1,k2,k3,k4;
    int i;
    x[0]=a;
    y[0]=alpha;
    h=(b-a)/N;
    for(i=1;i<=N;i++)
    {
        k1=h*function(x[0],y[0]);
        k2=h*function(x[0]+0.5*h,y[0]+0.5*k1);
        k3=h*function(x[0]+0.5*h,y[0]+0.5*k2);
        k4=h*function(x[0]+h,y[0]+k3);
        x[1]=x[0]+h;
        y[1]=y[0]+1.0/6.0*k1+1.0/3.0*k2+1.0/3.0*k3+1.0/6.0*k4;
        printf("x=%lf,y=%lf\n",x[1],y[1]);
        x[0]=x[1];
        y[0]=y[1];
    }
    return 0;
}
double function(double x,double y)
{
    double z;
    z=-20.0*y+20.0*sin(x)+cos(x);
    return z;
}
