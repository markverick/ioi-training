#include<bits/stdc++.h>
int main()
{
	int i,j,k,n,m=0;
	scanf("%d",&n);
	for(i=1;i<n-1;i++)
        for(j=i+3;j<=n;j++)
            m+=(j-i-2)*(n-j+1);
    printf("%d",m);
}
