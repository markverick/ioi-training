#include<stdio.h>

int main(){
    int n;
    int sum=0;
    double mean;
    int con=0;
    do{
            scanf("%d",&n);
            if(n<0)break;
            sum+=n;
            con+=1;
    }
    while(n>=0);
    printf("The sum is : %d\n",sum);
    printf("The mean is : %lf",(double)sum/con);
    scanf(" ");
}
