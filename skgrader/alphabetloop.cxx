#include<bits/stdc++.h>
using namespace std;
char str[120];
int val[520];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,i,j,k,len,t;
    scanf("%d",&T);
    val['A']=1;val['B']=2;val['D']=1;val['O']=1;val['P']=1;val['Q']=1;val['R']=1;
    for(t=1;t<=T;t++)
    {
        scanf("%s",str);
        len=strlen(str);
        int cot=0;
        for(i=0;i<len;i++)
        {
            cot+=val[str[i]];
        }
        printf("Case #%d\n%d\n",t,cot);
    }
}
