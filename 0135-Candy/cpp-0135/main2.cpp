/// Source : https://leetcode.com/problems/candy/
/// Author : liuyubobobo
/// Time   : 2018-12-10

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Two arrays's thinking
/// But only use one array :-)
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();

        vector<int> res(n, 1);
        for(int i = 1; i < n; i ++)
            if(ratings[i] > ratings[i - 1])
                res[i] = res[i - 1] + 1;

        for(int i = n - 2; i >= 0; i --)
            if(ratings[i] > ratings[i + 1] && res[i] <= res[i + 1])
                res[i] = res[i + 1] + 1;

        return accumulate(res.begin(), res.end(), 0);
    }
};


int main() {

    return 0;
}