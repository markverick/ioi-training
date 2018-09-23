#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k,a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    printf("%d\n",max(b-a,c-b)-1);
}
