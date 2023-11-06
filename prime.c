#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int(isprime(int num))
{
    int i;
    for (i = 0; i <= num / 2; i++)
    {
        /* code */
        if (num % i == 0)
        {
            /* code */
            return 0;
        }
    }
    return 1;
}

int isarmstrong(int num)
{
    int lastdigit, sum, originalnum, digits;
    sum = 0;
    originalnum = num;
    digits = (int)log10(num) + 1;

    while (num > 0)
    {
        /* code */
        lastdigit = num % 10;
        sum = sum + round(pow(lastdigit, digits));
        num = num / 10;
        return (originalnum == sum);
    }
}

int isperfect(int num)
{
    int i, sum, n;
    sum = 0;
    n = num;
    for (i = 1; i < n; i++)
    {
        /* code */
        if (n % i == 0)
        {
            /* code */
            sum += 1;
        }
    }
    return (num == sum);
}
int main(int argc, char const *argv[])
{
    int num;
    printf("enter the numbere");
    scanf("%d", &num);

    if (isprime(num))
    {
        printf("%d is the prime number", num);
    }
    else
    {
        printf("%d is not the prime number\n", num);
    }

    if (isarmstrong(num))
    {
        printf("%d is artstrong number.\n", num);
    }
    else
    {
        printf("%d is not armstrong number.\n", num);
    }

    if (isperfect(num))
    {
        printf("%d is perfect number.\n", num);
    }
    else
    {
        printf("%d is not perfect number.\n", num);
    }
    return 0;
}
