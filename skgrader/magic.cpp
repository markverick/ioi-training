#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
set<pair<int,int> > hat;
priority_queue<tuple<int,int,int> > del;
///time weight toWeight
int main()
{
    int n,m,i,j,k,ch,ty,w,v,d,x,q,time=0,ti,wei,towei,tmp;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m+n;i++)
    {
        scanf("%d",&ch);
        if(ch==1)
        {
            scanf("%d",&ty);
            switch(ty)
            {
            case 1:
                scanf("%d %d",&w,&v);
                hat.insert({w,v});
                break;
            case 2:
                scanf("%d %d %d",&w,&v,&d);
                hat.insert({w,v});
                del.emplace(-d,w,-1);
                break;
            case 3:
                scanf("%d %d %d %d",&w,&v,&d,&x);
                hat.insert({w,v});
                del.emplace(-d,w,x);
                break;
            }
        }
        else
        {
            if(!hat.empty())
            {
                printf("%d\n",(*hat.begin()).Y);
                hat.erase(hat.begin());
            }
            else
                printf("0\n");
        }
        time++;
        while(true)
        {
            if(del.empty())
                break;
            tie(ti,wei,towei)=del.top();
            ti=-ti;
            //printf(">>%d %d %d\n",ti,wei,towei);
            if(time>=ti)
            {
                if((*hat.lower_bound({wei,0})).X!=wei)
                {
                   //PapNungDiOmeletZa510GookGok
                }
                else if(towei==-1)
                {
                    hat.erase(hat.lower_bound({wei,0}));
                }
                else
                {
                    tmp=(*hat.lower_bound({wei,0})).Y;
                    hat.erase(hat.lower_bound({wei,0}));
                    hat.insert({towei,tmp});
                }
                del.pop();
            }
            else
            {
                break;
            }
        }
    }
}
