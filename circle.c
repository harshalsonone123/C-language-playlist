#include <stdio.h>
#include <math.h>
#include<stdlib.h>

double getdiameter(double r)
{
    return (2 * r);
}
double getcircum(double r)
{
    return (2 * 3.14 * r);
}
double getarea(double r)
{
    return(3.14*r*r);
}
int main()
{
    float r, d,c, a;

    printf("enter the radius of the circle:");
    scanf("%f",&r );

    d =  getdiameter(r);
    c =  getcircum(r);
    a =  getarea(r);

    printf("diameter is %.2f \n", d);
    printf("circumferance is %.2f \n ", c);
    printf("area is %.2f \n", a);
    

    return 0;
}
