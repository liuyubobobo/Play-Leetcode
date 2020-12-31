/// Source : https://leetcode.com/problems/combinations/description/
/// Author : liuyubobobo
/// Time   : 2017-11-18

#include <iostream>
#include <vector>

using namespace std;


/// Naive Recursive
/// Time Complexity: O(k * C(n, k))
/// Space Complexity: O(k)
class Solution {

private:
    vector<vector<int>> res;

    void generateCombinations(int n, int k, int start, vector<int> &c){

        if(c.size() == k){
            res.push_back(c);
            return;
        }

        for(int i = start ; i <= n ; i ++){
            c.push_back( i );
            generateCombinations(n, k, i + 1, c);
            c.pop_back();
        }

        return;
    }

public:
    vector<vector<int>> combine(int n, int k) {

        res.clear();
        if( n <= 0 || k <= 0 || k > n )
            return res;

        vector<int> c;
        generateCombinations(n, k, 1, c);

        return res;
    }
};


void print_vec(const vector<int>& vec){

    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<vector<int>> res = Solution().combine(4,2);
    for( int i = 0 ; i < res.size() ; i ++ )
        print_vec(res[i]);
    return 0;
}