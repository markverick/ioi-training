#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<map>
using namespace std;
char str[100000];
map<int,pair<char,int> >jum;
//index = m
int n,m;
int main()
{
    int i,j,k;
    scanf("%d %d",&n,&m);
    for(k=0;k<n*m;k++)
    {
        //system("pause");
        int p;
        scanf("%s",str);
        int q,w,e,r;
        sscanf(str,"[%d]<%d,%d,%d,%d>",&p,&q,&w,&e,&r);
        if(e+r==2*q)
        {
            jum[p].first='b';jum[p].second=(e-r)/2;
            //printf("b %d\n",jum[in]);
        }
        else if(e-r==2*w)
        {
            jum[p].first='a';jum[p].second=(e+r)/2;
            //printf("a %d\n",jum[in]);
        }

        //printf("==%d %d %d %d %d\n",p,a[p],b[p],c[p],d[p]);
    }
    int in;
    int t;
    scanf("%d",&t);

    for(i=0;i<t;i++)
    {
        scanf("%d",&in);
        if(jum[in].first>0)
        {
            printf("%c %d\n",jum[in].first,jum[in].second);
        }

    }
}

/*
3 3
[3]<1,2,4,0>[7]<1,1,1,1>[31]<3,2,4,0>
[2]<9,6,16,2>[25]<0,0,-1,1>[17]<3,3,5,1>
[1]<9,5,5,-5>[9]<3,7,15,1>[6]<6,4,8,0>
3
17
31
1
*/
