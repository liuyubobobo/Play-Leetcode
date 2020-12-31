/// Source : https://leetcode.com/problems/couples-holding-hands/description/
/// Author : liuyubobobo
/// Time   : 2018-06-17

#include <iostream>
#include <vector>

using namespace std;

/// Greedy Algorithm
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {

        for(int i = 0 ; i < row.size() ; i ++)
            row[i] = row[i] / 2;
        // print_vec(row);

        int res = 0;
        for(int i = 1 ; i < row.size() ; i += 2)
            if(row[i] != row[i - 1]){
                for(int j = i + 1 ; j < row.size() ; j ++)
                    if(row[j] == row[i - 1]){
                        swap(row[j], row[i]);
                        res ++;
                    }
            }
        return res;
    }

private:
    void print_vec(const vector<int>& vec){
        for(int e: vec)
            cout << e << " ";
        cout << endl;
    }
};

int main() {

    vector<int> row1 = {0, 2, 1, 3};
    cout << Solution().minSwapsCouples(row1) << endl;

    vector<int> row2 = {3, 2, 0, 1};
    cout << Solution().minSwapsCouples(row2) << endl;

    return 0;
}