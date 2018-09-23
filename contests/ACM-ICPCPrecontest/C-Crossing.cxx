#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int x[100135],hsh[100135];
pair<int,int> p[100135];
vector<pair<int,int> > v,u;
int main()
{
    int i,j,k,n=1;
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
    while(scanf("%d",&x[n])!=EOF)
    {
        if(x[n]==0)
            break;
        if(x[n]>=0)
            p[n]=MP(x[n],1);
        else
            p[n]=MP(-x[n],0);
        n++;
    }
    if(n==1)
    {
        printf("1\n");
        return 0;
    }
    n--;
    int cot=0;
    sort(&p[1],&p[n+1]);
//    n=unique(&p[1],&p[n+1])-&p[1];
    for(i=2;i<=n;i++) ///coexist!
    {
        if(p[i-1].X==p[i].X)
        {
            p[i].Y=-1;
            p[i-1].Y=2;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(p[i].Y>=0)
            v.emplace_back(p[i]);
    }
    if(v[0].Y==2)
        hsh[0]=1;
    for(i=1;i<v.size();i++)
    {
        if(v[i].Y==2)
            hsh[i]=1;
        if(hsh[i]==1||hsh[i-1]==1)
            continue;
        if((v[i-1].Y==1&&v[i].Y==0)||(v[i-1].Y==0&&v[i].Y==1))
        {
            hsh[i]=1;
        }
    }
    cot=0;
    for(i=0;i<v.size();i++)
    {
        if(hsh[i])
            cot++;
    }
    printf("%d",max(1,cot));
//    u.emplace_back(1,v[0].Y);
//    for(i=1;i<v.size();i++)
//    {
////        printf("%d (%d)\n",v[i-1].X,v[i].Y);
//        if(v[i].Y!=v[i-1].Y)
//            u.emplace_back(1,v[i].Y);
//        else
//            u[u.size()-1].X++;
//    }
//    for(i=0;i<u.size();u++)
//    {
//        for(j=i;j<u.size();u++)
//        {
//            if(u[j].Y==2)
//            {
//                cot+=j-i
//                break;
//            }
//            if(u[j].X>1)break;
//        }
//    }
}
