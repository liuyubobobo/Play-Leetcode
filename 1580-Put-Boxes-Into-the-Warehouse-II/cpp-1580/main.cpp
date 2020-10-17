/// Source : https://leetcode.com/problems/put-boxes-into-the-warehouse-ii/
/// Author : liuyubobobo
/// Time   : 2020-10-16

#include <iostream>
#include <vector>

using namespace std;


/// Sorting and Greedy and Two Pointers
/// Time Complexity: O(nlogn + mlogm + (n + m))
/// Space Complexity: O(1)
class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {

        int index = min_element(warehouse.begin(), warehouse.end()) - warehouse.begin();

        int cur = warehouse[0];
        for(int i = 0; i < index; i ++){
            warehouse[i] = min(warehouse[i], cur);
            cur = warehouse[i];
        }

        cur = warehouse.back();
        for(int i = warehouse.size() - 1; i > index; i --){
            warehouse[i] = min(warehouse[i], cur);
            cur = warehouse[i];
        }

        sort(warehouse.begin(), warehouse.end());
        sort(boxes.begin(), boxes.end());

        int i = 0, j = 0, res = 0;
        while(i < warehouse.size() && j < boxes.size())
            if(warehouse[i] >= boxes[j]) i ++, j ++, res ++;
            else i ++;
        return res;
    }
};


int main() {

    vector<int> box1 = {1, 2, 2, 3, 4}, warehouse1 = {3, 4, 1, 2};
    cout << Solution().maxBoxesInWarehouse(box1, warehouse1) << endl;

    return 0;
}
