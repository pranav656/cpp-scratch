#include <bits/stdc++.h>

using namespace std;

enum OrderType { BUY,
    SELL };

struct Order {
    int id;
    int quantity;
    float price;
};

struct buy_cmp {
    bool operator()(const Order& o1, const Order& o2) const
    {
        // sort based on the highest price
        if (o1.price < o2.price) {
            return true;
        }
        else if (o1.price == o2.price) {
            // if prices are equal, then based on time (in this case id)
            if (o1.id > o2.id)
                return true;
            return false;
        }
        else {
            return false;
        }
    }
};

struct sell_cmp {
    bool operator()(const Order& o1, const Order& o2) const
    {
        // sort based on the lowest price
        if (o1.price > o2.price) {
            return true;
        }
        else if (o1.price == o2.price) {
            // if prices are equal, then based on time (in this case id)
            if (o1.id > o2.id)
                return true;
            return false;
        }
        else {
            return false;
        }
    }
};
class OrderBook {
public:
    priority_queue<Order, vector<Order>, buy_cmp> buy_orders;
    priority_queue<Order, vector<Order>, sell_cmp> sell_orders;
    void print_buy_orders()
    {
        print_orders(buy_orders);
    }

    void print_sell_orders()
    {
        print_orders(sell_orders);
    }

private:
    void print_orders(auto& orders)
    {
        auto tmp_queue = orders;
        while (!tmp_queue.empty()) {
            Order o = tmp_queue.top();
            cout << "price:" << o.price << " qty:" << o.quantity << endl;
            tmp_queue.pop();
        }
    }
};

class MarketManager {
public:
    void add_order(string symbol, const Order& o, OrderType type)
    {
        // if the symbol is already present in the market
        if (market.find(symbol) != market.end()) {
#ifdef debug
            cout << "Symbol already present, finding matching orders" << endl;
#endif
            match_order(symbol, o, type);
        }
        else {
#ifdef debug
            cout << "Symbol not present, adding to market" << endl;
#endif
            // place the first order
            OrderBook ob;
            market[symbol] = ob;
            if (type == OrderType::BUY) {
                market[symbol].buy_orders.push(o);
            }
            else {
                market[symbol].sell_orders.push(o);
            }
        }
    }

