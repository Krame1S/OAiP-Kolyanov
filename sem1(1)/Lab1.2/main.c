#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,c;
    printf("Enter 3 numbers you want to check: \n");
    scanf("%f%f%f", &a, &b, &c);
    if((a - (int)a) == 0)
    {
    printf("%f is an integer\n",a);
    }
    else
        printf("%f is not an integer\n",a);
    if((b - (int)b) == 0)
    {
    printf("%f is an integer\n",b);
    }
    else
        printf("%f is not an integer\n",b);
    if((c - (int)c) == 0)
    {
    printf("%f is an integer\n",c);
    }
    else
        printf("%f is not an integer",c);
return 0;
}
