class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,r=nums.size()-1;
        while(i<=r){
            if(nums[i]==val){
                nums[i]=nums[r];
                r--;
            }else{
                i++;
            }
        }
         return r+1;
        }
            
   
        
    
};
