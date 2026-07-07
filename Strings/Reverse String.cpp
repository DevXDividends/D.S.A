// recursive TC:O(n) SC;O(n)
class Solution {
public:
    void recurseRev(vector<char>& s, int i, int j) {
        if (i >= j)
            return;
        swap(s[i], s[j]);
        recurseRev(s, i+1, j-1);
    }
    void reverseString(vector<char>& s) { recurseRev(s, 0, s.size() - 1); }
};
// iterative TC:O(n) SC:O(1)
class Solution {
public:
    void reverseString(vector<char>& s) {
       //simoley use 2 pointer to swap the characters at the two ends of the string using the inbuild swap() function and increment,decrement the variables
        int i=0,j=s.size()-1;
        while(i<j){
            swap(s[i++],s[j--]);
        }
    }
};
