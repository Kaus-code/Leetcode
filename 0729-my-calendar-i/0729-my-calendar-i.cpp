class MyCalendar {
public:
    vector<pair<int,int>> booking;

    MyCalendar() {}

    bool book(int startTime, int endTime) {
        for (auto [s, e] : booking) {
           
            if (startTime < e && s < endTime)
                return false;
        }
        
        booking.push_back({startTime, endTime});
        return true;
    }
};
