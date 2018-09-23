#include<stdio.h>
int main(){
    int a[50];
    int i,j,k;
    int sum[55];
    int smax=0;
    printf("Enter 50 numbers");
    for(i=0;i<50;i++){
        scanf("%d",&a[i]);
    }
    a[50]=0;
    for(i=0;i<50;i++){
        sum[i] = a[i]+a[i+1];
    }
    for(i=0;i<50;i++){
        if(smax<=sum[i]){
            smax=sum[i];
        }
    }
    printf("Max of sum nearby is : %d",smax);
    scanf(" ");
}
