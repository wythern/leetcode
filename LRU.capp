class LRUCache{
public:
    LRUCache(int capacity) {
        m_cap = capacity;
    }
    
    int get(int key) {
        map<int, int>::iterator it = kvPairs.find(key);
        if(it != kvPairs.end())
            return it->second;
        return -1;
    }
    
    void set(int key, int value) {
        if(keyFIFO.size() == m_cap){
            int oldKey = keyFIFO.front();
            keyFIFO.pop_front();
            kvPairs.erase(oldKey);
        }
        
        kvPairs[key] = value;
        keyFIFO.push_back(key);   
    }
    
private:
    list<int> keyFIFO;
    map<int, int> kvPairs;
    int m_cap;
};