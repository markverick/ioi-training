#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string>
#include<map>
#include<queue>
#define MP(x,y) make_pair(x,y)
using namespace std;

queue<pair<int,string> >q;
int fst,lst;
string q2[100000];
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
    string str="000000000";
    int i,j,k;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            char in;
            cin >> in;
            str[i*3+j]=in;
        }
    }
    string b4=str;
    //cout << str;
    //cout << str;
    string pro="123456780";
    int idx=0;
    for(i=0;i<9;i++)
    {
        if(str[i]=='0')
            idx=i;
        //printf("%c\n",str[i]);
    }

    //printf("F");
    //cout << pro;
    q.push(MP(idx,str));
    q[lst++]=str;
    //system("pause");

    while(!q.empty())
    {
        //printf("F");
        idx=q.front().first;
        string s=q.front().second;
        //cout <<s << " ";
        str=s;
        int cot=0;
        /*for(i=0;i<9;i++)
        {
            if(str[i]==pro[i])
                cot++;
        }
        */
        //cout << cot << " ";
        if(str==pro)
            break;
        q.pop();
        fst++;
        if(idx==0||idx==3||idx==6||idx==1||idx==4||idx==7)
        {
            swap(str[idx],str[idx+1]);ttm[str]=MP(s,'R');q[lst++]=str;
            q.push(MP(idx+1,str));swap(str[idx],str[idx+1]);
        }
        if(idx==2||idx==5||idx==8||idx==1||idx==4||idx==7)
        {
            swap(str[idx],str[idx-1]);ttm[str]=MP(s,'L');q[lst++]=str;
            q.push(MP(idx-1,str));swap(str[idx],str[idx-1]);
        }
        if(idx==0||idx==3||idx==1||idx==4||idx==2||idx==5)
        {
            swap(str[idx],str[idx+3]);ttm[str]=MP(s,'D');q[lst++]=str;
            q.push(MP(idx+3,str));swap(str[idx],str[idx+3]);
        }
        if(idx==6||idx==3||idx==7||idx==4||idx==8||idx==5)
        {
            swap(str[idx],str[idx-3]);ttm[str]=MP(s,'U');q[lst++]=str;
            q.push(MP(idx-3,str));swap(str[idx],str[idx-3]);
        }
    }
    str=b4;
    cout <<pro;
    while(str!=pro)
    {
        cout<< str << ttm[str].second << "\n";
        str=ttm[str].first;
    }
    //printf("%s",str);
}
