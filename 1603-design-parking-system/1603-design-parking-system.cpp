class ParkingSystem {
public:
    int large,bich,chota;
    ParkingSystem(int big, int medium, int small) {
        large=big;
        bich = medium;
        chota=small;
    }
    
    bool addCar(int carType) {
        if(carType==1 && large>0){
            large--;
            return true;
        }
        if(carType==2 && bich>0){
            bich--;
      return true;}  
        if(carType==3 && chota>0){
            chota--;
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