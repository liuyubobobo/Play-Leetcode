/// Source : https://leetcode.com/problems/lexicographical-numbers/description/
/// Author : liuyubobobo
/// Time   : 2017-10-16

#include <iostream>
#include <vector>

using namespace std;

/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i = 1 ; i < 10 ; i ++)
            if(i <= n)
                generateRes(res, i, n);

        return res;
    }

private:
    void generateRes(vector<int>& res, int pre, int n){

        res.push_back(pre);
        for(int i = 0 ; i < 10 ; i ++)
            if(pre*10+i <= n)
                generateRes(res, pre*10+i, n);
    }
};

int main() {

    vector<int> res1 = Solution().lexicalOrder(13);
    for(int num: res1)
        cout << num << " ";
    cout << endl;

    vector<int> res2 = Solution().lexicalOrder(100);
    for(int num: res2)
        cout << num << " ";
    cout << endl;

    return 0;
}