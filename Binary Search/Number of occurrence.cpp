// TC:O(log n) SC:O(1)
class Solution {
  public:
    int lowerB(vector<int> &arr,int tar){
        int low = 0;
        int high = arr.size()-1;
        while(low<=high){
            int mid  = low+(high-low)/2;
            if(arr[mid]>=tar)
                high = mid-1;
            else 
                low = mid+1;
        }
        return low;
        
    }
    int upperB(vector<int> &arr,int tar){
        int low = 0;
        int high = arr.size()-1;
        while(low<=high){
            int mid  = low+(high-low)/2;
            if(arr[mid]>tar)
                high = mid-1;
            else 
                low = mid+1;
        }
        return low;
        
    }
    int countFreq(vector<int>& arr, int target) {
        // code here
        return upperB(arr,target) - lowerB(arr,target);
        
    }
};
