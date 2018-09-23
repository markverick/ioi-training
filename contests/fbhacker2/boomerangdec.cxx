#include<bits/stdc++.h>
using namespace std;
char a[100135],b[100135];
vector<int> seq;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,i,j,k,t,n,cot;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        cot=1;seq.clear();
        scanf("%d",&n);
        scanf("%s %s",a,b);
        for(i=1;i<n;i++)
        {
            if(b[i]==b[i-1])
            {
                cot++;
            }
            else
            {
                seq.emplace_back(cot);cot=1;
            }
        }
        seq.emplace_back(cot);
        int mid=0;
        for(i=(seq.size()-1)/2;i>=0;i--)
        {
            mid+=seq[i];
        }
        mid--;
        for(i=mid;i>=0;i--)
        {
            if(a[i]!=b[i])
                break;
        }
        for(j=mid+1;j<n;j++)
        {
            if(a[j]!=b[j])
                break;
        }
//        printf("%d %d %d\n",i,mid,j);
        int sum=0;
        int mc=0;
        if(i>=0)
        for(k=0;k<seq.size();k++)
        {
            sum+=seq[k];
            if(sum>=i+1)
            {
                mc=max(mc,k+1);
                break;
            }
        }
        sum=0;
        if(j<n)
        for(k=seq.size()-1;k>=0;k--)
        {
            sum+=seq[k];
            if(sum>=n-j)
            {
                mc=max(mc,(int)seq.size()-k);
                break;
            }
        }
        printf("Case #%d: %d\n",t,mc);
//        for(i=0;i<seq.size();i++)
//        {
//            printf("%d ",seq[i]);
//        }
//        printf("\n");
    }
}
