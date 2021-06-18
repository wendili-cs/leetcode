// https://leetcode-cn.com/problems/design-parking-system/

class ParkingSystem {
private:
    vector<int> slots;
    vector<int> cur;
public:
    ParkingSystem(int big, int medium, int small) {
        slots = vector<int>(4, 0);
        cur = vector<int>(4, 0);
        slots[1] = big;
        slots[2] = medium;
        slots[3] = small;
    }
    
    bool addCar(int carType) {
        if(cur[carType] >= slots[carType]) return false;
        else cur[carType]++;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */