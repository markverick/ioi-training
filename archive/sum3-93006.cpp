#include<stdio.h>
int main(){
    int n,j;
    int i[50100];
    int sum=0;
    int sumx=0;
    scanf("%d",&n);
    for(j=1;j<=n;j++){
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
