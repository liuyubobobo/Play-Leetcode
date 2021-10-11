/// Source : https://leetcode.com/problems/stock-price-fluctuation/
/// Author : liuyubobobo
/// Time   : 2021-10-10

#include <iostream>
#include <set>
#include <map>

using namespace std;


/// Using MultiSet
/// Time Complexity: O(logn)
/// Space Complexity: O(n)
class StockPrice {

private:
    map<int, int> stocks; // time, price
    multiset<int> prices; // (price, time)

public:
    StockPrice() {}

    void update(int timestamp, int price) {

        if(stocks.count(timestamp))
            prices.erase(prices.find(stocks[timestamp]));

        stocks[timestamp] = price;
        prices.insert(price);
    }

    int current() {
        return stocks.rbegin()->second;
    }

    int maximum() {
        return *prices.rbegin();
    }

    int minimum() {
        return *prices.begin();
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
