#include<bits/stdc++.h>
using namespace std;
char s[5];
int a[5];
int main()
{
	int i,j,k;
	scanf("%d %d %d",&a[0],&a[1],&a[2]);
	sort(&a[0],&a[3]);
	scanf("%s",s);
	for(i=0;i<3;i++)
        printf("%d ",a[s[i]-'A']);
}
