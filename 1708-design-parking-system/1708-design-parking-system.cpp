class ParkingSystem {
public:
    int arr[3]; 
    ParkingSystem(int big, int medium, int small) {
        memset(arr, 0 ,sizeof(arr));
        arr[0] = big;
        arr[1] = medium;
        arr[2] = small;
    }
    
    bool addCar(int carType) {
        if(arr[carType-1] > 0){
            arr[carType-1]--;
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