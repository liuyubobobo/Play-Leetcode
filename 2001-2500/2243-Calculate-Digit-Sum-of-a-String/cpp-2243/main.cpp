#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {

        for(int start = 0; start + m < arr.size(); start ++)
            if(ok(arr, start, m, k)) return true;
        return false;
    }

private:
    bool ok(const vector<int>& arr, int start, int m, int k){

        for(int i = 0; i < m; i ++)
            for(int j = 0; j < k; j ++){
                if(start + j * m + i >= arr.size()) return false;
                if(arr[start + i] != arr[start + j * m + i]) return false;
            }
        return true;
    }
};

int main() {

    vector<int> arr1 = {1,2,4,4,4,4};
    cout << Solution().containsPattern(arr1, 1, 3) << endl;
    // 1

    vector<int> arr2 = {1,2,4,4,4};
    cout << Solution().containsPattern(arr2, 1, 3) << endl;
    // 1

    vector<int> arr3 = {1,2,4,4};
    cout << Solution().containsPattern(arr3, 1, 3) << endl;
    // 0

    vector<int> arr4 = {1,2,1,2,1,1,1,3};
    cout << Solution().containsPattern(arr4, 2, 2) << endl;
    // 1

    vector<int> arr5 = {1,2,1,2,1,3};
    cout << Solution().containsPattern(arr5, 2, 3) << endl;
    // 0

    vector<int> arr6 = {1,2,3,1,2};
    cout << Solution().containsPattern(arr6, 2, 2) << endl;
    // 0

    vector<int> arr7 = {2,2,2,2};
    cout << Solution().containsPattern(arr7, 2, 3) << endl;
    // 0

    return 0;
}
