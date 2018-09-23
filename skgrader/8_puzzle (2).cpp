#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<map>
#include<queue>
#define MP make_pair
using namespace std;
string str;
queue<pair<int,string> >q;
map<string,pair<string,char> > ttm;
int op[12];
char result[1000000];
string pro;
void swap(char *a,char *b)
{
    char c=*a;
    *a=*b;
    *b=c;
}
int main()
{
    int i,j,k;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            int in;
            scanf("%d",&in);
            str[i*3+j]=in+'0';
        }
    }
    for(i=0;i<9;i++)
    {
        pro[i]=i+1;
    }
    int idx=0;
    for(i=0;i<9;i++)
    {
        if(str[i]=='0')
            idx=i;
    }
    q.push(MP(idx,str));
    while(true)
    {
        idx=q.front().first;
        string s=q.front().second;
        str=s;
        if(str==pro)
            break;
        q.pop();
        if(idx==0){
            swap(str[0],str[1]);ttm[str]=MP(s,'r');q.push(MP(1,str));swap(str[0],str[1]);
            swap(str[0],str[3]);ttm[str]=MP(s,'d');q.push(MP(3,str));swap(str[0],str[3]);
        }
        if(idx==1){
            swap(str[1],str[0]);ttm[str]=MP(s,'l');q.push(MP(0,str));swap(str[1],str[0]);
            swap(str[1],str[2]);ttm[str]=MP(s,'r');q.push(MP(2,str));swap(str[1],str[2]);
            swap(str[1],str[4]);ttm[str]=MP(s,'d')s;q.push(MP(4,str));swap(str[1],str[4]);
        }
        if(idx==2){
            swap(str[2],str[1]);ttm[str]=s;q.push(MP(1,str));swap(str[2],str[1]);
            swap(str[2],str[5]);ttm[str]=s;q.push(MP(5,str));swap(str[2],str[5]);
        }
        if(idx==3){
            swap(str[3],str[0]);ttm[str]=s;q.push(MP(0,str));swap(str[3],str[0]);
            swap(str[3],str[4]);ttm[str]=s;q.push(MP(4,str));swap(str[3],str[4]);
            swap(str[3],str[6]);ttm[str]=s;q.push(MP(6,str));swap(str[3],str[6]);
        }
        if(idx==4){
            swap(str[4],str[1]);ttm[str]=s;q.push(MP(1,str));swap(str[4],str[1]);
            swap(str[4],str[3]);ttm[str]=s;q.push(MP(3,str));swap(str[4],str[3]);
            swap(str[4],str[5]);ttm[str]=s;q.push(MP(5,str));swap(str[4],str[5]);
            swap(str[4],str[7]);ttm[str]=s;q.push(MP(7,str));swap(str[4],str[7]);
        }
        if(idx==5){
            swap(str[5],str[2]);ttm[str]=s;q.push(MP(2,str));swap(str[5],str[2]);
            swap(str[5],str[4]);ttm[str]=s;q.push(MP(4,str));swap(str[5],str[4]);
            swap(str[5],str[8]);ttm[str]=s;q.push(MP(8,str));swap(str[5],str[8]);
        }
        if(idx==6){
            swap(str[6],str[3]);ttm[str]=s;q.push(MP(3,str));swap(str[6],str[3]);
            swap(str[6],str[7]);ttm[str]=s;q.push(MP(7,str));swap(str[6],str[7]);
        }
        if(idx==7){
            swap(str[7],str[4]);ttm[str]=s;q.push(MP(4,str));swap(str[7],str[4]);
            swap(str[7],str[6]);ttm[str]=s;q.push(MP(6,str));swap(str[7],str[6]);
            swap(str[7],str[8]);ttm[str]=s;q.push(MP(8,str));swap(str[7],str[8]);
        }
        if(idx==8){
            swap(str[8],str[5]);ttm[str]=s;q.push(MP(5,str));swap(str[8],str[5]);
            swap(str[8],str[7]);ttm[str]=s;q.push(MP(7,str));swap(str[8],str[7]);
        }


    }
    //printf("%s",str);
}
