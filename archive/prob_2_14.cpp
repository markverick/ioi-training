#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
int main(){
    int n,d,days,e,first,second,third,forth,fifth,sixth,i;
    system("COLOR 4D");
    printf("Enter the days of this month. [28-31] : ");
    scanf("%d",&n);
    system("COLOR 1D");
    printf("Enter first day of this month. [1-7] : ");
    scanf("%d",&e);
    system("COLOR 3B");
    d=e-1;
    if(n+e>=35&&e<=6&&e && n+e>=33&&e<=4)
    days=(n-6)*5+15;
    if(n+e>=35&&e<=6&&e && !(n+e>=33&&e<=4))
    days=(n-5)*5+12;
    if(!(n+e>=35&&e<=6)&&e && n+e>=33&&e<=4)
    days=(n-5)*5+13;
    if(!(n+e>=35&&e<=6&&e) && !(n+e>=33&&e<=4))
    days=(n-4)*5+10;
    printf("\n\nHow many bucket?? :  %d\n\n\n",days);






    if((n>=28&&n<=31)&&(e>=1&&e<=7)){
    printf("\n\nSU MO TU WE TH FR ST\n");
        for(i=1;i<=7;i++){
            if(i<=d){
                printf("  ");
            }
            else{
                printf("%2d",i-d);
                first=i-d;
            }
            printf(" ");
        }
        printf("\n");
        for(i=1;i<=7;i++){
            printf("%2d",i+first);
            printf(" ");
            second=i+first;
        }
        printf("\n");
        for(i=1;i<=7;i++){
            printf("%2d",i+second);
            printf(" ");
            third=i+second;
        }
        printf("\n");
        for(i=1;i<=7;i++){
            printf("%2d",i+third);
            printf(" ");
            forth=i+third;
        }
        printf("\n");
        for(i=1;i<=7;i++){
            if(i+forth>n)break;
            printf("%2d",i+forth);
            printf(" ");
            fifth=i+forth;
        }
        printf("\n");
        for(i=1;i<=7;i++){
            if(i+fifth>n)break;
            printf("%2d",i+fifth);
            printf(" ");
            sixth=i+fifth;
        }
    }
    else{
        printf("This is not a month!!! BOOOO!!!! [Invalid input]");
    }
    scanf(" ");
}
