Brute force approach -> using 2 loops 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if ((nums[i] + nums[j]) == target) {
                    return {i, j}; 
                }
            }
        }
        return {};  
    }
};


better approach -. using 2 pointers
bool twoSum(vector<int> &arr, int target){
  sort(arr.begin(),arr.end());
  
    int left = 0, right = arr.size() - 1;
    while (left < right){
        int sum = arr[left] + arr[right];

        if (sum == target)
            return true;
        
        // Move toward a higher sum
        else if (sum < target)
            left++; 
      
        // Move toward a lower sum
        else
            right--; 
    }
  
    // If no pair found
    return false;
}


optimal approach -> using hash-map 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        int comp=0;
        for(int i=0;i<nums.size();i++){
            comp=target-nums[i];
            if(mpp.find(comp)!=mpp.end()){
                return {i,mpp[comp]};
            }
            mpp[nums[i]]=i;
            }
        
        return {};  
    }
};
