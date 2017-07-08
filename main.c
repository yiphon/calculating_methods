#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10 //共给出N+1个点的值
#define M 5 //需要计算的点有M个
double function(double x);
double lagrangeinterpolation(double a[2][N+1],double x[M]);
int main()
{
    double given[2][N+1],x[M];
    int i;
    for(i=0;i<=M-1;i++)
    {
        scanf("%lf",&x[i]);
        printf("x[%d]=%lf\n",i,x[i]);
    }
    memset(given,0,sizeof(given));
    for(i=0;i<=N;i++)
    {
        scanf("%lf",&given[0][i]);
        given[1][i]=function(given[0][i]);
    }
    lagrangeinterpolation(given,x);
    return 0;
}
double lagrangeinterpolation(double a[2][N+1],double x[M])
{
    double y[M],l=0.0;
    int k=0,j,i;
    for(i=0;i<=M-1;i++)
    {
        y[i]=0.0;
        for(k=0;k<=N;k++)
        {
            l=1.0;
            for(j=0;j<=N;j++)
            {
                if(j==k)
                continue;
                else
                {
                    l=l*(x[i]-a[0][j])/(a[0][k]-a[0][j]);
                }
            }
            y[i]=y[i]+l*a[1][k];
        }
        printf("x[%d]=%lf,y[%d]=%lf\n",i,x[i],i,y[i]);
    }
    return 0.0;
}
double function(double x)
{
    double y=0.0;
    y=1.0/(1+25.0*x*x);
    return y;
}
