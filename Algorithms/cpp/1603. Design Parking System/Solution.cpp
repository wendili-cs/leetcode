// https://leetcode-cn.com/problems/design-parking-system/

class ParkingSystem {
public:
    vector<int> sp;
    ParkingSystem(int big, int medium, int small) {
        sp = {big, medium, small};
    }
    
    bool addCar(int carType) {
        if(sp[carType - 1] > 0){
            sp[carType - 1]--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */