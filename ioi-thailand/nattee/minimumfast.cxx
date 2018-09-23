#include <bits/stdc++.h>

using namespace std;

#define TASK "test"

const int INF=1e9;

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        int n,x;
        cin>>n>>x;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        deque<pair<int,int>> que;
        int ans=INF;
        int cur=0;
        for(int i=0;i<n;i++)
        {
            cur+=a[i];
            while(!que.empty() && que.back().first>cur) que.pop_back();
            que.push_back({cur,i});
            while(que.size()>2 && cur-que[1].first>=x) que.pop_front();
            if(que.front().second!=i && cur-que.front().first>=x) ans=min(ans,i-que.front().second);
            if(a[i]>=x) ans=1;
        }
        if(ans==INF) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}
