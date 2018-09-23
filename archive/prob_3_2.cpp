#include<stdio.h>
#include<math.h>;
double fsin(double x){
    return(sin(x));
}
double fcos(double x){
    return(cos(x));
}
int main(){
    double x;
    printf("Enter x : ");
    scanf("%lf",&x);
    printf("sinx is %lf\nsiny is %lf",fsin(x),fcos(x));
    scanf(" ");
}
