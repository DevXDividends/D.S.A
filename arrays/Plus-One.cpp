class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       for(int i=digits.size()-1;i>=0;i--){
        
         if(digits[i]<9){
            digits[i]+=1;
            return digits;
            break;
         }else{
            digits[i]=0;
         }
       }
       digits.insert(digits.begin(),1); // insert 1 at pos 0
       return digits;
    }
};
