#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define a 0
#define b 1
#define N 10
#define EPS 5e-5
double function(double x);
int main()
{
    double h=b-a;
    int m=1,i;
    double t[3],s[3],c[3],r[3],sumoft,k,tol;
    long ii;
    t[1]=0.5*h*(function(a)+function(b));
    printf("t[1]=%lf\n",t[1]);
    for(i=1; i<=N; i++)
    {
        ii=pow(2,i-1);
        sumoft=0;
        for(k=1; k<=ii; k++)
        {
            sumoft+=0.5*h*function(a+(k-0.5)*h);
        }
        t[2]=0.5*t[1]+sumoft;
        printf("t[2]=%lf\n",t[2]);
        s[2]=(1.0/3.0)*(4.0*t[2]-t[1]);
        printf("s[2]=%lf\n",s[2]);
        if(m!=1)
        {
            c[2]=(16.0*s[2]-s[1])/15.0;
            printf("c[2]=%lf\n",c[2]);
            if(m!=2)
            {
                r[2]=(64.0*c[2]-c[1])/63.0;
                printf("r[2]=%lf\n",r[2]);
                if(m!=3)
                {
                    tol=fabs(r[2]-r[1]);
                    if(tol<EPS)
                    {
                        break;
                    }

                    else
                        continue;
                }
            }
        }
        r[1]=r[2];
        c[1]=c[2];
        s[1]=s[2];
        t[1]=t[2];
        h=h/2.0;
        m++;
    }
    return 0;
}
double function(double x)
{
    double y;
    y=4.0/(1.0+x*x);
    return y;
}
