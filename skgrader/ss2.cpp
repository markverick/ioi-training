#include<stdio.h>
long long a[2000],b,kill[300000],sum[300000];
int main(){
	int n,k;
	int i,j;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=a[i]+sum[i-1];
	}
	int fst=0,lst=0;
	int max;
	for(i=1;i<=k;i++){
		max=0;fst=0;lst=0;
		scanf("%lld",&b);
		while(true){
			if(lst>n||fst>n)break;
			if(sum[lst]-sum[fst]<=b){
				lst++;
				
			}
			else{
				fst++;

			}
			if(max<lst-fst)max=lst-fst;
			
		}
		printf("%d\n",max-1);
	}
}
/*
4 4
17 10 20 30
50 30 29 7
*/