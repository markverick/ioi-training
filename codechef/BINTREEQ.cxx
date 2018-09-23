#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<int> a,b;
int main()
{
	int Q,i,j,k,u,v,n,tri,x,y,lca,fst,lst,mid,mc;
	scanf("%d",&Q);
	while(Q--)
    {
        scanf("%d %d %d",&n,&u,&v);
        x=u;y=v;
        a.clear();b.clear();
        while(x!=y)
        {
            if(x>y)
            {
                if(x%2)
                    a.emplace_back(1);
                else
                    a.emplace_back(0);
                x/=2;
            }
            else
            {
                if(y%2)
                    b.emplace_back(1);
                else
                    b.emplace_back(0);
                y/=2;
            }
        }
        lca=x;
        fst=0,lst=n;mc=0;
        while(fst<=lst)
        {
            mid=(fst+lst)/2;
            x=mid;y=mid;
            for(i=a.size()-1;i>=0;i--)
            {
                x=x*2+a[i];
                if(x>n)break;
            }
            for(i=b.size()-1;i>=0;i--)
            {
                y=y*2+b[i];
                if(y>n)break;
            }
            if(x<=n&&y<=n)
            {
                mc=max(mc,mid);
                fst=mid+1;
            }
            else
            {
                lst=mid-1;
            }
        }
        printf("%d\n",mc);
    }
}
