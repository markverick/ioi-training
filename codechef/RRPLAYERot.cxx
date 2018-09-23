    #include <iostream>
    #include <iomanip>
    using namespace std;
    #include <vector>
    #include <algorithm>
    #include <math.h>
    int main()
    {
        long t;
        cin>>t;
        cout<<setprecision(1)<<fixed;
        while(t--)
        {
            int n;
            cin>>n;
            float s=0;
            for(int i=1;i<=n;i++)
            s+=((float)n/i);
            cout<<s<<endl;
        }
        return 0;
    }
