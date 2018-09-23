#include<bits/stdc++.h>
using namespace std;
vector<double> dx;
vector<double> dy;
//vector<double> db;
int x[200135],y[200135];
int ax,ay,bx,by,T,t;
int main()
{
    int n,i,j,k,X,Y,C=1;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            return 0;
        printf("Case %d:\n",C);
        C++;
        dx.clear();
        dy.clear();
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&x[i],&y[i]);
        }
        scanf("%d %d %d %d %d",&ax,&ay,&bx,&by,&T);
        for(i=1;i<=n;i++)
        {
            dx.emplace_back(hypot(x[i]-ax,y[i]-ay) );
            dy.emplace_back(hypot(x[i]-bx,y[i]-by) );
           // db.emplace_back(max(hypot(x[i]-bx,y[i]-by),hypot(x[i]-ax,y[i]-ay) ) );
        }
        sort(dx.begin(),dx.end());
        sort(dy.begin(),dy.end());
        int z=0;
        int a,b,c;
        for(t=1;t<=T;t++)
        {
            scanf("%d %d",&X,&Y);
            a=upper_bound(dx.begin(),dx.end(),X)-dx.begin();
            b=upper_bound(dy.begin(),dy.end(),Y)-dy.begin();
            //c=upper_bound(db.begin(),db.end(),X)-db.begin();
            printf("%d\n",max(0,n-a-b));
        }
    }
}
