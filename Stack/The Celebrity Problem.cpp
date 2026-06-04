// brute force : TC:O(n^3) SC:O(1)
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        
        int row = mat.size();
        int col=  mat[0].size();
        if (row == 1 && col == 1)return 0;
        
        for(int i=0;i<col;i++){
            for(int j=0;j<row;j++){
                if(i == j)continue;
                if(mat[i][j] == 1){
                    bool celebrity  = true;
                    for(int k=0;k<col;k++){
                        if(k == j)
                            continue;
                        if(mat[k][j]!=1 || mat[j][k]!=0){
                            celebrity = false;
                            break;
                        }
                    }
                    if(celebrity)
                        return j;
                }
            }
        }
        return -1;
    }
};
// better : TCO(n^2)+ O(n) SC:O(2n)
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        
        int row = mat.size();
        int col=  mat[0].size();
        if (row == 1 && col == 1)return 0;
        
        vector<int> knowMe(col,0);
        vector<int> iKnow(col,0);
        for(int i=0;i<col;i++){
            for(int j=0;j<row;j++){
                if(i == j)
                    continue;
                if(mat[i][j] == 1){
                    knowMe[j]++;
                    iKnow[i]++;
                }
            }
        }
        for(int i=0;i<col;i++)
            if(knowMe[i] == col-1 && iKnow[i] == 0)
                return i;
        return -1;
    }
};
// optimal :TC:O(n) SC:O(1)
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int top = 0;
        int down = n-1;
        while(top<down){
            if(mat[top][down] == 1)
                top++;
            else if (mat[down][top] == 1)
                down--;
            else{
             top++;
             down--;
            }
        }
        if(top>down)
            return -1;
        for(int i=0;i<n;i++){
            if( i == top)
                continue;
            if(mat[i][top] !=1 || mat[top][i]!=0)
                return -1;
        }
        return top;
        
    }
};
