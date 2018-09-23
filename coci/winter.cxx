#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[100135],hsh[100135],qs[100135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,w;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<0)
            a[i]=-1;
        else
            a[i]=1;
    }
    j=1;
    int cot=0,mc=0;
    vector<pair<int,int> > v;
    for(i=1;i<=n;i++)
    {
        if(a[i]==-1)
        {
            j=i;
            while(a[i]==-1)
                i++;
            i--;
            w=(i-j+1);
            v.emplace_back(j,i);
            mc=max(mc,w);
            w*=2;
            for(k=max(1,j-w);k<j;k++)
            {
                if(hsh[k]==0)
                    hsh[k]=1,cot++;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        if(hsh[i]==0)
            qs[i]=qs[i-1]+1;
        else
            qs[i]=qs[i-1];
    }
    int m=0;
//    printf("%d\n",cot);
    for(i=0;i<v.size();i++)
    {
//        printf("%d %d\n",v[i].X,v[i].Y);
        w=v[i].Y-v[i].X+1;
        if(w<mc)
            continue;
        m=max(m,qs[max(0,v[i].X-w*2-1)]-qs[max(0,v[i].X-w*3-1)]);
//        printf("%d %d %d\n",max(0,v[i].X-w*2-1),max(0,v[i].X-w*3-1),m);
    }
    printf("%d",cot+m);
}
