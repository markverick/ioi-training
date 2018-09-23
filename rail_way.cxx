#include<bits/stdc++.h>
using namespace std;
int seg[200135];
int lazy[200135];
int x,y;
void add(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(lst<x||fst>y)
    {
        return;
    }
    if(fst>=x&&lst<=y)
    {
        seg[idx]=val*(lst-fst+1)
        return;
    }

}
int main()
{
    int n,i,j,k;
}
