#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> prices = {7,6,5,4,3,2,1};
    int minprice = prices[0];
    int maxprofit = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        
        if (prices[i] < minprice)
        {
            minprice = prices[i];
        }
        
        int profit = prices[i] - minprice;
        maxprofit = max(maxprofit, profit);
        
        cout << " Minprice - " << i + 1 << " is " << minprice << endl;
        cout << " profit - " << i + 1 << " is " << profit << endl;
        cout << " maxprofit - " << i + 1 << " is " << maxprofit << endl;
    }

    return 0;
}
