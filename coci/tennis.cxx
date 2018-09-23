#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char name[135],str[135],p1[55],p2[55],fed[55]="federer";
int valid[5];
vector<int> x,y,z;
queue<int> q;
int main()
{
	int i,j,k,len,a,b,v,n,fedie=0;
	gets(name);
	sscanf(name,"%s %s",p1,p2);
	gets(str);
	sscanf(str,"%d",&n);
	if(strcmp(p1,fed)==0)
        fedie=1;
    if(strcmp(p2,fed)==0)
        fedie=2;
	while(n--)
    {
        x.clear();y.clear();z.clear();
        gets(str);
        len=strlen(str);
        q.emplace(0);
        for(i=0;i<len;i++)
        {
            if(str[i]==' ')
                str[i]='\0',q.emplace(i+1);
        }
        while(!q.empty())
        {
            sscanf(str+q.front(),"%d:%d",&a,&b);
            x.emplace_back(a);
            y.emplace_back(b);
            if(a>b)
                z.emplace_back(0);
            else
                z.emplace_back(1);
            q.pop();
        }
//        system("pause");
        if(z.size()<=1)
        {
            printf("ne\n");
            continue;
        }
        a=x[0];b=y[0];
        if(a>b)swap(a,b);
        if(b==7&&a==6)
            valid[0]=1;
        else if(b==6&&a<=4)
            valid[0]=1;
        else if(b==7&&a==5)
            valid[0]=1;
        else
            valid[0]=0;
        a=x[1];b=y[1];
        if(a>b)swap(a,b);
        if(b==7&&a==6)
            valid[1]=1;
        else if(b==6&&a<=4)
            valid[1]=1;
        else if(b==7&&a==5)
            valid[1]=1;
        else
            valid[1]=0;
        a=x[2];b=y[2];
        if(a>b)swap(a,b);
        if(b>=6&&b-a>=2)
            valid[2]=1;
        else
            valid[2]=0;
        k=0;
        for(i=0;i<z.size();i++)
        {
            if(valid[i]==0)
            {
                printf("ne\n");
                k=1;
                break;
            }
        }
        if(k)continue;
        k=0;
        for(i=0;i<z.size();i++)
        {
            if(fedie==1)
            {
                if(z[i]==1)
                    k=1;
            }
            if(fedie==2)
                if(z[i]==0)
                    k=1;
        }
        if(k==1)
        {
            printf("ne\n");
            continue;
        }
        if(z.size()==2)
        {
            if(z[0]^z[1]==0)
            {
                printf("da\n");
            }
            else
            {
                printf("ne\n");
            }
        }
        else if(z.size()==3)
        {
            if(z[0]^z[1]==0)
            {
                printf("ne\n");
            }
            else
            {
                printf("da\n");
            }
        }
    }
}
