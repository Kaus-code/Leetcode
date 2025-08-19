class Solution {
public:
    long long fact(long long j){
        long long ans=1;
        ans = (j*(j+1))/2;
        return ans;
    }
    long long zeroFilledSubarray(vector<int>& arr) {
        int n = arr.size();
        long long c=0;
        long long j=0;
        bool check = false;
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
               if(check){

                    c=c+fact(j);
                    j=0;
               }
                
                check =false;
            }
            else{
                j++;
                check = true;
            }
        }
        if (check) {
            c += fact(j);
        }
        return c;
    }
};