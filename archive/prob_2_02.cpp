#include<stdio.h>
int main(){
    int i,j,k,hi=0,lo=100,sum=0;
    int n;
    for(i=1;i<=10;i++){
        printf("Enter number %d : ",i);
        scanf("%d",&n);
        if(n>hi){
            hi = n;
        }
        if(n<lo){
            lo = n;
        }
        sum = sum+n;
    }
    printf("Sum is %d\n",sum);
    printf("Highest is %d\n",hi);
    printf("Lowest is %d",lo);
    scanf(" ");
}
