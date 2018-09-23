#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 1e5 + 10;
const int INF = 2e9;

int n, par[MAXN], hl[MAXN];
int s_t[MAXN], f_t[MAXN], tm, nut[4 * MAXN], fen[MAXN], mp[MAXN];
pair<int, int>	weed[4 * MAXN];
vector<int>	adj[MAXN];

void dfs(int v){
	mp[tm] = v;
	s_t[v] = tm++;
	for (int u:adj[v])
		dfs(u);
	f_t[v] = tm;
}

void plant(int v, int b, int e){
	if (e - b == 1){
		weed[v] = {hl[mp[b]], b};
		return;
	}

	int mid = (b + e)/ 2;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	weed[v] = min(weed[v<<1], weed[v<<1^1]);
}

void absorb(int v){
	nut[v<<1] += nut[v];
	nut[v<<1^1] += nut[v];
	weed[v<<1].F -= nut[v];
	weed[v<<1^1].F -= nut[v];
	nut[v] = 0;
}

void water(int v, int b, int e, int l, int r, int val){
	if (l <= b && e <= r){
		weed[v].F -= val;
		nut[v] += val;
		return;
	}
	if (r <= b || e <= l)	return;

	int mid = (b + e)/ 2;
	absorb(v);
	water(v<<1, b, mid, l, r, val);
	water(v<<1^1, mid, e, l, r, val);
	weed[v] = min(weed[v<<1], weed[v<<1^1]);
}

void burn(int v, int b, int e, int pos){
	if (e - b == 1){
		weed[v].F = INF;
		return;
	}

	int mid = (b + e)/ 2;
	absorb(v);
	if (pos < mid)
		burn(v<<1, b, mid, pos);
	else
		burn(v<<1^1, mid, e, pos);
	weed[v] = min(weed[v<<1], weed[v<<1^1]);
}

void add(int v){
	for (v++; v < MAXN; v+=v&-v)
		fen[v]++;
}

int get(int v){
	int ret = 0;
	for (; v; v-=v&-v)
		ret += fen[v];
	return ret;
}

int main(){
	scanf("%d", &n); n++;
	for (int i = 1; i < n; i++){
		scanf("%d %d", &hl[i], &par[i]);
		adj[par[i]].push_back(i);
	}
	hl[0] = INF;
	dfs(0);

	plant(1, 0, n);
	int q;	scanf("%d", &q);
	while (q--){
		int type;	scanf("%d", &type);
		if (type - 1){
			int v;	scanf("%d", &v);
			printf("%d\n", f_t[v] - s_t[v] - 1 - (get(f_t[v]) - get(s_t[v] + 1)));
		}
		else{
			int v, val;	scanf("%d %d", &v, &val);
			water(1, 0, n, s_t[v] + 1, f_t[v], val);
			while (weed[1].F <= 0){
				add(weed[1].S);
				burn(1, 0, n, weed[1].S);
			}
		}
	}
	return 0;
}
