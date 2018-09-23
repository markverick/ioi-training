#include<stdio.h>
#include<string.h>
int cot[1000];
int main(){
    int n;
    char a[1000];
    int len;
    int sum=0;
    int j=0;
    int i;
    scanf("%s",a);
    len = strlen(a);
    for(i=0;i<len;i++){
        if(a[i]=='('){
            cot[j]++;
           }
        if(a[i]==')'){
            cot[j]--;
        }
        if(cot[j]<0){
            sum++;
            j++;
        }
    }
    //printf("%d ",sum);
    sum+=cot[j]<0?-cot[j]:cot[j];
    printf("%d",sum);



}
