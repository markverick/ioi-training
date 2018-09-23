#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define EB emplace_back
using namespace std;
int A,B,C;
int hsh[12][12];
void gen(int idx)
{
    int i,j;
    if(idx>=A*B*C)
    {
        return;
    }
    j=idx;
    a=j%3;
    j/=3;
    b=j%3;
    j/=3;
    c=j%3;
    hsh[a][b]=1;
    gen(idx+1);
}
int main()
{
    int t,T,i,j,k;
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d %d %d %d\n",&A,&B,&C,&m);
        gen(0);
        printf("Case #%d: ",t);
    }
}
