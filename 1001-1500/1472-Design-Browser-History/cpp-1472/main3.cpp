/// Source : https://leetcode.com/problems/design-browser-history/
/// Author : liuyubobobo
/// Time   : 2020-06-06

#include <iostream>
#include <vector>

using namespace std;


/// Using Array
/// make a sz to record the valid length
/// Time Complexity: init: O(1)
///                  visit: O(1)
///                  back: O(1)
///                  forward: O(1)
class BrowserHistory {

private:
    vector<string> history;
    int p, sz;

public:
    BrowserHistory(string homepage) : p(0), sz(1) {
        history.push_back(homepage);
    }

    void visit(string url) {
        if(p + 1 < history.size()) history[++p] = url;
        else history.push_back(url), p ++;
        sz = p + 1;
    }

    string back(int steps) {
        p = max(0, p - steps);
        return history[p];
    }

    string forward(int steps) {
        p = min(sz - 1, p + steps);
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

    BrowserHistory bh("leetcode.com");
    bh.visit("google.com");
    bh.visit("facebook.com");
    bh.visit("youtube.com");

    cout << bh.back(1) << endl; // facebook
    cout << bh.back(1) << endl; // google
    cout << bh.forward(1) << endl; // facebook

    bh.visit("linkedin.com");

    cout << bh.forward(2) << endl; // linkedin
    cout << bh.back(2) << endl; // google
    cout << bh.back(7) << endl; // leetcode

    return 0;
}
