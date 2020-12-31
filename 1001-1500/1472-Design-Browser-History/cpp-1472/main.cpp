/// Source : https://leetcode.com/problems/design-browser-history/
/// Author : liuyubobobo
/// Time   : 2020-06-06

#include <iostream>
#include <vector>

using namespace std;


/// Using Array
/// Time Complexity: init: O(1)
///                  visit: O(n)
///                  back: O(1)
///                  forward: O(1)
class BrowserHistory {

private:
    vector<string> history;
    int p;

public:
    BrowserHistory(string homepage) : p(0) {
        history.push_back(homepage);
    }

    void visit(string url) {
        while(p + 1 != history.size()) history.pop_back();
        history.push_back(url);
        p ++;
    }

    string back(int steps) {

        p = max(0, p - steps);
        return history[p];
    }

    string forward(int steps) {

        p = min((int)history.size() - 1, p + steps);
        return history[p];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

int main() {

    return 0;
}
