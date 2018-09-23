#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[10];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,fk=0;
	for(i=1;i<=8;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=8;i++)
    {
        if(a[i]!=i)
            fk=1;
    }
    if(fk==0)
    {
        printf("ascending");
        return 0;
    }
    fk=0;
    for(i=1;i<=8;i++)
    {
        if(a[i]!=9-i)
            fk=1;
    }
    if(fk==0)
    {
        printf("descending");
        return 0;
    }
    printf("mixed");
}
