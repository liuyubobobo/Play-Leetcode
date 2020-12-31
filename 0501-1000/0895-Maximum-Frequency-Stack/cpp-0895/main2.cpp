/// Source : https://leetcode.com/problems/maximum-frequency-stack/description/
/// Author : liuyubobobo
/// Time   : 2018-08-26

#include <iostream>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;


/// Using Two HashSets: (freq: stack) HashSet and (key: freq) HashSet
/// keeping max_freq in FreqStack to get pop element:)
///
/// Time Complexity: push: O(1)
///                  pop: O(1)
/// Space Complexity: O(n)
class FreqStack {

private:
    unordered_map<int, stack<int>> order; // freq -> order stack
    unordered_map<int, int> freq; // key -> freq
    int max_freq;

public:
    FreqStack() {
        order.clear();
        freq.clear();
        max_freq = 0;
    }

    void push(int x) {

        freq[x] ++;
        order[freq[x]].push(x);

        if(max_freq < freq[x])
            max_freq = freq[x];
    }

    int pop() {

        int ret = order[max_freq].top();
        order[max_freq].pop();
        if(order[max_freq].empty())
            max_freq --;

        freq[ret] --;
        return ret;
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