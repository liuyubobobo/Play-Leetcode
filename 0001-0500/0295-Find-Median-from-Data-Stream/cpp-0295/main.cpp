/// https://leetcode.com/problems/find-median-from-data-stream/
/// Author : liuyubobobo
/// Time   : 2019-09-22

#include <iostream>
#include <vector>

using namespace std;


/// Insertion Sort
/// Time Complexity: add: O(n)
///                  findMedian: O(1)
class MedianFinder {

private:
    vector<int> data;

public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {

        data.push_back(num);

        int i;
        for(i = (int)data.size() - 1; i >= 1 && data[i] > data[i - 1]; i --)
            swap(data[i], data[i - 1]);
    }

    double findMedian() {

        if(data.size() % 2) return data[data.size() / 2];
        return (data[data.size() / 2 - 1] + data[data.size() / 2]) / 2.0;
    }
};


int main() {

    MedianFinder mf;
    mf.addNum(6);
    cout << "after adding 6 :" << mf.findMedian() << endl; // 6

    mf.addNum(10);
    cout << "after adding 10 :" << mf.findMedian() << endl; // 8

    mf.addNum(2);
    cout << "after adding 2 :" << mf.findMedian() << endl; // 6

    mf.addNum(6);
    cout << "after adding 6 :" << mf.findMedian() << endl; // 6

    mf.addNum(5);
    cout << "after adding 5 :" << mf.findMedian() << endl; // 6

    mf.addNum(0);
    cout << "after adding 0 :" << mf.findMedian() << endl; // 5.5

    mf.addNum(6);
    cout << "after adding 6 :" << mf.findMedian() << endl; // 6.0

    mf.addNum(3);
    cout << "after adding 3 :" << mf.findMedian() << endl; // 5.5

    return 0;
}