// TC:O(n) SC:O(1)
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
       int n = nums.size() ;
        double avg=-1e9;
        double sum=0.0;
        int l=0,r=0;
        while(r<n){
            sum+=nums[r];
            if(r-l+1<k)
            r++;
            else if(r-l+1==k){
            avg=max(avg,sum/k);
            sum-=nums[l];
            l++;r++;
            }
            
        }
        return avg;
    }
}; 