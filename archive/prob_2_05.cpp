#include<stdio.h>
#include<math.h>
int main(){
    double p=3,m=100,total=0,year=0;
    double i,j,k;

    total=m;
    for(i=1;i<=10000000;i++){
        total = total*(p+100)/100+100;
        year=i;

        if(total>=30000){
            year=i;
            break;

        }
    }
    printf("All money U have if U can buy IPhone (30000 THB) is %lf\n",total);
    printf("How many year? : %d years",(int)year);
    scanf(" ");
}
