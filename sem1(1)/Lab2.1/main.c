#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    int p; //population
    int z; //years
    float y; //counter
    printf("Enter n: ");
    scanf("%d", &n);
    p=1;
    y=p;
    z=1;
    do
    {
    y=y+1/(float)n*y;
    z++;
    }
    while(y<=3*p);
    printf("Population of the city will tripled in %d years",z);
return 0;
}
