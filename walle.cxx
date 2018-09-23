#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
char str[1351350];
int len;
set<double> out;
unordered_map<double,int> hsh;
vector<pair<int,double> > vi;
void gen(int idx,int x,int y)
{
    if(idx==len)
    {
        out.insert(sqrt(x*x+y*y));
        hsh[sqrt(x*x+y*y)]++;
        return;
    }
    switch (str[idx+1])
    {
    case 'N':
        gen(idx+1,x,y+1);break;
    case 'S':
        gen(idx+1,x,y-1);break;
    case 'E':
        gen(idx+1,x+1,y);break;
    case 'W':
        gen(idx+1,x-1,y);break;
    case '*':
        gen(idx+1,x,y+1);
        gen(idx+1,x,y-1);
        gen(idx+1,x+1,y);
        gen(idx+1,x-1,y);break;
    }

}
int main()
{
    int i,j,k,sz,cot;
    scanf("%d %s",&len,str+1);
    len=strlen(str+1);
    gen(0,0,0);
    for(auto it=out.begin();it!=out.end();it++)
    {
        vi.emplace_back(hsh[*it],*it);
    }
    sort(vi.begin(),vi.end());
    sz=vi.size();
    for(i=sz-1;i>=0;i--)
    {
        printf("%.3lf %d\n",vi[i].Y,vi[i].X);
    }
}
