#include<stdio.h>
#include<math.h>;

double cyl(double r,double h){
    return(M_PI*r*r*h);
}

int main(){
    double r,h;
    printf("Enter r : ");
    scanf("%lf",&r);
    printf("Enter h : ");
    scanf("%lf",&h);
    printf("The Volume is %lf",cyl(r,h));
    scanf(" ");
}
