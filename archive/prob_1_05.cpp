#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
    int x;
    double pi;
    pi = acos(-1.0);
    system("COLOR 4D");
    scanf("%d",&x);
    printf("%lf",sin((double)x*pi/180));

    scanf(" ");
}
