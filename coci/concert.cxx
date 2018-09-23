#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int hsh[100135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,nn,m,mm,a;
	vector<int> va,vb;
	scanf("%d %d",&n,&nn);
	for(i=1;i<=nn;i++)
    {
        scanf("%d",&a);
        hsh[a]=1;
    }
    for(i=1;i<=n;i++)
        if(!hsh[i])
            va.emplace_back(i);
    scanf("%d %d",&m,&mm);
	for(i=1;i<=mm;i++)
    {
        scanf("%d",&a);
        vb.emplace_back(a);
    }
    j=0;
    for(i=0;i<vb.size();i++)
    {
        if(j>=va.size())
            break;
        hsh[va[j]]=1;
        printf("GIVE GIRL %d GUY %d\n",vb[i],va[j]);
        j++;
    }
//    if(j>=va.size())
//    {
//        for(i=i;i<vb.size();i++)
//            printf("GIVE GIRL %d GUY %d\n",vb[i],1);
//    }
    int cot=0,x;
    vector<int> missed,yay;
    for(i=1;i<=n;i++)
    {
        if(hsh[i])
            printf("ENTER GUY %d\n",i),yay.emplace_back(i);
        else
            missed.emplace_back(i);
    }
    if(yay.size()<2)
        return 0;
    ///EXPLOITATION BEGINS!
    for(i=0;i<missed.size();i++)
    {
            printf("GIVE GUY %d GUY %d\n",yay[0],yay[1]);
            printf("EXIT GUY %d\n",yay[1]);
            printf("GIVE GUY %d GUY %d\n",yay[1],missed[i]);
            printf("ENTER GUY %d\n",missed[i]);
            printf("ENTER GUY %d\n",yay[1]);
            printf("GIVE GUY %d GUY %d\n",missed[i],yay[0]);
    }
}
