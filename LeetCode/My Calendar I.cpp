struct Node {
    int start;
    int end;
    Node *left, *right;
    Node(int s, int e) {
        start = s;
        end = e;
        left = NULL;
        right = NULL;
    }
};

class MyCalendar {
    public:
    Node *head;
    MyCalendar() {
        head = NULL;
    }
    bool book(int start, int end) {
        Node *curr = this -> head, *prev = NULL;
        if(curr == NULL) {
            this -> head = new Node(start, end);
            return true;
        }
        while(curr) {
            prev = curr;
            if(curr -> start >= end) {
                curr = curr -> left;
            }
            else if(start >= curr -> end) {
                curr = curr -> right;
            }
            else
                return false;
        }
        Node *newEntry = new Node(start, end);
        if(end <= prev -> start) {
            prev -> left = newEntry;
        }
        else
            prev -> right = newEntry;
        return true;
    } 
};

/*
struct cmp{ 
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
        return a.second <= b.first;
    }
};

class MyCalendar {
    set<pair<int, int>, cmp> booked;
public: 
    
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        return booked.insert({ start, end }).second;    
    }
};
*/

