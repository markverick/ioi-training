#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<int> v;

int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,a,b,x,y;
	scanf("%d %d",&a,&b);
	if(a==0)
    {
        printf("0\n0");
        return 0;
    }
	while(a%b!=0)
    {
//        printf("%d %d\n",a,b);
//        system("pause");
        v.emplace_back(a/b);
        y=a%b;x=b;
        a=x;b=y;
    }
    k=a/b;
    v.emplace_back(k-1);
    v.emplace_back(1);
    printf("%d\n",v.size()-1);
    for(i=0;i<v.size();i++)
    {
        printf("%d ",v[i]);
    }
}
