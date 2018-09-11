/// Source : https://leetcode.com/problems/online-stock-span/description/
/// Author : liuyubobobo
/// Time   : 2018-09-10

#include <iostream>
#include <vector>

using namespace std;


/// Using Stack
/// Time Complexity: init: O(1)
///                  next: O(1) - average
/// Space Complexity: O(n)
class StockSpanner {

private:
    vector<pair<int, int>> nums;

public:
    StockSpanner() {
        nums.clear();
    }

    int next(int price) {

        if(nums.size() == 0 || price < nums.back().first){
            nums.push_back(make_pair(price, 1));
            return 1;
        }

        int cnt = 1;
        while(!nums.empty() && nums.back().first <= price){
            cnt += nums.back().second;
            nums.pop_back();
        }
        nums.push_back(make_pair(price, cnt));
        return cnt;
    }
};


int main() {

    StockSpanner stockSpanner;
    cout << stockSpanner.next(100) << endl; // 1
    cout << stockSpanner.next(80) << endl; // 1
    cout << stockSpanner.next(60) << endl; // 1
    cout << stockSpanner.next(70) << endl; // 2
    cout << stockSpanner.next(60) << endl; // 1
    cout << stockSpanner.next(75) << endl; // 4
    cout << stockSpanner.next(85) << endl; // 6

    return 0;
}