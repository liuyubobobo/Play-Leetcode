/// Source : https://leetcode.cn/problems/hqCnmP/
/// Author : liuyubobobo
/// Time   : 2023-04-22

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> supplyWagon(vector<int>& supplies) {

        int n = supplies.size(), k = n - n / 2;
        while(k --)
            supplies = merge(supplies);
        return supplies;
    }

private:
    vector<int> merge(vector<int>& supplies) {

        int n = supplies.size();
        int min_sum = supplies[0] + supplies[1], pos = 1;
        for(int i = 2; i < n; i ++){
            if(supplies[i - 1] + supplies[i] < min_sum)
                min_sum = supplies[i - 1] + supplies[i], pos = i;
        }

        vector<int> res;
        for(int i = 0; i < n; )
            if(i == pos - 1)
                res.push_back(min_sum), i += 2;
            else
                res.push_back(supplies[i ++]);
        return res;
    }
};


int main() {

    return 0;
}
