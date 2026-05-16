class TimeMap {
public:
    map<string, vector<pair<string, int>>> kvstore;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if (kvstore[key].size() == 0) {
            vector<pair<string, int>> temp;
            temp.push_back({value, timestamp});
            kvstore[key] = temp;
        }
        else {
            kvstore[key].push_back({value, timestamp});
        }
        return;
    }
    
    string get(string key, int timestamp) {
        int i = 0;
        int j = kvstore[key].size() - 1;

        while (i <= j) {
            int mid = i + (j - i) / 2;
            cout << mid << " ";
            if (kvstore[key][mid].second <= timestamp) {
                i = mid + 1;
            }
            else j = mid - 1;
        }
        cout << "\n";
        // cout << i << " " << j << " ";
        if (j < 0) return "";
        return kvstore[key][j].first;
    }
};
