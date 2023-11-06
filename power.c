#include <stdio.h>
double pow(double base, int expo)
{
    if (expo == 0)
    {
        return 1;
        /* code */
    }
    else if (expo > 0)
    {
        return base * pow(base, expo - 1);
        /* code */
    }
    else
    {
        return 1 / pow(base, -expo);
        /* code */
    }
}

int main(int argc, char const *argv[])
{
    double base, power;
    int expo;

    printf("enter base:");
    scanf("lf", &base);
    printf("enter exponents:");
    scanf("%d", &expo);

    power = pow(base, expo);
    printf("%2lf ^ %d =%f", base, expo, power);

    return 0;
}
