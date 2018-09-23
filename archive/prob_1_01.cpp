#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
    int r,h;
    system("COLOR 1D");
    double pi;
    pi = acos(-1);
    printf("\n\n\t\t\tWelcome to the Cylinder Calculator Program\n\n");

    printf("\t\t\t Please enter Radius of Cylinder : ");
    scanf("%d",&r);
    printf("\t\t\t Please enter Height of Cylinder : ");
    system("COLOR 3B");
    scanf("%d",&h);
    system("COLOR 2A");
    printf("The Volume of this Cylinder is : %lf",(double)h*pi*pow((double)r,2));
}
