/// Source : https://leetcode.com/problems/design-browser-history/
/// Author : liuyubobobo
/// Time   : 2020-06-06

#include <iostream>
#include <stack>

using namespace std;


/// Two Stacks
/// Time Complexity: init: O(1)
///                  visit: O(1)
///                  back: O(step)
///                  forward: O(step)
class BrowserHistory {

private:
    stack<string> history, backhistory;

public:
    BrowserHistory(string homepage){
        history.push(homepage);
    }

    void visit(string url) {
        history.push(url);
        backhistory = stack<string>();
    }

    string back(int steps) {
        while(steps -- && history.size() > 1)
            backhistory.push(history.top()), history.pop();
        return history.top();
    }

    string forward(int steps) {
        while(steps -- && backhistory.size())
            history.push(backhistory.top()), backhistory.pop();
        return history.top();
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
