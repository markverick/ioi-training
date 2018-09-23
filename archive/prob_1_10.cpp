#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
    double a,b,c,x1,x2,y1,y2,m,p,q;
    char o1,o2;
    system("COLOR 1D");
    printf("\n\n\t \tWelcome to the Linear Equation Calculator Program\n\n");
    printf("\n\t\t\t=====[ Ax^2 + By + C = 0 ]====== \n\n");
    printf("\t\t\t Please enter A : ");
    scanf("%lf",&a);
    printf("\t\t\t Please enter B : ");
    system("COLOR 3B");
    scanf("%lf",&b);
    system("COLOR 2A");
    printf("\t\t\t Please enter C : ");
    scanf("%lf",&c);
    system("COLOR 4D");
    x1=((-b+sqrt(pow(b,2)-4*a*c))/(2*a));
    x2=((-b-sqrt(pow(b,2)-4*a*c))/(2*a));
    y1=abs(x1);
    y2=abs(x2);
    m = sqrt(4*a*c - b*b);
    if(x1>0){
        o1 = '-';
    }
    else{
        o1 = '+';
    }
    if(x2>0){
        o2 = '-';
    }
    else{
        o2 = '+';
    }
    if(b*b-(4*a*c)>0){
        printf("\t\t - The factor is (x %c %lf) or (x %c %lf)\n",o1,y1,o2,y2);
        p = (-b+sqrt((b*b)-4*a*c))/(2*a);
        q = (-b-sqrt((b*b)-4*a*c))/(2*a);
        printf("\t\t - The answer is %.1f,%.1f\n",p,q);
    }
    else if(b*b-(4*a*c)==0){
        printf("\t\t - The factor is (x %c %lf)^2\n",o1,y1);
        p = -b/(2*a);
        printf("\t\t - The answer is %.1f\n",p);
    }
    else{
        printf("\t\t - The answer is %1f %+1f i,%1f %+1f i\n",((-1)*b)/(2*a),m,((-1)*b)/(2*a),(-1)*m);
    }
    scanf(" ");
}
