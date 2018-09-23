#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
    double x,y,h,k,r;
    system("COLOR 2A");
    printf("Enter x0 y0 r x y");
    scanf("%lf %lf %lf %lf &lf &lf",&h,&k,&r,&x,&y);
    if(pow(x-h,2)+pow(y-k,2)<r*r){
        printf("This dot is in the circle!");
    }
    else if(pow(x-h,2)+pow(y-k,2)==r*r){
        printf("This dot is the Point of Tangency!");

    }
    else{
        printf("This dot is NOT in the circle!");
    }
    scanf(" ");
}
