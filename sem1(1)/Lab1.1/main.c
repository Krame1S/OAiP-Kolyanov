#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,i,num1, num2;
    int dig1,dig2,dig3,dig4,dig5,dig6;
    printf("Enter the number of your ticket: ");
    scanf("%d",&num);
    num2=num;
    num1=num;
    for(i=0;num1!=0;i++)
    {
        num1=num1/10;
    }
    if(i==6)
    {
        dig1=num%10;
        num/=10;
        dig2=num%10;
        num/=10;
        dig3=num%10;
        num/=10;
        dig4=num%10;
        num/=10;
        dig5=num%10;
        num/=10;
        dig6=num%10;
        if(dig1+dig2+dig3==dig4+dig5+dig6)
        {
            printf("Ticket %d is a lucky one! Congratulations!!!", num2);
        }
        else
        {
            printf("This ticket is not lucky(");
        }
    }
        else
        {
            printf("It is not a 6 digit number! ");
            printf("\nGood luck next time!");
        }
return 0;
}
