#include<bits/stdc++.h>
using namespace std;
void swap(int *p,int *q)
{
    int tmp=*p;
    *p=*q;
    *q=tmp;
}
vector<int> v;
int main()
{
    int T,a,b,i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d/%d",&a,&b);
        v.clear();
        while(a>1||b>1)
        {
            if(a>b)
            {
                v.emplace_back('R');
                a-=b;
                swap(&a,&b);
            }
            else
            {
                v.emplace_back('L');
                swap(&a,&b);
                a-=b;
            }
        }
        for(i=0;i<v.size();i++)
        {
            printf("%c",v[i]);
        }
        printf("\n");
    }
}