    void print_all_orders()
    {
        for (auto it = market.begin(); it != market.end(); it++) {
            cout << "Printing BUY orders for symbol " << it->first << endl;
            it->second.print_buy_orders();
            cout << "Printing SELL orders for symbol " << it->first << endl;
            it->second.print_sell_orders();
        }
    }

private:
    map<string, OrderBook> market;
    void match_order(const string& symbol, const Order& o, OrderType type)
    {
        // if the highest of buy matches with the lowest of sell
        bool matching_order_found = false;
        int volume_left_to_sell = o.quantity;
        if (type == OrderType::BUY) {
            if (!market[symbol].sell_orders.empty()) {
                Order lowest_sell_order = market[symbol].sell_orders.top();
                while (lowest_sell_order.price <= o.price && volume_left_to_sell > 0 && market[symbol].sell_orders.size() > 0) {
                    market[symbol].sell_orders.pop();
                    matching_order_found = true;
                    float profit = o.price - lowest_sell_order.price;
                    // if the quantity of buy is greater than the
                    // amount available to sell, update the buy orders
                    // with the the portion that cannot be sold
                    if (volume_left_to_sell > lowest_sell_order.quantity) {
                        volume_left_to_sell = volume_left_to_sell - lowest_sell_order.quantity;
#ifdef debug
                        cout << "Less quanity available to sell, buy order partially executed at profit:"
                             << profit << " volume left:" << volume_left_to_sell << endl;
#endif
                    }
                    else {

// if the quantity of buy is less than (or equal) to the
// amount available for sale, sell as much as possible
// and queue the remaining portion
#ifdef debug
                        cout << "Sell quantity available:" << lowest_sell_order.quantity << " volume_left_to_sell=" << volume_left_to_sell << endl;
#endif
                        int left_over_from_trade = lowest_sell_order.quantity - volume_left_to_sell;
                        volume_left_to_sell = 0;

                        if (left_over_from_trade > 0) {
                            market[symbol].sell_orders.push({ lowest_sell_order.id, left_over_from_trade,
                                lowest_sell_order.price });
                        }
                    }
                    lowest_sell_order = market[symbol].sell_orders.top();
                }
                // cout<<"Volume left after loop:"<<volume_left_to_sell<<endl;
                if (volume_left_to_sell > 0 && matching_order_found) {
#ifdef debug
                    cout << "Partial Buy Order left" << endl;
#endif
                    market[symbol].buy_orders.push({ o.id, volume_left_to_sell, o.price });
                }
            }
            if (!matching_order_found) {
#ifdef debug
                cout << "No matching order found (BUY), adding to order book" << endl;
#endif
                market[symbol].buy_orders.push(o);
            }
        }

        // Logic for SELL orders (Duplicate code as BUY, refactor)
        else {
            if (!market[symbol].buy_orders.empty()) {
                Order highest_buy_order = market[symbol].buy_orders.top();
                while (highest_buy_order.price >= o.price && volume_left_to_sell > 0 && market[symbol].buy_orders.size() > 0) {
#ifdef debug
                    cout << "Match buy found for incoming sell order" << endl;
#endif
                    market[symbol].buy_orders.pop();
                    matching_order_found = true;
                    float profit = highest_buy_order.price - o.price;
                    if (volume_left_to_sell > highest_buy_order.quantity) {
                        volume_left_to_sell = volume_left_to_sell - highest_buy_order.quantity;
#ifdef debug
                        cout << "Less quanity available to buy, buy order partially executed at profit:"
                             << profit << " volume left:" << volume_left_to_sell << endl;
#endif
                    }
                    else {

                        // if the quantity of sell is less than (or equal) to the
                        // amount available for sale, buy as much as possible
                        // and queue the remaining portion
                        cout << "Buy quantity available:" << highest_buy_order.quantity << " volume_left_to_sell=" << volume_left_to_sell << endl;
                        int left_over_from_trade = highest_buy_order.quantity - volume_left_to_sell;
                        volume_left_to_sell = 0;
                        if (left_over_from_trade > 0) {
                            market[symbol].buy_orders.push({ highest_buy_order.id, left_over_from_trade,
                                highest_buy_order.price });
                        }
                    }
                    highest_buy_order = market[symbol].buy_orders.top();
                }
                if (volume_left_to_sell > 0 && matching_order_found) {
#ifdef debug
                    cout << "Partial Sell Order left" << endl;
#endif
                    market[symbol].sell_orders.push({ o.id, volume_left_to_sell, o.price });
                }
            }
            //Order highest_buy_order = market[symbol].buy_orders.top();
            //cout<<highest_buy_order.price<<endl;
            if (!matching_order_found) {
#ifdef debug
                cout << "No matching order found (SELL), adding to order book" << endl;
#endif
                market[symbol].sell_orders.push(o);
            }
        }
    }
};

int main()
{
    MarketManager m;
    Order o1{ 0, 20, 120 };
    m.add_order("AAPL", o1, OrderType::BUY);
    Order o2{ 1, 20, 130 };
    m.add_order("AAPL", o2, OrderType::BUY);
    Order o3{ 3, 20, 130 };
    m.add_order("AAPL", o3, OrderType::BUY);
    Order o4{ 4, 20, 130 };
    m.add_order("AAPL", o4, OrderType::SELL);
    Order o5{ 5, 20, 140 };
    m.add_order("AAPL", o5, OrderType::SELL);
    // Two buy orders left at 130,120 prices
    // One sell order left at 140 price
    m.print_all_orders();

    return 0;
}
