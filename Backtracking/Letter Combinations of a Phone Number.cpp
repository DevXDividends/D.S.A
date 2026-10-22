// TC:O(N x 4^n) SC:O(N) 
class Solution {
public:
    void f(int i, unordered_map<char, string>& map, vector<string>& ans,
           string bucket, string& digits) {

        if (i == digits.size()) {
            ans.emplace_back(bucket);
            return;
        }
        string letters = map[digits[i]];

        for (int k = 0; k < letters.size(); k++) {
            bucket += letters[k];
            f(i + 1, map, ans, bucket, digits);
            bucket.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        unordered_map<char, string> mpp = {
            {'2' , "abc"},
            {'3' , "def"},
            {'4' , "ghi"},
            {'5' , "jkl"},
            {'6' , "mno"},
            {'7' , "pqrs"},
            {'8' , "tuv"},
            {'9' , "wxyz"}
        };

        vector<string> ans;
        string bucket = "";

        f(0, mpp, ans, bucket, digits);

        return ans;
    }
};
