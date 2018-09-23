#include<bits/stdc++.h>
using namespace std;
int p[5];
int mn,id;
int main()
{
    int n,cot=0,i,j,k;
    scanf("%d",&n);
    scanf("%d %d %d",&p[0],&p[1],&p[2]);
    for(i=0;i<n;i++)
    {
        mn=1000000000;
        for(j=0;j<3;j++)
        {
            if(i%3==j)
                continue;
            if(p[j]>p[i%3]&&mn>p[j])
            {
                mn=p[j];id=j;
            }
        }
        if(mn!=1000000000)
            p[i%3]+=2*(p[id]-p[i%3]);
        else
            cot++;
    }
    for(i=0;i<3;i++)
        printf("%d\n",p[i]);
}
