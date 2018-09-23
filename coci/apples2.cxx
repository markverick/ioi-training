#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;

int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
    int i,j,k,n,m,q,fst,lst,a,cot=0;
    scanf("%d %d",&n,&m);
    fst=1;lst=m;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&a);
        while(lst<a)
        {
            lst++;fst++;cot++;
        }
        while(fst>a)
        {
            lst--;fst--;cot++;
        }
    }
    printf("%d",cot);
}
