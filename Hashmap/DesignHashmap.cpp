// LC706 - Design Hashmap
class MyHashMap {
private:
    // atmost 10^4 calls
    static constexpr int N = 10001;
    vector<list<pair<int, int>>> m_hashmap;
public:
    MyHashMap() {
        m_hashmap = vector<list<pair<int, int>>>(N);
    }
    
    list<pair<int, int>>::iterator find(int key)
    {
        int bucket = key % N;
        for(auto it = m_hashmap[bucket].begin(); it != m_hashmap[bucket].end(); it++)
        {
            if(it->first == key) return it;
        }
        return m_hashmap[bucket].end();

    }

    void put(int key, int value) {
        auto bucket =  key % N;
        auto it = find(key);
        if(it == m_hashmap[bucket].end())
        {
            m_hashmap[bucket].push_back({key, value});
        }
        else
        {
            it->second = value;
        }
    }
    
    int get(int key) {
        auto bucket =  key % N;
        auto it = find(key);
        if(it == m_hashmap[bucket].end())
        {
            return -1;
        }
        else
        {
            return it->second;
        }
    }
    
    void remove(int key) {
        auto bucket =  key % N;
        auto it = find(key);
        if(it != m_hashmap[bucket].end())
        {
            m_hashmap[bucket].erase(it);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
