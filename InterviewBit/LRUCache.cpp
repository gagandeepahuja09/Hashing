int n;

class Node {
    public:
    Node *next, *prev;
    int key, val;
    Node(int k, int v) {
        key = k; 
        val = v;
        next = NULL;
        prev = NULL;
    }
};
Node *head, *tail; 
unordered_map<int, Node*> mp;

void moveToFront(Node* &curr) {
    Node* prev = curr -> prev;
    if(!prev)
        return;
    Node* next = curr -> next;
    prev -> next = next;
    if(next)
        next -> prev = prev;
    curr -> next = head;
    head -> prev = curr;
    head = curr;
}

LRUCache::LRUCache(int capacity) {
    mp.clear();
    head = tail = NULL;
    n = capacity;
}

void insertAtFront(int key, int value) {
    if(!head) {
        head = new Node(key, value);
        tail = head;
    }
    else {
        Node* temp = new Node(key, value);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
    mp[key] = head;
}

int removeLRU() {
    Node* prev = tail -> prev;
    int x=tail->key;
    if(!prev)
    {
        head = tail = NULL;
        delete (tail);
        return x;
    }
    Node* temp = tail;
    tail = prev;
    tail -> next = NULL;
    int key = temp -> key;
    delete(temp);
    return key;
}

int LRUCache::get(int key) {
    // key does not exist
    if(mp.find(key) == mp.end())
        return -1;
    // key exists move at front and return val
    int val = mp[key] -> val;
    Node* curr = mp[key];
    moveToFront(curr);
    return val;
}

void LRUCache::set(int key, int value) {
    if(mp.find(key) != mp.end()) {
        // key exists
        // move at front and update val
        Node* curr = mp[key];
        moveToFront(curr);
        curr -> val = value;
    }
    else {
        // key does not exist
        // check size
        // if map size is greater than or equal to capacity
        // remove lru from back and insert element at front
        if(mp.size() >= n) {
            int k = removeLRU();
            mp.erase(k);
        }
        // insert at front of dll
        insertAtFront(key, value);
    }
}

