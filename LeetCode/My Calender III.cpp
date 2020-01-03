class MyCalendarThree {
public:
    map<int, int> mp;
    MyCalendarThree() {
        mp.clear();
    }
    
    int book(int start, int end) {
        int booked = 0;
        mp[start]++;
        mp[end]--;
        int maxBooked = 0;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            booked += it -> second;
            maxBooked = max(booked, maxBooked);
        }
        return maxBooked;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
