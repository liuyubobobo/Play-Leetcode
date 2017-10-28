/// Source : https://leetcode.com/problems/range-sum-query-immutable/description/
/// Author : liuyubobobo
/// Time   : 2017-10-28

#include <iostream>
#include <vector>

using namespace std;

class NumArray {

private:
    vector<int> sum;

public:
    NumArray(vector<int> nums) {
        sum.push_back(0);
        for(int num: nums)
            sum.push_back(sum.back() + num);
    }

    int sumRange(int i, int j) {
        i ++;
        j ++;
        return sum[j] - sum[i-1];
    }
};

int main() {

    int nums[] = {-2, 0, 3, -5, 2, -1};
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int));
    NumArray obj(vec);

    cout << obj.sumRange(0, 2) << endl;
    cout << obj.sumRange(2, 5) << endl;
    cout << obj.sumRange(0, 5) << endl;

    return 0;
}