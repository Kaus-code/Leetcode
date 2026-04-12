class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        
        //Ensure nums1 is smaller array
        if(n1>n2)
        return findMedianSortedArrays(nums2,nums1);

        int left=0,right=n1,total=n1+n2;
while(left<=right)
{
int partition1=(left+right)/2; //partition in nums1 
int partition2=(total+1)/2-partition1;    //partition in nums2
 
//Edge Cases
int maxleft1=(partition1==0)?INT_MIN:nums1[partition1-1];
int minright1=(partition1==n1)?INT_MAX:nums1[partition1];
int maxleft2=(partition2==0)?INT_MIN:nums2[partition2-1];
int minright2=(partition2==n2)?INT_MAX:nums2[partition2];


if(maxleft1<=minright2  && maxleft2<=minright1)
{
    if(total%2==0)
    {
        return (max(maxleft1,maxleft2)+min(minright1,minright2))/2.0;
    }
    else
    {
        return max(maxleft1,maxleft2);
    }
}
else if(maxleft1>minright2)
{
    right=partition1-1;
}
else
{
    left=partition1+1;
}

    
}
return -1;
    }
};