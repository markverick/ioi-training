#include<bits/stdc++.h>
using namespace std;

//char maps[260][260];
int main()
{
    //maps['1']['1']='1';maps['1']['i']='i';maps['1']['j']='j';maps['1']['k']='k';
    //maps['i']['1']='i';maps['i']['i']='0';maps['i']['j']='k';maps['i']['k']='y';
    //maps['j']['1']='j';maps['j']['i']='k';maps['j']['j']='0';maps['j']['k']='x';
    //maps['k']['1']='k';maps['k']['i']='j';maps['k']['j']='x';maps['k']['k']='0';
    int T,t,i,j,k;
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        string s;
        string str;
        int n,m;
        scanf("%d %d",&n,&m);
        cin >> s;
        for(j=0;j<m;j++)
        {
            str+=s;
        }
        cout << str<<"\n";
        int op=0;
        for(i=0;i<n;i++)
        {

        }
    }
}
