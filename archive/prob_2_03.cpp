#include<stdio.h>
#include<math.h>
int main(){
    double p,m,n,total=0;
    double i,j,k;
    printf("Enter rate % : ");
    scanf("%lf",&p);
    printf("Enter amount to deposit : ");
    scanf("%lf",&m);
    printf("How many year? : ");
    scanf("%lf",&n);
    total=m;
    for(i=1;i<=n;i++){
        total = total*(p+100)/100;

    }
    printf("Total of your money is %lf",total);
    scanf(" ");
}
