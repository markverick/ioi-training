#include<stdio.h>
int main(){
	int i,j,k,count=0,max=0,del=0;
	int x[20],y[20],z[20];
	for(i=1;i<=15;i++){
		scanf("%d",&x[i]);
		y[i]=x[i]%37;
	}
	y[16]=y[1];
	z[1]=y[1];
	for(i=1;i<=15;i++){
		z[i]=0;
	}
	for(i=1;i<=15;i++){
		if(y[i+1]!=y[i]){
			count+=1;
			for(j=1;j<=15;j++){
				if(y[i]==z[j])
			}
			
			z[count]=y[i];
		}
		else{
			
		}
	}
	for(i=1;i<=15;i++){
			printf("%d ",z[i]);
	}
	
}