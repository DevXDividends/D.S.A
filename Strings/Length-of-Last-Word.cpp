class Solution {
public:
    int lengthOfLastWord(string s) {

        int count=0,i=s.length()-1;

        while (i >= 0 && s[i] == ' ')
            i--; // skip trailing spaces Eg:- "hello world "
        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }
        return count;
    }
};
