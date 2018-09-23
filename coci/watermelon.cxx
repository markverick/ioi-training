#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char mat[22][22];
long long bt[22];
long long nxt[1100000],hsh[1100000],a[22],b[22],adj[22],S[1100000],tme[1100000];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long n,h,i,j,k,t,st=0,bit=1,sum=0;
	scanf("%lld %lld",&n,&h);
	for(i=0;i<n;i++)
    {
        scanf("%s",mat[i]);
        k=0;
        for(j=n-1;j>=0;j--)
        {
            k*=2;
            if(mat[i][j]=='1')
                k++,adj[i]++;
        }
        bt[i]=k;
    }
    bit=bt[0];
    sum+=adj[0];
    S[0]=sum;
    long long fk=0;
    for(t=1;t<h;t++)
    {
        st=0;
        hsh[bit]=1;
        for(i=0;i<n;i++)
        {
            if((1<<i)&bit)
            {
                st^=bt[i];
                sum+=adj[i];
            }
            else
            {
                sum+=adj[i]*2;
            }
        }
        nxt[bit]=st;
        bit=st;
        S[t]=sum;
        if(hsh[bit]==1)
        {
            fk=1;
            break;
        }
        tme[bit]=t;
    }
    if(fk==0)
    {
        printf("%lld",sum);
        return 0;
    }
    sum=0;
    long long fst=tme[bit],lst=t,cyc=(lst-fst),sm=S[lst]-S[fst];
    h-=fst+1;
    sum=S[fst];
    sum+=(h/cyc)*sm;
    sum+=S[fst+h%cyc]-S[fst];
    printf("%lld\n",sum);
//    for(i=0;i<h;i++)
//    {
//        printf("> %lld\n",S[i]);
//    }
}
