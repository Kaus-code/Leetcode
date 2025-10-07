class Solution {
public:
    vector<int> avoidFlood(vector<int>& arr) {
        int n = arr.size();
        set<int> st;
        vector<int> ans(n,1);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                st.insert(i);
            }   
            else{
                ans[i] = -1;
                int temp = arr[i];
                if(mp.count(temp)){
                    auto it = st.lower_bound(mp[temp]);
                    if(it==st.end()){
                        return {};
                    }
                    ans[*it] = temp;
                    st.erase(it);
                }
                mp[temp]=i;
            }
        }
        return ans;
    }
};