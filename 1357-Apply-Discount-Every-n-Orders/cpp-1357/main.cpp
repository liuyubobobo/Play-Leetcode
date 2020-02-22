/// Source : https://leetcode.com/problems/apply-discount-every-n-orders/
/// Author : liuyubobobo
/// Time   : 2020-02-22

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Simulation
/// Time Complexity: init: O(n)
///                  getBill: O(m)
/// Space Complexity: O(n)
class Cashier {

private:
    int n, discount;
    map<int, int> price;
    int index = 1;

public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) : n(n), discount(discount) {
        for(int i = 0; i < products.size(); i ++)
            price[products[i]] = prices[i];
    }

    double getBill(vector<int> product, vector<int> amount) {

        double res = 0.0;
        for(int i = 0; i < product.size(); i ++)
            res += price[product[i]] * amount[i];

        if(index % n == 0)
            res -= discount * res / 100;

        index ++;

        return res;
    }
};


int main() {

    return 0;
}
