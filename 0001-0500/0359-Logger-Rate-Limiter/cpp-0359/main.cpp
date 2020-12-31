/// Source : https://leetcode.com/problems/logger-rate-limiter/description/
/// Author : liuyubobobo
/// Time   : 2018-10-02

#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;


/// Using a Queue and HashSet
/// Time Complexity: init: O(1)
///                  shouldPrintMessage: O(10)
/// Space Complexity: O(10)
class Logger {

private:
    unordered_set<string> messages;
    queue<pair<int, string>> q;

public:
    /** Initialize your data structure here. */
    Logger() {}

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {

        while(!q.empty()){
            if(timestamp - q.front().first >= 10){
                messages.erase(q.front().second);
                q.pop();
            }
            else
                break;
        }

        if(messages.count(message))
            return false;

        messages.insert(message);
        q.push(make_pair(timestamp, message));
        return true;
    }
};


int main() {

    return 0;
}