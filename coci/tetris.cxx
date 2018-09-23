#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > v[10];
int a[135];
int main()
{
	int i,j,k,n,p,fk;
	scanf("%d %d",&n,&p);
	v[1].emplace_back(vector<int> {0});
	v[1].emplace_back(vector<int> {0,0,0,0});
	v[2].emplace_back(vector<int> {0,0});
	v[3].emplace_back(vector<int> {0,0,1});
	v[3].emplace_back(vector<int> {0,-1});
	v[4].emplace_back(vector<int> {0,-1,-1});
	v[4].emplace_back(vector<int> {0,1});
	v[5].emplace_back(vector<int> {0,0,0});
	v[5].emplace_back(vector<int> {0,1});
	v[5].emplace_back(vector<int> {0,-1,0});
	v[5].emplace_back(vector<int> {0,-1});
	v[6].emplace_back(vector<int> {0,0,0});
	v[6].emplace_back(vector<int> {0,0});
	v[6].emplace_back(vector<int> {0,1,1});
	v[6].emplace_back(vector<int> {0,-2});
	v[7].emplace_back(vector<int> {0,0,0});
	v[7].emplace_back(vector<int> {0,2});
	v[7].emplace_back(vector<int> {0,0,-1});
	v[7].emplace_back(vector<int> {0,0});
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int cot=0;
	for(i=0;i<v[p].size();i++)
	{
		for(j=1;j<=n;j++)
		{
			fk=0;
			for(k=0;k<v[p][i].size();k++)
			{
				if(j+k>n)
				{
					fk=1;break;
				}
				if(a[j+k]-a[j]!=v[p][i][k])
				{
					fk=1;break;
				}
			}
			if(fk==0)
				cot++;
		}
	}
	printf("%d",cot);
}