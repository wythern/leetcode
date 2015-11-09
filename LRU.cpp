#include "common.h"

class LRUCache{
public:
    LRUCache(int capacity) {
        m_cap = capacity;
    }
    
    int get(int key) {
        return getImpl(key, true);
    }

    int getImpl(int key, bool bUpdate) {
        int val = -1;
        map<int, int>::iterator it = kvPairs.find(key);
        if(it != kvPairs.end()){
            val = it->second;
            if(bUpdate) updateKeyIdxMap(key);
        }
        return val;
    }

    void updateKeyIdxMap(int key){
        map<int, list<int>::iterator>::iterator itKiPair = kiPairs.find(key);
        keyFIFO.erase(itKiPair->second);
        keyFIFO.push_back(key);
        kiPairs[key] = --keyFIFO.end();
    }
    
    void set(int key, int value) {
        if(getImpl(key, false) == -1){
            if(keyFIFO.size() == m_cap){
                int oldKey = keyFIFO.front();
                keyFIFO.pop_front();
                kvPairs.erase(oldKey);
            }

            keyFIFO.push_back(key);
            kiPairs[key] = --keyFIFO.end();
        }else{
            updateKeyIdxMap(key);
        }

        kvPairs[key] = value;
    }
private:
    list<int> keyFIFO;
    map<int, int> kvPairs;
    map<int, list<int>::iterator> kiPairs;
    int m_cap;
};


int main(int argc, char** argv){
    char file[256] = "lru.input";
    if(argc > 1)
        strcpy(file, argv[1]);

    FILE* fp = fopen(file, "r");
    if(NULL == fp)
        return 0;

    char str[256];
    char* pszLine = NULL;
    int cap = 1;
    if ((pszLine = fgets(str, 256, fp)) != NULL)
        cap = atoi(pszLine);
    LRUCache s(cap);

    while((pszLine = fgets(str, 256, fp)) != NULL){
        if(string(pszLine, pszLine + 3) == string("set")){
            int key = 0;
            int val = 0;
            sscanf(pszLine+3, "(%d,%d)", &key, &val);
            s.set(key, val);
        }else if(string(pszLine, pszLine + 3) == string("get")){
            int key = 0;
            sscanf(pszLine+3, "(%d)", &key);
            int val = s.get(key);
            //if(val == -1) cout << "Not Found " << key << " ." << endl;
            //else cout << "Get " << key << "," << val << " ." << endl;
        }

    }

	return 0;
}
