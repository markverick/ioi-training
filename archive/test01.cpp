#include<stdio.h>
int main(){
	int d,i,j,k;
	int n[30],v[30][1200],e[30][1200],o[30][1200],m[i];
	scanf("%d",&d);
	for(i=1;i<=d;i++){
		scanf("%d",&n[i]);
			for(j=1;j<=n[i];j++){
				scanf("%d",&v[i][j]);
			}
		for(j=1;j<=n[i];j++){
			if(j%2==0){
				e[i][j/2]=v[i][j];			
			}
			if(j%2==1){
				o[i][j/2+1]=v[i][j];
			}
		}
	}
	for(i=1;i<=d;i++){
		if(n[i]%2==1){
			for(j=1;j<=n[i]/2;j++){
				printf("%d ",e[i][j]);
			}
			for(j=1;j<=n[i]/2+1;j++){
				printf("%d ",o[i][j]);
			}
		}
		if(n[i]%2==0){
			for(j=1;j<=n[i]/2;j++){
				printf("%d ",e[i][j]);
			}
			for(j=1;j<=n[i]/2;j++){
				printf("%d ",o[i][j]);
			}
		}
		printf("\n");
	}
}