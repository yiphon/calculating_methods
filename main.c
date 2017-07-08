#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ALP 2.5 //��ֵ
#define EPS1 1e-6 //����ֵ��Ӧ�ľ���Ҫ��
#define EPS2 1e-4 //����ֵ��Ӧ�ľ���Ҫ��
#define EPS3 1e-6 //�󵼺����еľ���Ҫ��
#define N 20 //����������
double derivative(double x);
double function(double x);
int main()
{
    int i=1;
    double f,df,x0=ALP,x1,tol;
    for(i=1;i<=N;i++)
    {
        f=function(x0);
        df=derivative(x0);
        if(fabs(f)<EPS1)
        {
            printf("x=%lf",x0);
            break;
        }
        if(fabs(df)<EPS2)
        {
            printf("Failed.\n");
            break;
        }
        x1=x0-f/df;
        tol=fabs(x1-x0);
        if(tol<EPS1)
        {
            printf("x=%lf",x1);
            break;
        }
        x0=x1;
    }
    if(i==N+1)
        printf("Failed.\n");
    return 0;
}
double function(double x)
{
    double y;
    y=64.0*pow(x,6)-480.0*pow(x,4)+720.0*x*x-120.0;
    return y;
}
double derivative(double x)
{
    double dx=1.0,y0,y1,tol;
    int i;
    for(i=1;;i++)
    {
        y0=(function(x+dx)-function(x))/dx;
        dx=dx/2;
        y1=(function(x+dx)-function(x))/dx;
        tol=y0-y1;
        if(fabs(tol)<EPS3)
        {
            return y1;
            break;
        }
    }
}
