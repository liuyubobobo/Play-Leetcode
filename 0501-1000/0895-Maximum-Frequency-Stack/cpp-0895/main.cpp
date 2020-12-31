/// Source : https://leetcode.com/problems/maximum-frequency-stack/description/
/// Author : liuyubobobo
/// Time   : 2018-08-25

#include <iostream>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;


/// Using (freq, time) pair to record the order of all elements
/// Time Complexity: push: O(logn)
///                  pop: O(logn)
/// Space Complexity: O(n)
class FreqStack {

private:
    unordered_map<int, stack<int>> order;
    unordered_map<int, pair<int, int>> freq;
    map<pair<int, int>, int> data;

    int times = 0;

public:
    FreqStack() {
        order.clear();
        freq.clear();
        data.clear();
        times = 0;
    }

    void push(int x) {

        if(freq.find(x) == freq.end())
            freq[x] = make_pair(1, times);
        else{
            pair<int, int> p = freq[x];
            p.first += 1;
            p.second = times;
            freq[x] = p;
        }

        data[freq[x]] = x;
        order[x].push(times);

        times ++;
    }

    int pop() {
        pair<int, int> freqData = data.rbegin()->first;
        int key = data.rbegin()->second;

        data.erase(freqData);
        freqData.first -= 1;
        order[key].pop();
        if(freqData.first == 0)
            freq.erase(key);
        else {
            freqData.second = order[key].top();
            freq[key] = freqData;
            data[freqData] = key;
        }

        return key;
    }
};


int main() {

    FreqStack stack;
    stack.push(5);
    stack.push(7);
    stack.push(5);
    stack.push(7);
    stack.push(4);
    stack.push(5);

    cout << stack.pop() << endl; // 5
    cout << stack.pop() << endl; // 7
    cout << stack.pop() << endl; // 5
    cout << stack.pop() << endl; // 4
    return 0;
}