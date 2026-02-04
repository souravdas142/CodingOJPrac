class RideSharingSystem {
public:
    queue<int> driver;
    deque<int> rider;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        rider.push_back(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(rider.empty()!=true && driver.empty()!=true) {
            int r = rider.front(); rider.pop_front();
            int d = driver.front(); driver.pop();
            return {d,r};
        }
        else return {-1,-1};
    }
    
    void cancelRider(int riderId) {
        deque<int> tmp;
        while(!rider.empty()) {
            int r = rider.front();
            rider.pop_front();
            if(r==riderId) {
                break;
            }
            tmp.push_back(r);
        }

        while(!tmp.empty()) {
            int r = tmp.back();
            rider.push_front(r);
            tmp.pop_back();
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */