#include<bits/stdc++.h> using namespace std;
class ParenthesesDiv2Hedium { public: vector <int> correct(string s) stack<int> st; int n=s.size(); vector<int> ans; vector<int> arr(50,0); for(int i=0; i<n; i++)
{
if(s[i]==.(1) {
} else {
}
st.push(i);
if(st.empty()==1) {
arr[i]=1; st.push(i);
} else st.pop();
1 int x=0; while(!st.empty())
