#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int hsh[30],pcol[30135],isodd[30],colid[30135];
char ch[3];
vector<int> v,p;
queue<int> qe,qr;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k,l,a,c,q,odd=0,I,J,K;
	memset(colid,-1,sizeof colid);
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
    {
        scanf("%s %d",ch,&a);
        if(a%2)
            odd++,isodd[a]=1;
        v.emplace_back(ch-'A');
        hsh[ch-'A']=a;
    }
    q=n-odd;
    if(q<0)
    {
        printf("IMPOSSIBLE");
        return 0;
    }
    sort(v.begin(),v.end());
    scanf("%d",&c);
    for(i=1;i<=c;i++)
    {
        scanf("%d",&a);
        a--;
        colid[a]=p.size();
        p.emplace_back(a);
        pcol[a]=1;
    }
    k=0;
    for(i=0;i<n;i++)
    {
        if(qr.empty())
        {
            l=n-i;
            if(hsh[k]%2==0&&q==0)
            {
                qe.emplace(i);
                if(hsh[k]>=(l-1)*2)
                {
                    hsh[k]-=(l-1)*2;
                    for(j=0;j<p.size();j++)
                    {
                        if(p[j]>i)
                        {
                            out[i][j]=k;
                            if(colid[i]>=0)
                                out[p[j]][colid[i]]=k;
                        }
                    }
                    if(hsh[k]==0)
                        k++;
                }
                else
                {
                    I=i;
                    while(135)
                    {
                        if(hsh[k]%2)
                        {
                            if(!qe.empty())
                            {
                                if(pcol[qe.front()])
                                    out[i][i]=k;
                                qe.pop();
                            }
                            else
                            {
                                qr.emplace(k);
                            }
                            hsh[k]--;
                        }
                        J=I+hsh[k]/2-1;
                        for(j=0;j<p.size();j++)
                        {
                            if(p[j]>=I&&p[j]<=J)
                            {
                                out[i][j]=k;
                                if(colid[i]>=0)
                                    out[p[j]][colid[i]]=k;
                            }
                        }
                        hsh[k]=max(0,J-n+1);
                        if(hsh[k]==0)
                            k++;
                        if(J>=n-1)
                            break;
                    }
                }
            }
        }

        if(hsh[k]>=2*l-1)
        {
            if(isodd[k])
            {
                hsh[k]-=2*l-1;
                for(j=0;j<p.size();j++)
                {
                    if(p[j]>=i)
                        out[i][j]=k;
                }
                if(hsh[k]==0)
                    k++;
                isodd[k]=0;
            }
            else if(q>0)
            {
                hsh[k]-=2*l-1;
                for(j=0;j<p.size();j++)
                {
                    if(p[j]>=i)
                        out[i][j]=k;
                }
                if(hsh[k]==0)
                    k++;
                q--;
            }
        }
        else
        {
            if(hsh[k]%2)
            {

            }
        }
    }
    for(i=0;i<v.size();i++)
    {
        if(hsh[v[i]]%2==0)
        {

        }
    }
}
