#include<bits/stdc++.h>
#define M 300007
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char a[250135],b[250135];
int ha[300135],hb[300135],hsh[300135];
vector<int> x,y,yy;
int main()
{
	freopen("out.txt","w",stdout);
	freopen("in.txt","r",stdin);
	int i,j,k,l,ii,A,B,fst=0,mid,lst,mc=0,fu,fk,ID,II;
	scanf("%s %s",b,a);
    A=strlen(a);B=strlen(b);
    lst=min(A,B);
    while(fst<=lst)
    {
        x.clear();y.clear();
        memset(ha,0,sizeof ha);
        memset(hb,0,sizeof hb);
        memset(hsh,0,sizeof hsh);
        mid=(fst+lst)/2;
//        printf("%d <- %d -> %d\n",fst,mid,lst);
        j=0;k=1;
        for(i=0;i<mid;i++)
        {
            j*=37;k*=37;
            j+=a[i]-'a';
            j%=M;k%=M;
        }
        x.emplace_back(j);
        ha[j]=1;
        for(i=mid;i<A;i++)
        {
            j*=37;
            j+=a[i]-'a';
            j-=k*(a[i-mid]-'a');
            while(j<0)
                j+=M;
            j%=M;
            x.emplace_back(j);
            ha[j]=1;
        }
        j=0;k=1;
        for(i=0;i<mid;i++)
        {
            j*=37;k*=37;
            j+=b[i]-'a';
            j%=M;k%=M;
        }
        y.emplace_back(j);
        hb[j]=1;
        for(i=mid;i<B;i++)
        {
            j*=37;
            j+=b[i]-'a';
            j-=k*(b[i-mid]-'a');
            while(j<0)
                j+=M;
            j%=M;
            y.emplace_back(j);
            hb[j]=1;
        }
        fu=0;
        for(ii=0;ii<x.size();ii++)
        {
            i=x[ii];
            if(hsh[i])continue;
            hsh[i]=1;
            if(ha[i]==1&&hb[i]==1)
            {
                yy.clear();
                for(j=0;j<y.size();j++)
                {
                    if(y[j]==i)yy.emplace_back(j);
                }
                for(j=0;j<x.size();j++)
                {
                    if(x[j]==i)
                    {
                        for(k=0;k<yy.size();k++)
                        {
                            fk=0;
                            for(l=0;l<mid;l++)
                            {
                                if(a[j+l]!=b[yy[k]+l])
                                {
                                    fk=1;break;
                                }
                            }
                            if(fk==0)
                            {
                                ID=j;
                                fu=1;
                                break;
                            }
                        }
                    }
                    if(fu==1)break;
                }
                if(fu==1)break;
            }
        }
        if(fu==0)
        {
            lst=mid-1;
        }
        else
        {
            if(mid>mc)
                mc=mid,II=ID;
            fst=mid+1;
        }
    }
//    printf("%d %d\n",x.size(),y.size());
    for(i=II;i<II+mc;i++)
        printf("%c",a[i]);
    printf("\n%d\n",mc);
}
