#include<stdio.h>
int main(){
    int n,j,j,k;
    int i[21000];
    int sum=0;
    int sumx=0;
    for(j=0;j<=21000;j++){
    	i[j]=0
    }
    for(j=1;j<=21000;j++){
        scanf("%d",&i[j]);
    }
    for(j=n;j>=1;j--){
        sum = sum+i[j];
    }
    sumx=sum;
    for(j=1;j<=n;j++){
        printf("%d ",sumx);
        sumx=sumx-i[j];
    }
}