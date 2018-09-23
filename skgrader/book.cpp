#include<cstdio>
#include<iostream>

#define mod 1000000007


int a[1001][1001];


int main()
{
   int i;
    a[0][0]=1;
    int j=0;
    for(i=1;i<1001;i++){
      a[i][0]=a[i-1][i-1];
      for(j=1;j<=i;j++){
	  a[i][j]=(a[i][j-1]+a[i-1][j-1]);

	  if(a[i][j]>=mod)
	    a[i][j]-=mod;
	}
    }
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%d\n",a[n-1][n-1]);
    }
    return 0;
}
