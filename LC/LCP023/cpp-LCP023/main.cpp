/// Source : https://leetcode.com/problems/two-sum/description/
/// Author : liuyubobobo
/// Time   : 2020-09-21

#include <iostream>
#include <vector>

using namespace std;


/// Greedy + Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool isMagic(vector<int>& target) {

        int n = target.size();

        vector<int> data;
        for(int i = 2; i <= n; i += 2) data.push_back(i);
        for(int i = 1; i <= n; i += 2) data.push_back(i);

        int k = 0;
        for(int i = 0; i < target.size() && target[i] == data[i]; i ++) k ++;
        if(k == 0) return false;

        data = shuffle(target.size(), k);
        return data == target;
    }

private:
    vector<int> shuffle(int n, int k){

        vector<int> data(n);
        for(int i = 1; i <= n; i ++) data[i - 1] = i;

        vector<int> res;
        while(data.size()){
            vector<int> t;
            for(int i = 1; i < data.size(); i += 2) t.push_back(data[i]);
            for(int i = 0; i < data.size(); i += 2) t.push_back(data[i]);

            reverse(t.begin(), t.end());
            for(int i = 0; i < k && t.size(); i ++)
                res.push_back(t.back()), t.pop_back();
            reverse(t.begin(), t.end());

            data = t;
        }
        return res;
    }
};


int main() {

    vector<int> target1 = {2, 4, 3, 1, 5};
    cout << Solution().isMagic(target1) << endl;
    // 1

    vector<int> target2 = {5, 4, 3, 2, 1};
    cout << Solution().isMagic(target2) << endl;
    // 0

    return 0;
}
