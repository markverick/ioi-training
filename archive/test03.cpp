#include<stdio.h>
int main(){
	int n[38],x[20],y[20];
	int i,j,k,count=0;

	for(i=0;i<38;i++){
		n[i]=0;
	}

	for(i=1;i<=15;i++){
		scanf("%d",&x[i]);
		y[i]=x[i]%37;
	}
	for(i=1;i<=15;i++){
		for(j=0;j<=37;j++){
			if(y[i]==j){
				n[j]+=1;
			}
		}
	}
	for(i=0;i<=37;i++){
		if(n[i]>0){
			count+=1;
		}
	}
	printf("%d",count);
}