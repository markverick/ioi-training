#include<bits/stdc++.h>
using namespace std;
int len;char str[1135],jum=0;
void gen(int start,int idx)
{
    printf("%d %d\n",start,idx);
    if(idx>=len)return;
    if(str[idx]=='_')
    {
        jum=idx+1;
        return;
    }
    gen(start,idx+1);
    printf("%c",str[idx]);
    if(idx==start)
    {
        printf("_");
    }
    gen(jum,jum);
}
int main()
{
    scanf("%s",str);
    len=strlen(str);
    gen(0,0);
}
