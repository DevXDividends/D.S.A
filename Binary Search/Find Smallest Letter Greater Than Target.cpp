// TC:O(log n) SC:O(1)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int low(0),high(n-1);
        while(low<=high){
            int mid(low+(high-low)/2);
            if(letters[mid]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return (low<n)?letters[low]:letters[0];
    }
};
