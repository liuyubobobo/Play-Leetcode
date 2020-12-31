/// Source : https://leetcode.com/problems/combinations/description/
/// Author : liuyubobobo
/// Time   : 2019-03-29

#include <iostream>
#include <vector>

using namespace std;


/// Using bit mask
/// Time Complexity: O(2^n * n)
/// Space Complexity: O(1)
class Solution {

public:
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> res;

        int LIMIT = (1 << n);
        for(int i = 0; i < LIMIT; i ++){

            vector<int> tres = get_vector(i);
            if(tres.size() == k) res.push_back(tres);
        }
        return res;
    }

private:
    vector<int> get_vector(int num){

        vector<int> res;
        int i = 1;
        while(num){
            if(num % 2) res.push_back(i);
            i ++, num /= 2;
        }
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