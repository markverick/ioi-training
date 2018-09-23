#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T,a,b,c,sum;
    scanf("%d",&T);
    while(T--)
    {
        sum=0;
        scanf("%d %d",&a,&b);
        while(true)
        {
            if(a<b)
            {
                c=a;a=b;b=c;
            }
            //printf("%d %d\n",a,b);
            if(a==1)break;
//            system("pause");
            sum+=a/b;
            a-=a/b*b;
        }
        printf("%d\n",sum-1);
    }
}
