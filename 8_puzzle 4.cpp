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
map<int,pair<int,char> > ttm;
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
    q2[lst++]=str;
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
        {
            idx=fst;
            break;
        }

        q.pop();
        fst++;
        if(idx==0||idx==3||idx==6||idx==1||idx==4||idx==7)
        {
            swap(str[idx],str[idx+1]);ttm[lst]=MP(fst-1,'R');q2[lst++]=str;
            q.push(MP(idx+1,str));swap(str[idx],str[idx+1]);
        }
        if(idx==2||idx==5||idx==8||idx==1||idx==4||idx==7)
        {
            swap(str[idx],str[idx-1]);ttm[lst]=MP(fst-1,'L');q2[lst++]=str;
            q.push(MP(idx-1,str));swap(str[idx],str[idx-1]);
        }
        if(idx==0||idx==3||idx==1||idx==4||idx==2||idx==5)
        {
            swap(str[idx],str[idx+3]);ttm[lst]=MP(fst-1,'D');q2[lst++]=str;
            q.push(MP(idx+3,str));swap(str[idx],str[idx+3]);
        }
        if(idx==6||idx==3||idx==7||idx==4||idx==8||idx==5)
        {
            swap(str[idx],str[idx-3]);ttm[lst]=MP(fst-1,'U');q2[lst++]=str;
            q.push(MP(idx-3,str));swap(str[idx],str[idx-3]);
        }
    }
    //str=b4;
    //cout <<pro;
    //idx=lst-1;
    //cout << q2[idx];
    //system("pause");
    while(q2[idx]!=b4)
    {
        printf("%c",ttm[idx].second);
        idx=ttm[idx].first;
    }
    //printf("%s",str);
}
