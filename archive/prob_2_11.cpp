#include<stdio.h>
int main()
{
	int n, i,j;
	int cot=0;
	int count[100000];
	scanf("%d", &n);
	for(i=1;i<=n;i++)count[i]=0;
	for(j=1;j<=n;j++){
		for(i=1;i<=j;i++){
			if(j%i==0){
				count[j]+=1;
			}
		}
	}
	for(i=1;i<=n;i++){
		if(count[i]==2){
			cot+=1;
			printf("%d ",i);
		}
	}
	printf("\nThe amount is %d",cot);
}
