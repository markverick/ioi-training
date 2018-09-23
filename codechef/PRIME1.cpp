#include<bits/stdc++.h>
using namespace std;
int hsh[1000135];
vector<int> p;
int main()
{
    int T,n,i,j,k,a,b,prod,bd,fk=0;
    for(i=2;i<=1000000;i++)
    {
        if(hsh[i]==0)
        {
            p.emplace_back(i);
            for(j=i;j<=1000000;j+=i)
                hsh[j]=1;
        }
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&a,&b);
        bd=sqrt(b);bd++;
        if(2>=a&&2<=b)
            printf("2\n");
        for(i=max(3,a%2?a:a+1);i<=b;i+=2)
        {
            fk=0;
            for(j=0;j<p.size();j++)
            {
                if(p[j]>bd)
                    break;
                if(i!=p[j]&&i%p[j]==0)
                {
                    fk=1;
                    break;
                }
            }
            if(fk==0)
                printf("%d\n",i);
        }
        printf("\n");
    }
}
