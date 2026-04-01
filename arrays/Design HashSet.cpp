// TC:O(1) SC:O(n) 
class MyHashSet {
    vector<bool> stt;

public:
    MyHashSet() { stt = vector<bool>(1000001, false); }

    void add(int key) { stt[key] = true; }

    void remove(int key) { stt[key] = false; }

    bool contains(int key) { return stt[key]; }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
