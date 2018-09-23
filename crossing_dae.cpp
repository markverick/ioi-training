#include<bits/stdc++.h>


using namespace std;


int main() {
  int T,N;
  cin >> T;
  while (T--) {
    cin >> N;
    vector<pair<int,int>> t;
    t.clear();
    for (int i = 0;i < N;i++) {
      int a,b;
      cin >> a >> b;
      t.push_back(make_pair(a,b));
    }

    long long count = 0;
    for (int i = 0;i < N;i++) {
      for (int j = i+1;j < N;j++) {
        int d = abs(t[i].first - t[j].first);
        int r1 = t[i].second;
        int r2 = t[j].second;
        if (d < r1) {
          if (r2 > r1 - d && r2 < r1 + d) count++;
        } else {
          if (r2 > d - r1 && r2 < r1 + d) count++;
        }
      }
    }
    cout << count << endl;
  }
}
