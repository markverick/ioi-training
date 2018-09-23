#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int hsh[30],pcol[30135],out[30135][55],colid[30135];
char ch[3];
vector<pair<int,int> > v;
vector<int> p;
queue<int> qe,qr;
int main()
{
//	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k,l,a,c,q,odd=0,I,J,K;
	memset(colid,-1,sizeof colid);
//	memset(out,-1,sizeof out);
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
    {
        scanf("%s %d",ch,&a);
        if(a%2)
            odd++;
        v.emplace_back(ch[0]-'A',a);
    }
    q=n-odd;
    sort(v.begin(),v.end());
    for(i=0;i<v.size();i++)
        hsh[i]=v[i].Y;
    scanf("%d",&c);
    for(i=1;i<=c;i++)
    {
        scanf("%d",&a);
        a--;
        colid[a]=p.size();
        p.emplace_back(a);
        pcol[a]=1;
    }
    if(q<0||q%2)
    {
        printf("IMPOSSIBLE");
        return 0;
    }
    k=0;
    for(i=0;i<n;i++)
    {
        l=n-i;
        if(!qe.empty()&&hsh[k]%2)
        {
            if(pcol[qe.front()])
                out[qe.front()][colid[qe.front()]]=k;
            qe.pop();
            hsh[k]--;
            if(hsh[k]==0)
            k++;
        }

        if(qr.empty())
        {
            if(hsh[k]%2==0&&q==0)
            {
//                printf("!!%d %d\n",i,k);
                I=i+1;
                qe.emplace(i);
            }
            else if(hsh[k]%2==0)
            {
                if(pcol[i])
                    out[i][colid[i]]=k;
                I=i+1;
                hsh[k]--;
                q-=2;
            }
            else if(hsh[k]%2)
            {
                if(pcol[i])
                    out[i][colid[i]]=k;
                hsh[k]--;
                I=i+1;
            }
            else
                I=i;
        }
        else
        {
            if(pcol[i])
                out[i][colid[i]]=qr.front();
            qr.pop();
            I=i+1;
        }
        while(135)
        {
            if(hsh[k]%2)
            {
                if(!qe.empty())
                {
                    if(pcol[qe.front()])
                        out[qe.front()][colid[qe.front()]]=k;
                    qe.pop();
                }
                else
                {
                    qr.emplace(k);
                }
                hsh[k]--;
            }
            J=I+hsh[k]/2-1;
//            printf("HSH %d\n",hsh[k]);
//            printf("> %d\n",k);
            for(j=0;j<p.size();j++)
            {
                if(p[j]>=I&&p[j]<=J)
                {
                    out[i][j]=k;
                }
            }
            if(pcol[i])
            {
                for(j=I;j<=min(J,n-1);j++)
                    out[j][colid[i]]=k;
            }
            hsh[k]=max(0,(J-n+1)*2);
//            printf("+[%d] = %d\n",k,hsh[k]);
            if(hsh[k]==0)
                k++;
//            printf("%d < - > %d\n",I,J);
//            printf("Q Reserved = %d, QE [Hole] = %d\n",qr.size(),qe.size());
//            system("pause");
//            printf("!\n");
            if(J>=n-1)
                break;
            I=J+1;
        }
//        printf("END OF LINE %d\n",i);
//        printf("K = %d hsh[k] = %d q = %d qe = %d qr = %d\n",k,hsh[k],q,qe.size(),qr.size());
//        system("pause");
    }
    while(!qe.empty())
    {
        if(hsh[k]==0)
        {
//            printf("FAILED\n");
            break;
        }
        if(pcol[qe.front()])
            out[qe.front()][colid[qe.front()]]=k;
        qe.pop();
        hsh[k]--;
        if(hsh[k]==0)
            k++;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<p.size();j++)
        {
            printf("%c",v[out[i][j]].X+'A');
////            printf("%d",out[i][j]);
        }
        printf("\n");
    }
}
