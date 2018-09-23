#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,k,a,b=-1;
    int stk=0;
    int p,q;
    scanf("%d",&n);
    p=n;q=n;
    for(i=0;i<n*2;i++)
    {
        //printf("%d %d %d\n",p,q,stk);
        scanf("%d",&a);
        if(a%2==b%2)
        {
            stk++;
            if(a%2==0&&stk<2)
                p--;
            else if(a%2==0&&stk>=2)
                p-=3;
            else if(a%2==1&&stk<2)
                q--;
            else if(a%2==1&&stk>=2)
                q-=3;
        }
        else
        {
            stk=0;
            if(a%2==0)p--;
            else q--;
        }
        b=a;
        if(p<=0)
        {
            printf("0\n%d",a);
            break;
        }
        if(q<=0)
        {
            printf("1\n%d",a);
            break;
        }
    }
}
