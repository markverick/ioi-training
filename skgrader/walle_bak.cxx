#include<bits/stdc++.h>
using namespace std;
char str[20];
int len;
unordered_map<double,int> hsh;
char result[20];
void gen(int idx,int x,int y)
{

    if(idx==len)
    {
        printf("%s\n",result);
        return;
    }
    switch (str[idx+1])
    {
    case 'N':
        result[idx]=str[idx+1];
        gen(idx+1,x,y+1);break;
    case 'S':
        result[idx]=str[idx+1];
        gen(idx+1,x,y-1);break;
    case 'E':
        result[idx]=str[idx+1];
        gen(idx+1,x+1,y);break;
    case 'W':
        result[idx]=str[idx+1];
        gen(idx+1,x-1,y);break;
    case '*':
        result[idx]='N';
        gen(idx+1,x,y+1);
        result[idx]='S';
        gen(idx+1,x,y-1);
        result[idx]='E';
        gen(idx+1,x+1,y);
        result[idx]='W';
        gen(idx+1,x-1,y);break;
    }

}
int main()
{
    int i,j,k;
    scanf("%d %s",&len,str+1);
    len=strlen(str+1);
    gen(0,0,0);
}
