/// Source : https://leetcode.com/problems/put-boxes-into-the-warehouse-i/
/// Author : liuyubobobo
/// Time   : 2020-10-17

#include <iostream>
#include <vector>

using namespace std;


/// Sorting and Greedy
/// Time Complexity: O(nlogn + n + m)
/// Space Complexity: O(1)
class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {

        int cur = warehouse[0];
        for(int i = 1; i < warehouse.size(); i ++){
            warehouse[i] = min(warehouse[i], cur);
            cur = warehouse[i];
        }

        sort(boxes.begin(), boxes.end());
        int i = 0, j = warehouse.size() - 1, res = 0;
        while(i < boxes.size() && j >= 0)
            if(boxes[i] <= warehouse[j]) i ++, j --, res ++;
            else j --;

        return res;
    }
};


int main() {

    vector<int> box1 = {4, 3, 4, 1}, warehouse1 = {5, 3, 3, 4, 1};
    cout << Solution().maxBoxesInWarehouse(box1, warehouse1) << endl;
    // 3

    return 0;
}
