
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
    int capacity;
    list<pair<int, int>> items; 
    // Front = most recently used
    // Back = least recently used

    unordered_map<int, list<pair<int, int>>::iterator> pos;

public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        if (pos.find(key) == pos.end())
            return -1;

        auto it = pos[key];
        int value = it->second;

        // Move accessed item to the front
        items.splice(items.begin(), items, it);

        return value;
    }

    void put(int key, int value) {
        if (capacity <= 0) return;

        // If key exists, update and mark recently used
        if (pos.find(key) != pos.end()) {
            auto it = pos[key];
            it->second = value;
            items.splice(items.begin(), items, it);
            return;
        }

        // Remove least recently used item if full
        if ((int)items.size() == capacity) {
            int oldKey = items.back().first;
            pos.erase(oldKey);
            items.pop_back();
        }

        // Insert new item at the front
        items.push_front({key, value});
        pos[key] = items.begin();
    }
};

int main() {
    LRUCache cache(2);

    cache.put(1, 100);
    cache.put(2, 200);

    cout << cache.get(1) << '\n'; // 100
    cache.put(3, 300);            // Evicts key 2
    cout << cache.get(2) << '\n'; // -1
}
