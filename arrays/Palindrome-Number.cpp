class Solution {
    public boolean isPalindrome(int x) {
        int num=x;
        if(x<0)
            return false;
        
        int reversenum=0;
        while(x>0){
            int remainder = x%10;
            reversenum = reversenum * 10 + remainder;
            x/=10;
        }
        return num == reversenum;

        
    }
}
