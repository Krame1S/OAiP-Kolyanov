#include <stdio.h>
#include <stdlib.h>

int main()
{
    char mon[10];
    printf("Enter a season: summer, autumn, winter, spring\n");
    scanf("%s", &mon);
    if((mon[0]=='S' || mon[0]=='s') && mon[1]=='u' && mon[2]=='m' && mon[3]=='m' && mon[4]=='e' && mon[5]=='r')
        printf("June, July, August");
    else if((mon[0]=='A' || mon[0]=='a') && mon[1]=='u' && mon[2]=='t' && mon[3]=='e' && mon[4]=='m' && mon[5]=='n')
        printf("September, October, November");
    else if((mon[0]=='W' || mon[0]=='w') && mon[1]=='i' && mon[2]=='n' && mon[3]=='t' && mon[4]=='e' && mon[5]=='r')
        printf("December, January, February");
    else if((mon[0]=='S' || mon[0]=='s') && mon[1]=='p' && mon[2]=='r' && mon[3]=='i' && mon[4]=='n' && mon[5]=='g')
        printf("March, April, May");
    else
        printf("Your inputs are wrong!");
    return 0;
}
