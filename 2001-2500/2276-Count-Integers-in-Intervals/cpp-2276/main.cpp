/// Source : https://leetcode.com/problems/count-integers-in-intervals/
/// Author : liuyubobobo
/// Time   : 2022-05-15

#include <iostream>
#include <set>

using namespace std;


/// Using Set
/// Time Complexity: init: O(1)
///                  add: O(logn) in everage
///                  count: O(1)
/// Space Complexity: O(n)
class CountIntervals {

private:
    set<pair<int, int>> intervals;
    int num = 0;

public:
    CountIntervals() { }

    void add(int left, int right) {

        auto iter = intervals.lower_bound({left, left - 1});
        if(iter != intervals.begin()){
            iter --;
            if(intersection(left, right, iter->first, iter->second)){
                left = min(left, iter->first);
                right = max(right, iter->second);

                num -= (iter->second - iter->first + 1);
                intervals.erase(iter);
            }
        }

        while(true) {
            auto iter = intervals.lower_bound({left, left - 1});
            if(iter == intervals.end()) break;

            if(intersection(left, right, iter->first, iter->second)){
                left = min(left, iter->first);
                right = max(right, iter->second);

                num -= (iter->second - iter->first + 1);
                intervals.erase(iter);
            }
            else break;
        }

        intervals.insert({left, right});
        num += right - left + 1;
    }

    int count() {
        return num;
    }

private:
    bool intersection(int l1, int r1, int l2, int r2){
        if(l1 > l2) swap(l1, l2), swap(r1, r2);
        return l2 <= r1;
    }
};


int main() {

    CountIntervals obj;
    obj.add(2, 3);
    cout << obj.count() << '\n'; // 2

    obj.add(7, 10);
    cout << obj.count() << '\n'; // 6

    obj.add(5, 8);
    cout << obj.count() << '\n'; // 8

    return 0;
}
