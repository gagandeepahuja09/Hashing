/// Source: https://github.com/gagandeepahuja09/SportProgramming/blob/master/InterviewBit/Heaps-And-Maps/LRU.cpp

class Node {
    public:
        Node(int a, int b): left(0), right(0), val(a), k(b) {}
        Node *left, *right;
        int val;
        int k;
};

class Dq {
    public:
        Dq(): front(0), rear(0) {}
        Node *front, *rear;
        Node* pushFront(int, int);
        int popBack();
        void clear();
        void recentlyUsed(Node*);
};

Node* Dq::pushFront(int a, int b) {
    Node* node = new Node(a, b);
    if(!front) {
        front = node;
        rear = node;
    }
    else {
        front -> left = node;
        node -> right = front;
        front = node;
    }
    return node;
}

int Dq::popBack() {
    Node* curr = rear;
    int key = curr -> k;
    rear = rear -> left;
    if(rear)
        rear -> right = NULL;
    else
        front = NULL;
    delete curr;
    return key;
}

void Dq::clear() {
    Node* curr = front;
    while(front) {
        front = front -> right;
        delete curr;
        curr = front;
    }
    front = rear = NULL;
}

void Dq::recentlyUsed(Node* curr) {
    // Remove it from its current position
    if(!curr)
        return;
    Node* prev = curr -> left;
    if(prev)
        prev -> right = curr -> right;
    else
        return;
    Node* next = curr -> right;
    next -> left = prev;
    // Spl case if rear and curr are same
    if(rear == curr) {
        rear = curr -> left;
    }
    rear -> right = NULL;
    // Move it at the front
    curr -> right = front;
    front -> left = curr;
    curr -> left = NULL;
    front = curr;
}

unordered_map<int, Node*> mp;
int lruSize = 0;
Dq dq;

LRUCache::LRUCache(int capacity) {
    dq.clear();
    mp.clear();
    lruSize = capacity;
}

int LRUCache::get(int key) {
    if(mp.find(key) == mp.end())
        return -1;
    Node* curr = mp[key];
    dq.recentlyUsed(curr);
    return dq.front -> val;
}

void LRUCache::set(int key, int value) {
    int n = mp.size();
    // Key with this already exists in LRU
    // So it is most recently used => It should be moved to the front
    if(mp.find(key) != mp.end()) {
        Node* curr = mp[key];
        curr -> val = value;
        dq.recentlyUsed(curr); 
    }
    else {
        if(n >= lruSize) {
            mp.erase(dq.popBack());
        }
        mp[key] = dq.pushFront(value, key);
    }
}

