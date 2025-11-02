// TC:O(n^2) SC:O(1)
class Solution {
  public:
    bool findPair(vector<int> &arr, int target) {
        // code here
        for(int i=0;i<arr.size();i++){
            int comp = target + arr[i];
            for(int j=i+1;j<arr.size();j++){
                if(arr[j]==comp) return true;
            }
        }
        return false;
    }
};
// TC:O(n) SC:O(1)

class Solution {
  public:
    bool findPair(vector<int> &arr, int target) {
        // code here
        unordered_set<int>mpp;
        for(int n:arr){
            int comp1 = n + target;
            int comp2= n - target;
            if(mpp.find(comp1)!=mpp.end() || mpp.find(comp2)!=mpp.end()) return true;
            mpp.insert(n);
        }
        return false;
        
    }
};
