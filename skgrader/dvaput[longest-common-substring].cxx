#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[200135];
unordered_map<int,int> hsh;
int main()
{
//	freopen("out.txt","w",stdout);
//	freopen("in.txt","r",stdin);
	int n,i,j,k,fst,mid,lst,sum,yo,ye,mc=0,id,fk,ie;
	scanf("%d",&n);
    scanf("%s",s+1);
    fst=1;lst=n;
    while(fst<=lst)
    {
        mid=(fst+lst)/2;
//        printf("%d <- %d -> %d\n",fst,mid,lst);
        sum=0;k=1;yo=0;ye=0;
        hsh.clear();
        for(i=1;i<=mid;i++)
        {
            sum*=37;
            sum+=s[i]-'a';
            k*=37;
        }
        hsh[sum]=1;
        for(i=mid+1;i<=n;i++)
        {
            sum*=37;
            sum+=s[i]-'a';
            sum-=k*(s[i-mid]-'a');
            if(hsh.find(sum)==hsh.end())
            {
                hsh[sum]=i-mid+1;
            }
            else
            {
                fk=0;
                for(j=0;j<mid;j++)
                {
                    if(s[hsh[sum]+j]!=s[i-mid+1+j])
                    {
                        fk=1;
                        break;
                    }
                }
                if(fk==0)
                {
                    yo=i-mid+1;ye=hsh[sum];
                    break;
                }
            }
        }
        if(yo)
        {
            if(mc<mid)
            {
                mc=mid;id=yo;ie=ye;
            }
            fst=mid+1;
        }
        else
        {
            lst=mid-1;
        }
    }
    printf("%d",mc);
//    printf("%d %d\n",ie,id);
//    for(i=ie;i<ie+mc;i++)
//        printf("%c",s[i]);
//    printf("\n");
//    for(i=id;i<ie+mc;i++)
//        printf("%c",s[i]);
}
