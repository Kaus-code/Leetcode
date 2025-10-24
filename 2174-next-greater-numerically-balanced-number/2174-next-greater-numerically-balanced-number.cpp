class Solution {
public:
 bool isbalanced(int n)
 {
    int t=n;
    vector<int> f(10,0);
    while(t)
    {
        int p=t%10;
        f[p]++;
        t=t/10;
    }

    for(int d=0;d<10;d++)
    {
        if(f[d]>0 && f[d]!=d)
        {
            return false;
        }
    }
    return true;
 }
    int nextBeautifulNumber(int n) {
        int x=n+1;
        while(true)
        {
            if(isbalanced(x))
            {
                return x;
            }
            x++;
        }
    }
};