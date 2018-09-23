    int tb[400005],lazy[400005];

    void add(int idx,int l,int r,int a,int b,int val)

    {

        if(a<=l&&r<=b)lazy[idx]+=val;

        tb[idx]+=lazy[idx]*(r-l+1);

        if(l!=r)

        {

            lazy[idx*2]+=lazy[idx];

            lazy[idx*2+1]+=lazy[idx];

        }

        lazy[idx]=0;

        if(b<l||r<a)return;

        if(a<=l&&r<=b)return;

        int m=(l+r)/2;

        add(idx*2,l,m,a,b,val);

        add(idx*2+1,m+1,r,a,b,val);

        tb[idx]=tb[idx*2]+tb[idx*2+1];

    }

    int sum(int idx,int l,int r,int a,int b)

    {

        tb[idx]+=lazy[idx]*(r-l+1);

        if(l!=r)

        {

            lazy[idx*2]+=lazy[idx];

            lazy[idx*2+1]+=lazy[idx];

        }

        lazy[idx]=0;

        if(b<l||r<a)return 0;

        if(a<=l&&r<=b)return tb[idx];

        int m=(l+r)/2;

        return sum(idx*2,l,m,a,b)+sum(idx*2+1,m+1,r,a,b);

    }
