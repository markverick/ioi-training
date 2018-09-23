#include<stdio.h>
int a[220000];
int main(){
	int n;
	int i,j,k,b;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[j+1]<a[j]){
                b=a[j+1];a[j+1]=a[j];a[j]=b;
            }
        }
	}
	for(i=1;i<=n;i++){
		printf("%d\n",a[i]);
	}
}
