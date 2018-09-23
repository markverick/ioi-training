#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[5135];
unordered_map<int,int> hsh;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,tod;
	scanf("%d %*d",&n);
	for(i=2;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i]--;
        hsh[a[i]]=1;
    }
//    scanf("%d",&tod);
//    tod--;
    int cot=0;
    for(i=1;i<=n;i++)
    {
        if(hsh[a[i]]==1)
        {
            for(j=a[i];j<=a[n];j+=a[i])
            {
                if(hsh[j]==1)
                    hsh[j]=0;
            }
            cot++;
        }
    }
    printf("%d",cot);
}
