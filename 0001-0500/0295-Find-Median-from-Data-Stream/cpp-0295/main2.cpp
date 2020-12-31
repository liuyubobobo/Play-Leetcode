/// https://leetcode.com/problems/find-median-from-data-stream/
/// Author : liuyubobobo
/// Time   : 2019-09-22

#include <iostream>
#include <map>

using namespace std;


/// Using TreeMap
/// Time Complexity: add: O(logn)
///                  findMedian: O(logn)
class MedianFinder {

private:
    map<int, int> data;
    int count = 0;

    map<int, int>::iterator iter;
    int index = 0;

public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {

        if(!count){
            data[num] ++;
            iter = data.begin();
            count ++;
            return;
        }

        data[num] ++;
        if(count % 2){ // odd number
            if(num < iter->first){
                if(index) index --;
                else iter --, index = iter->second - 1;
            }
        }
        else{ // even number
            if(num >= iter->first){
                if(index + 1 < iter->second) index ++;
                else iter ++, index = 0;
            }
        }
        count ++;
    }

    double findMedian() {

        if(count % 2) return iter->first;

        if(index + 1 < iter->second) return iter->first;

        map<int, int>::iterator iter2 = iter;
        iter2 ++;
        return (iter->first + iter2->first) / 2.0;
    }
};


int main() {

    MedianFinder mf;
    mf.addNum(6);
    cout << "after adding 6 " << mf.findMedian() << endl; // 6

    mf.addNum(10);
    cout << "after adding 10 " << mf.findMedian() << endl; // 8

    mf.addNum(2);
    cout << "after adding 2 " << mf.findMedian() << endl; // 6

    mf.addNum(6);
    cout << "after adding 6 " << mf.findMedian() << endl; // 6

    mf.addNum(5);
    cout << "after adding 5 " << mf.findMedian() << endl; // 6

    mf.addNum(0);
    cout << "after adding 0 " << mf.findMedian() << endl; // 5.5

    mf.addNum(6);
    cout << "after adding 6 " << mf.findMedian() << endl; // 6.0

    mf.addNum(3);
    cout << "after adding 3 " << mf.findMedian() << endl; // 5.5

    return 0;
}