class Solution {
public:
int gcd(int a,int b)
{
    if(b==0)
         return a;
    else
      return gcd(b,a%b);
}

bool ncm(int x,int y)
{
    if(gcd(x,y)>1)
    {
        return true;
    }
    return false;
}
long long lcm(int a,int b)
{
    return (a/gcd(a,b))*b;
}
    vector<int> replaceNonCoprimes(vector<int>& nums) {
     vector<int> ans;
     
     for(int i=0;i<nums.size();i++)
     {
        ans.push_back(nums[i]);
        while(ans.size()>1)
        {
            int prev_val=ans[ans.size()-2];
            int next_val=ans[ans.size()-1];
        if(!ncm(prev_val,next_val))
        {
break;
        }
        ans.pop_back();
        ans.pop_back();
        long long LCM=lcm(prev_val,next_val);
        ans.push_back(int(LCM));
        }
     }
     return ans;   
    }
};