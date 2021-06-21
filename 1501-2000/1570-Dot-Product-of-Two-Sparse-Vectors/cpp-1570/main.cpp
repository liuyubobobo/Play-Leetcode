/// Source : https://leetcode.com/problems/dot-product-of-two-sparse-vectors/
/// Author : liuyubobobo
/// Time   : 2021-06-20

#include <iostream>
#include <vector>

using namespace std;


/// Using index-value array
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class SparseVector {

private:
    vector<pair<int, int>> data; // pos->num

public:
    SparseVector(vector<int> &nums) {

        for(int i = 0; i < nums.size(); i ++)
            if(nums[i]) data.push_back({i, nums[i]});
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {

        int res = 0, i = 0, j = 0;
        while(i < data.size() && j < vec.data.size())
            if(data[i].first == vec.data[j].first){
                res += data[i].second * vec.data[j].second;
                i ++;
                j ++;
            }
            else if(data[i].first < vec.data[j].first) i ++;
            else j ++;
        return res;
    }
};


int main() {

    vector<int> v1 = {1, 0, 0, 2, 3}, v2 = {0, 3, 0, 4, 0};
    SparseVector sp1(v1), sp2(v2);
    cout << sp1.dotProduct(sp2) << endl;

    return 0;
}
