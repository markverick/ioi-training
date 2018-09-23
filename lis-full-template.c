vector<int> LIS_nlgn(vector<int> A)
{
    ///IF ALLOW SAME NUMBER USE UPPER_BOUND INSTEAD
    vector<int> pp,idx;
    vector<int> pre(A.size()+5);
    vector<int>::iterator it;
    for(int i=0; i<A.size(); i++)
    {
        it=lower_bound(pp.begin(),pp.end(),A[i]);
        pre[i]=-1;
        if(it==pp.end())
        {
            if(pp.size()>0)

                pre[i]=idx[pp.size()-1];

            pp.push_back(A[i]);
            idx.push_back(i);
        }
        else
        {
            if(it-pp.begin()>0)

                pre[i]=idx[it-pp.begin()-1];

            pp[it-pp.begin()]=A[i];
            idx[it-pp.begin()]=i;
        }
    }
    // construct LIS
    vector<int> ans;
    int k=idx[pp.size()-1];
    while(k!=-1)
    {
        ans.push_back(A[k]);
        k=pre[k];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
