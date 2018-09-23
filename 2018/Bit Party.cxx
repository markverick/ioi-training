#include<bits/stdc++.h>
#define MP make_pair
#define X first
#define Y second
using namespace std;
long long M[1135],S[1135],P[1135];
pair<long long,long long> srt[1135];
int main()
{
	long long T,i,j,k,t,R,B,C,fs,md,ls,sm,mn;
	scanf("%lld",&T);
	for(t=1;t<=T;t++)
	{
		fs=0;ls=1500000000000000000;mn=1500000000000000000;
		scanf("%lld %lld %lld",&R,&B,&C);
		for(i=1;i<=C;i++)
		{
			scanf("%lld %lld %lld",&M[i],&S[i],&P[i]);
		}
		while(fs<=ls)
		{
			md=(fs+ls)/2;
			sm=0;
			for(i=1;i<=C;i++)
			{
				if(md<P[i])
					srt[i]=make_pair(0,i);
				else
					srt[i]=make_pair(min(M[i],(md-P[i])/S[i]),i);
			}
			sort(&srt[1],&srt[C+1]);
			for(i=C;i>C-R;i--)
			{
				if(srt[i].X==0)break;
				sm+=srt[i].X;
				// printf("%lld\n",srt[i].X);
			}
			// printf("%lld <-- %lld --> %lld\n = %lld / %lld\n",fs,md,ls,sm,B);
			if(sm>=B)
			{
				mn=min(mn,md);
				ls=md-1;
			}
			else
			{
				fs=md+1;
			}
		}
		printf("Case #%lld: %lld\n",t,mn);

	}
}