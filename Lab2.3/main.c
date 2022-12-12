#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,x,y;
    printf("Enter A:");
    x=scanf("%d",&a);
    if(x==1)
    {
    printf("Enter B:");
    y=scanf("%d",&b);
        if(y==1)
        {
            while(a!=0 && b!=0)
            {
                if(a>b)
                    a=a%b;
                else
                    b=b%a;
            }
        printf("NOD=%d", a+b);
        }
        else
        {
            printf("Your inputs are wrong!!!");
        }
    }
    else
    printf("Your inputs are wrong!!!");
return 0;
}

