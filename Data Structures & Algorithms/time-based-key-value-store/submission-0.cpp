class TimeMap {
public:
    unordered_map<string, map<int, string>> mp;

    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = mp[key].upper_bound(timestamp);
        
        if(it == mp[key].begin()) return "";
        else return (--it)->second;
    }
};
