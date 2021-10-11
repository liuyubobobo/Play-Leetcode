/// Source : https://leetcode.com/problems/stock-price-fluctuation/
/// Author : liuyubobobo
/// Time   : 2021-10-09

#include <iostream>
#include <set>
#include <map>

using namespace std;


/// Using Set
/// Time Complexity: O(logn)
/// Space Complexity: O(n)
class StockPrice {

private:
    map<int, int> stocks; // time, price
    set<pair<int, int>> prices; // (price, time)

public:
    StockPrice() {}

    void update(int timestamp, int price) {

        if(stocks.count(timestamp)){
            int p = stocks[timestamp];
            prices.erase({p, timestamp});
        }

        stocks[timestamp] = price;
        prices.insert({price, timestamp});
    }

    int current() {
        return stocks.rbegin()->second;
    }

    int maximum() {
        return prices.rbegin()->first;
    }

    int minimum() {
        return prices.begin()->first;
    }
};

int main() {

    StockPrice st;
    st.update(1, 10);
    st.update(2, 5);
    cout << st.current() << endl;
    cout << st.maximum() << endl;
    st.update(1, 3);
    cout << st.maximum() << endl; // 5

    return 0;
}
