class LRUCache {
public:
    list<pair<int,int>> cache;
    unordered_map<int,list<pair<int,int>> ::iterator> mp;
    int c;
    LRUCache(int capacity) {
        c =capacity;
    }
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        auto iter = mp[key];
        int val = iter->second;
        cache.erase(iter);
        cache.push_front({key,val});
        mp[key] = cache.begin();
        return val;
    }
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            cache.erase(mp[key]);
        }
        else if(c==cache.size()){
            int Lkey = cache.back().first;
            cache.pop_back();
            mp.erase(Lkey);
        }
        cache.push_front({key,value});
        mp[key] = cache.begin();
    }
};