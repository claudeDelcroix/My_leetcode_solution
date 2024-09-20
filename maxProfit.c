int maxProfit(int* prices, int pricesSize) {
    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }

    return maxProfit;
}
int maxProfit(int* prices, int pricesSize) {

    if (pricesSize < 2) {
        return 0;
    }

    int min_price = prices[0];
    int max_profit = 0;

    for (int i = 1; i < pricesSize; i++) {
        // Update the minimum price so far
        if (prices[i] < min_price) {
            min_price = prices[i];
        }

        // Calculate the profit if we sold at the current price
        int profit = prices[i] - min_price;

        // Update the maximum profit so far
        if (profit > max_profit) {
            max_profit = profit;
        }
    }

    return max_profit;
}
