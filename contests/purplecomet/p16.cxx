#include<bits/stdc++.h>
using namespace std;
int a[6],hsh[12];
int main()
{
	int i,j,k,fk,sm=0,R=0,S=0;
	for(i=1111;i<=9999;i++)
	{
		j=0;
		fk=0;
		k=i;
		sm=0;x
		memset(hsh,0,sizeof hsh);
		while(k>0)
		{
			a[j]=k%10;
			if(a[j]<1||a[j]>6)fk=1;
			k/=10;
			j++;
		}
		if(fk)continue;
		R++;
		// printf("%d %d %d %d\n",a[0],a[1],a[2],a[3]);
		for(j=0;j<4;j++)
		{
			hsh[a[j]]=1;
		}
		for(j=1;j<=6;j++)
		{
			sm+=hsh[j];
		}
		S+=sm;
	}
	printf("%d/%d\n",S,R);
}