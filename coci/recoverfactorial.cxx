#include<bits/stdc++.h>
#define MI 1000000000
#define BD 10000001
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int hsh[BD+5],H[BD+5],chk[BD+5];
int num[BD+5],pos[BD+5];
vector<int> pr;
int main()
{
//	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	memset(H,-1,sizeof H);
	int i,j,k,n;
	for(i=2;i<=BD;i++)
    {
        if(chk[i]==0)
        {
            pos[i]=pr.size();
            pr.emplace_back(i);
            for(j=i;j<=BD;j+=i)
                chk[j]=1;
        }
    }
	for(i=2;i<=BD;i++)
    {
        k=i;
        num[i]=num[i-1];
        for(j=0;j<pr.size();j++)
        {
            if(pr[j]*pr[j]>k)
                break;
            while(k%pr[j]==0)
            {
                hsh[j]++;num[i]++;
                k/=pr[j];
            }
        }
        if(k>1)
            hsh[pos[k]]++,num[i]++;
        if(num[i]>BD)
            break;
        H[num[i]]=i;
    }
    H[0]=0;
    H[1]=2;
    int t=0;
    while(scanf("%d",&n)!=EOF)
    {
        if(n<0)
            return 0;
        printf("Case %d: ",++t);
        if(H[n]>=0)
            printf("%d!\n",H[n]);
        else
            printf("Not possible.\n");
    }
}
