class Solution {
public:
    int gcd(int a,int b) {
        if(b==0) return a;
        return gcd(b,a%b);
    }

    bool ncm(int x,int y) { // non-coprime?
        return gcd(x,y) > 1;
    }

    long long lcm(int a,int b) {
        return 1LL * a / gcd(a,b) * b;
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long> ans;
        vector<int> res;

        for (int i=0;i<nums.size();i++) {
            long long cur = nums[i];
            ans.push(cur);

            while(ans.size()>=2) {
                long long top1 = ans.top(); ans.pop();
                long long top2 = ans.top(); ans.pop();

                if (!ncm(top1, top2)) {
                    ans.push(top2);
                    ans.push(top1);
                    break;
                }

                long long LCM = lcm(top1, top2);
                ans.push(LCM);
            }
        }

        while(!ans.empty()) {
            res.push_back((int)ans.top());
            ans.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
