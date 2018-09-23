#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int hsh[55];
int main()
{
    int i,j,k=0,n;
    for(i=1;i<=10;i++)
    {
        scanf("%d",&j);
        hsh[j%42]=1;
    }
    for(i=0;i<42;i++)
        if(hsh[i])
            k++;
    printf("%d",k);
}
