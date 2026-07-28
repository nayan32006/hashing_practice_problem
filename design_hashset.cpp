#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class MyHashSet {
private:
    int numBuckets;
    vector<list<int>> buckets;

    int hash(int key) {
        return key % numBuckets;
    }

public:
    MyHashSet() {
        numBuckets = 10007;
        buckets.resize(numBuckets);
    }
    
    void add(int key) {
        int index = hash(key);
        auto& bucket = buckets[index];
        if (find(bucket.begin(), bucket.end(), key) == bucket.end()) {
            bucket.push_back(key);
        }
    }
    
    void remove(int key) {
        int index = hash(key);
        auto& bucket = buckets[index];
        auto it = find(bucket.begin(), bucket.end(), key);
        if (it != bucket.end()) {
            bucket.erase(it);
        }
    }
    
    bool contains(int key) {
        int index = hash(key);
        auto& bucket = buckets[index];
        return find(bucket.begin(), bucket.end(), key) != bucket.end();
    }
};

int main() {
    MyHashSet* myHashSet = new MyHashSet();
    myHashSet->add(1);
    myHashSet->add(2);
    cout << (myHashSet->contains(1) ? "true" : "false") << endl;
    cout << (myHashSet->contains(3) ? "true" : "false") << endl;
    myHashSet->add(2);
    cout << (myHashSet->contains(2) ? "true" : "false") << endl;
    myHashSet->remove(2);
    cout << (myHashSet->contains(2) ? "true" : "false") << endl;

    delete myHashSet;
    return 0;
}