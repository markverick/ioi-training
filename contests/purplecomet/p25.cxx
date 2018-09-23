#include<bits/stdc++.h>
using namespace std;
int a[13];
int main()
{
	int n,i,j,k,S=0,R=0,fk=0;
	for(i=5;i<10;i++)a[i]=1;
	do
	{
		// for(i=0;i<10;i++)
		// 	printf("%d ",a[i]);
		// printf("\n");
		fk=0;
		for(i=0;i<  ;i++)
		{
			if(a[i]==1&&a[(i+5)%10]==1)
				fk=1;
		}
		if(fk)S++;
		R++;
	}
	while(next_permutation(&a[0],&a[10]));
	printf("%d/%d %d\n",S,R,S/__gcd(S,R)+R/(__gcd(S,R)));
}