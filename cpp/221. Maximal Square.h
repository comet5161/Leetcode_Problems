
/*
[
    ["0","0","0","1"],
    ["1","1","0","1"],
    ["1","1","1","1"],
    ["0","1","1","1"],
    ["0","1","1","1"]]
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int side_len = 0;
        int row = matrix.size();
        int col = 0;
        if(row > 0)
            col = matrix[0].size();
        else
            return 0;

        vector<int> v(col + 1, 0);
        vector<vector<int>> sqrMatrix(row + 1, v);
        
       for(int i = 1; i <= row; i++)
        for(int j = 1; j <= col; j++){
            if( matrix[i-1][j-1] == '1')
                sqrMatrix[i][j] = 1 + min(sqrMatrix[i-1][j-1], min(sqrMatrix[i-1][j], sqrMatrix[i][j-1]));
                side_len = max(side_len, sqrMatrix[i][j]);
        }
        return side_len*side_len;

    }
};