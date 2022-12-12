
#include <stdio.h>
#include <stdlib.h>

int main() {
    double Pi = 1;
    double h=3;
    double j=5;
    for(int i = 0; i < 500; i++)
    {
        Pi=Pi-(1/h)+(1/j);
        h=h+4;
        j=j+4;
    }
    printf("Pi = %.10f", 4*Pi);
    return 0;
}
