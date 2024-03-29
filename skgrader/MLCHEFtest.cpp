#pragma warning(disable:4786)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;

#define IN(A, B, C) assert( B <= A && A <= C)

//typedef int LL;
//typedef __int64 LL;

#define MX 100005
vector<int> V[MX];
int health[MX];
int array[MX], start[MX], end[MX], indx;
int n;

int minm[4*MX], lazy[4*MX];
int cnt[4*MX];

void DFS(int at)
{
	array[indx++] = at;
	start[at] = indx - 1;

	int sz = V[at].size(), i;
	for(i = 0; i < sz; i++)
	{
		DFS(V[at][i]);
	}

	end[at] = indx - 1;
}

void update(int at, int L, int H, int lo, int hi, int x)
{
	if(hi < L || H < lo) return;

	if(lo <= L && H <= hi)
	{
		lazy[at] += x;
		minm[at] -= x;
		return;
	}

	if(lazy[at])
	{
		lazy[at*2] += lazy[at];
		lazy[at*2+1] += lazy[at];

		minm[at*2] -= lazy[at];
		minm[at*2+1] -= lazy[at];

		lazy[at] = 0;
	}

	int M = (L + H)/2;
	update(at*2, L, M, lo, hi, x);
	update(at*2 + 1, M + 1, H, lo, hi, x);

	minm[at] = MIN(minm[at*2] , minm[at*2+1]);
}

void build(int at, int L, int H)
{
	if(L == H)
	{
		lazy[at] = 0;
		minm[at] = health[array[L]];
		cnt[at] = 1;

		return;
	}

	int M = (L + H)/2;

	build(at*2, L, M);
	build(at*2 + 1, M + 1, H);

	minm[at] = MIN(minm[at*2] , minm[at*2+1]);
	cnt[at] = cnt[at*2] + cnt[at*2+1];
	lazy[at] = 0;
}

int query(int at, int L, int H, int lo, int hi)
{
	if(hi < L || H < lo) return 0;

	if(L == H)
	{
		if(minm[at] > 0) return cnt[at];
				
		minm[at] = 2000000000;
		return cnt[at] = 0;	
	}

	if(lazy[at])
	{
		lazy[at*2] += lazy[at];
		lazy[at*2+1] += lazy[at];

		minm[at*2] -= lazy[at];
		minm[at*2+1] -= lazy[at];

		lazy[at] = 0;
	}

	if(lo <= L && H <= hi)
	{
		if(minm[at] <= 0)
		{
			int M = (L + H)/2;
			query(at*2, L, M, lo, hi);
			query(at*2 + 1, M + 1, H, lo, hi);

			minm[at] = MIN(minm[at*2] , minm[at*2+1]);
			cnt[at] = cnt[at*2] + cnt[at*2+1];
		}

		return cnt[at];
	}

	int M = (L + H)/2;
	int x = query(at*2, L, M, lo, hi);
	int y = query(at*2 + 1, M + 1, H, lo, hi);

	minm[at] = MIN(minm[at*2] , minm[at*2+1]);

	cnt[at] = cnt[at*2] + cnt[at*2+1];

	return x + y;
}

int main()
{
	int i, p, t, ans, q, a, x;

	scanf("%d", &n);
	IN(n, 0, 100000);
	for(i = 1; i <= n; i++)
	{
		scanf("%d %d", &health[i], &p);
		IN(health[i], 1, 1000000000);
		IN(p, 0, i - 1);
		V[p].push_back(i);
	}

	indx = 0;
	DFS(0);

	build(1, 0, n);

	scanf("%d", &q);
	IN(q, 1, 100000);
	while(q--)
	{
		scanf("%d", &t);
		IN(t, 1, 2);

		if(t == 1)
		{
			scanf("%d %d", &a, &x);
			IN(a, 0, n);
			IN(x, 1, 10000);
			update(1, 0, n, start[a]+1, end[a], x);

		}
		else if(t == 2)
		{
			scanf("%d", &a);
			IN(a, 0, n);
			ans = query(1, 0, n, start[a]+1, end[a]);
			printf("%d\n", ans);
		}
	}

	return 0;
}
