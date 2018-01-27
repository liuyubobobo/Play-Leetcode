/// Source : https://leetcode.com/problems/toeplitz-matrix/description/
/// Author : liuyubobobo
/// Time   : 2018-01-26

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Using HashTable to memorize the r-c value
/// Time Complexity: O(N^2)
/// Space Complexity: O(N)
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {

        unordered_map<int, int> table;
        for(int i = 0 ; i < matrix.size() ; i ++)
            for(int j = 0 ; j < matrix[i].size() ; j ++){
                unordered_map<int, int>::iterator iter = table.find(i - j);
                if(iter == table.end())
                    table.insert(make_pair(i - j, matrix[i][j]));
                else if(iter->second != matrix[i][j])
                    return false;
            }

        return true;
    }
};


void printBool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {
    vector<vector<int>> matrix1 = {{1,2,3,4}, {5,1,2,3}, {9,5,1,2}};
    printBool(Solution().isToeplitzMatrix(matrix1));

    vector<vector<int>> matrix2 = {{1, 2}, {2, 2}};
    printBool(Solution().isToeplitzMatrix(matrix2));

    return 0;
}