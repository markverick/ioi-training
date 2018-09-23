#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n,t,tmp,mc,mn,i,c=0;
    while(scanf("%d %d %d",&m,&n,&t)!=EOF)
    {
        mc=-1;mn=1000000000;
        if(m<n)
        {
            tmp=m;m=n;n=tmp;
        }
        for(i=0;i*n<=t;i++)
        {
            if( (t-i*n)%m==0 )
            {
                mc=max(mc,i+(t-i*n)/m );
            }
            if(mn>=(t-i*n)%m)
            {
                mn=(t-i*n)%m;
                c=i+(t-i*n)/m;
            }
        }
        if(mc>=0)
            printf("%d\n",mc);
        else
        {
            printf("%d %d\n",c,mn);
        }
    }

}
