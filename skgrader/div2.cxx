#include<bits/stdc++.h>
using namespace std;
int lcm(int a,int b)
{
    return a*b/__gcd(a,b);
}
int main()
{
    int n,i,j,k,p,q,a,b,c,tmp;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d %d %d",&p,&q,&a,&b,&c);
        if(p>=0&&q>=0)
        {
            p--;
            if(p>=0)
                printf("%d\n",q-q/a-q/b-q/c + q/lcm(a,b)+q/lcm(b,c)+q/lcm(c,a)-q/lcm((lcm(a,b)),c) - ( p-p/a-p/b-p/c + p/lcm(a,b)+p/lcm(b,c)+p/lcm(c,a)-p/lcm((lcm(a,b)),c) ) );
            else
                printf("%d\n",q-q/a-q/b-q/c + q/lcm(a,b)+q/lcm(b,c)+q/lcm(c,a)-q/lcm((lcm(a,b)),c) );
        }
        else if(p<0&&q>=0)
        {
            p=-p;
            printf("%d\n",q-q/a-q/b-q/c + q/lcm(a,b)+q/lcm(b,c)+q/lcm(c,a)-q/lcm((lcm(a,b)),c) + ( p-p/a-p/b-p/c + p/lcm(a,b)+p/lcm(b,c)+p/lcm(c,a)-p/lcm((lcm(a,b)),c) ) );
        }
        else
        {
            tmp=p;
            p=-q;
            q=-tmp;
            p--;
            if(p>=0)
                printf("%d\n",q-q/a-q/b-q/c + q/lcm(a,b)+q/lcm(b,c)+q/lcm(c,a)-q/lcm((lcm(a,b)),c) - ( p-p/a-p/b-p/c + p/lcm(a,b)+p/lcm(b,c)+p/lcm(c,a)-p/lcm((lcm(a,b)),c) ) );
            else
                printf("%d\n",q-q/a-q/b-q/c + q/lcm(a,b)+q/lcm(b,c)+q/lcm(c,a)-q/lcm((lcm(a,b)),c) );
        }
    }
}
