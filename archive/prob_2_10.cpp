#include<stdio.h>
int main()
{
	int n,i;
	int cot=0;
	int count=0;
	scanf("%d",&n);
    for(i=1;i<=n;i++){
        if(n%i==0){
            count+=1;
        }
    }
    if(count==2)
        printf("This number is Prime!");
    else
        printf("This number is NOT prime!");

}
