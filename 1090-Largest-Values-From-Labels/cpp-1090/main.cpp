/// Source : https://leetcode.com/problems/largest-values-from-labels/
/// Author : liuyubobobo
/// Time   : 2019-06-15

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Sorting and Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {

        vector<pair<int, int>> vec;
        for(int i = 0; i < values.size(); i ++)
            vec.push_back(make_pair(values[i], labels[i]));
        sort(vec.begin(), vec.end(), greater<pair<int, int>>());

        unordered_map<int, int> freq;
        int sum = 0, num = 0;
        for(const pair<int, int>& p: vec)
            if(freq[p.second] < use_limit){

                sum += p.first;
                num ++;
                freq[p.second] ++;
                if(num == num_wanted)
                    break;
            }
        return sum;
    }
};


int main() {

    vector<int> values = {5,4,3,2,1};
    vector<int> labels = {1,1,2,2,3};
    int num_wanted = 3, use_limit = 1;
    cout << Solution().largestValsFromLabels(values, labels, num_wanted, use_limit) << endl;

    return 0;
}