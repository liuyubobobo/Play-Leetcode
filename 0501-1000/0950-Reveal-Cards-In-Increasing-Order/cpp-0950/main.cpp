/// Source : https://leetcode.com/problems/reveal-cards-in-increasing-order/
/// Author : liuyubobobo
/// Time   : 2018-12-01

#include <iostream>
#include <vector>
#include <deque>

using namespace std;


/// Simulation with deque
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        sort(deck.begin(), deck.end(), greater<int>());

        deque<int> deque;
        deque.push_back(deck[0]);
        for(int i = 1; i < deck.size(); i ++){
            int back = deque.back();
            deque.pop_back();
            deque.push_front(back);
            deque.push_front(deck[i]);
        }

        return vector<int>(deque.begin(), deque.end());
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> deck1 = {17, 13, 11, 2, 3, 5, 7};
    print_vec(Solution().deckRevealedIncreasing(deck1));

    return 0;
}