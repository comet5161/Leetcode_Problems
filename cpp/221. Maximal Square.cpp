#include <iostream>
#include <vector>
#include <algorithm>
#include "CJsonObject/CJsonObject.hpp"
using namespace std;

#include "221. Maximal Square.h"

vector<vector<char>> toMatrix(neb::CJsonObject& oJson){
    vector<vector<char>> matrix;
    int row = oJson.GetArraySize();
    int col = oJson[0].GetArraySize();
    for(int i = 0; i < row; i++){
        vector<char> v;
        for(int j = 0; j < col; j++){
            v.push_back(oJson[i][j].ToString()[1]);
        }
        matrix.push_back(v);
    }
    return matrix;
}
//test case:
//[["0","0","0","1"],["1","1","0","1"],["1","1","1","1"],["0","1","1","1"],["0","1","1","1"]]

int main(int argc, char* argv[]){
    cout << "please input:" << endl;
    string s;// = R"([["0","0","0","1"],["1","1","0","1"],["1","1","1","1"],["0","1","1","1"],["0","1","1","1"]])";
    getline(cin, s);
    neb::CJsonObject oJson(s);

    vector<vector<char>> matrix = toMatrix(oJson);
    Solution sol;
    cout << sol.maximalSquare(matrix);

    return 0;
}
