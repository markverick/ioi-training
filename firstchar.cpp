#include<bits/stdc++.h>
using namespace std;
map<char,int> hsh;
int str[200];
int main()
{
    int n;
    int j;
    char i;
    int yay=0;
    scanf("%d",&n);
    for(j=0;j<n;j++)
    {
        scanf("%s",str);
        hsh[str[0]]++;
    }
    for(i='a';i<='z';i++)
    {
        if(hsh[i]>=5)
        {
            yay=1;
            printf("%c",i);
        }

    }
    if(yay==0)
            printf("PREDAJA");
}
