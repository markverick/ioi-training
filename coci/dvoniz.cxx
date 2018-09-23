#include<bits/stdc++.h>
using namespace std;
int qs[100135],chk[100135];
int main()
{
	int n,s,i,j,k,fst,mid,lst,mc,a;
	scanf("%d %d",&n,&s);
	for(i=1;i<=n;i++)
    {
        scanf("%d",&qs[i]);
        qs[i]+=qs[i-1];
    }
    for(i=1;i<n;i++)
    {
        fst=0;lst=min(i,n-i);mc=0;
        while(fst<=lst)
        {
            mid=(fst+lst)/2;
            if(qs[i]-qs[i-mid]<=s&&qs[i+mid]-qs[i]<=s)
            {
                mc=max(mc,mid);
                fst=mid+1;
            }
            else
                lst=mid-1;
        }
        chk[i-mc+1]=max(chk[i-mc+1],mc);
    }
    for(i=1;i<=n;i++)
    {
        printf("%d\n",chk[i]*2);
        chk[i+1]=max(chk[i]-1,chk[i+1]);
    }
}
