int LIS_nlgn(vector<int> A)
{
    ///IF ALLOW SAME NUMBER USE UPPER_BOUND INSTEAD
    vector<int> pp;
    vector<int>::iterator it;
    for(int i=0; i<A.size(); i++)
    {
        it=lower_bound(pp.begin(),pp.end(),A[i]);
        if(it==pp.end())
            pp.push_back(A[i]);
        else
            pp[it-pp.begin()]=A[i];
    }
    return pp.size();
}
