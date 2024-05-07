
// Simple solution using map
class TimeMap {
private:
    map<string, map<int, string>> store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        string ans;
        // logn search
        auto ptr = store[key].upper_bound(timestamp);
        if(ptr == store[key].begin()) return "";
        return prev(ptr)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
