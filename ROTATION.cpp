#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;

int a[120000];
char in[3];
int main()
{
    int T,i,j,k;
    int n,m,r=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(j=0;j<m;j++)
    {
        scanf("%s",in);
        if(in[0]=='C')
        {
            int b;
            scanf("%d",&b);
            r+=b;
            r%=n;
        }
        else if(in[0]=='A')
        {
            int b;
            scanf("%d",&b);
            r-=b;
            while(r<0)
                r+=n;
            r%=n;
        }
        else if(in[0]=='R')
        {
            int b;
            scanf("%d",&b);
            int c=b+r-1;
            while(c<0)
                c+=n;
            c%=n;
            printf("%d\n",a[c]);
        }
    }
}

