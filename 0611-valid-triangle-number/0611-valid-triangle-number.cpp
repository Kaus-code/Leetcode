class Solution {
public:
    int triangleNumber(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        sort(arr.begin(),arr.end());
        
        for(int i =0;i<n-1;i++){
            if(arr[i]==0) continue;
            for(int j =i+1;j<n-1;j++){
                int s = j;
                int e = n-1;
                int ans = j;
                int pivot = arr[i]+arr[j];
                while(s<=e){
                    int mid = (s+e)/2;
                    if(arr[mid]<pivot){
                        ans = mid;
                        s = mid+1;
                    }
                    else{
                        e = mid-1;
                    }
                }
                res+=ans-j;
            }
        }
        return res;
    }
};