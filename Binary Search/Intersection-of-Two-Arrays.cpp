class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1),end(nums1));
        sort(begin(nums2),end(nums2));
        int i=0,j=0;
        vector<int> res;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                res.emplace_back(nums1[i]);
            
            while(i<nums1.size()-1 && nums1[i]==nums1[i+1]) i++;
            while(j<nums2.size()-1 && nums2[j]==nums2[j+1]) j++;
            i++;j++;
            }else if(nums1[i]<nums2[j]){
                i++;
            }else{
                j++;
            }
            
        }
        return res;
    }
};
