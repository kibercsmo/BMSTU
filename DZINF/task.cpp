#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Light{
protected:
    bool isOn = false;
public:
    void turnOn(){isOn = true;};
    void turnOff(){isOn = false;};
    
    std::string getStatus(){
       if (isOn){
        return "ON";
       }
       else{
        return "OFF";
       } 
    };

    bool getState(){return isOn;};
    void setState(bool OnOff){isOn = OnOff;};
};

class Thermostat{
protected:
    int temperature = 20;
public:
    void setTemperature(int temperature){this->temperature = temperature;};
    int getTemperature(){return temperature;};
};

class SecuritySystem{
protected:
    bool isArmed = false;
public:
    void arm(){isArmed = true;};
    void disarm(){isArmed = false;};

    std::string getStatus(){
        if (isArmed){
            return "Armed";
        }
        else{
            return "Disarmed";
        }
    };

    bool getState(){return isArmed;};
    void setState(bool ArmDisarm){isArmed = ArmDisarm;};
};

class Curtains{
protected:
    bool isUp = false;
public:
    void raise(){isUp = true;};
    void lower(){isUp = false;};

    std::string getStatus(){
        if (isUp){
            return "Raised";
        }
        else{
            return "Lowered";
        }
    };

    bool getState(){return isUp;};
    void setState(bool UpDown){isUp = UpDown;};
};

class AirConditioner{
protected:
    bool isOn = false;
public:
    void turnOn(){isOn = true;};
    void turnOff(){isOn = false;};
    
    std::string getStatus(){
       if (isOn){
        return "ON";
       }
       else{
        return "OFF";
       } 
    };

    bool getState(){return isOn;};
    void setState(bool OnOff){isOn = OnOff;}; 
};

class SmartHome{
private:
    Light light;
    Thermostat thermostat;
    SecuritySystem securitySystem;
    Curtains curtains;
    AirConditioner airConditioner;

    std::string stateFile = "home_state.txt";
    short buff;

public:
    
    void controlLight(bool state){light.setState(state);};
    void setTemperature(int temperature){thermostat.setTemperature(temperature);};
    void controlSecurity(bool state){securitySystem.setState(state);};
    void controlCurtains(bool state){curtains.setState(state);};
    void controlAirConditioner(bool state){airConditioner.setState(state);};

    std::string getFile(){return stateFile;};

    void displayStatus(){
        std::cout << "Light: "           << light.getStatus()           << std::endl;
        std::cout << "Temperature: "     << thermostat.getTemperature() << "*C" << std::endl;
        std::cout << "Security system: " << securitySystem.getStatus()  << std::endl;
        std::cout << "Curtains: "        << curtains.getStatus()        << std::endl;
        std::cout << "Air conditioner: " << airConditioner.getStatus()  << std::endl;
    };

    void saveState(){
        std::ofstream File(stateFile);
        File << light.getState() << std::endl;
        File << thermostat.getTemperature() << std::endl;
        File << securitySystem.getState() << std::endl;
        File << curtains.getState() << std::endl;
        File << airConditioner.getState() << std::endl;
        File.close();
    };

    void loadState(){
        std::ifstream File;
        File.open(stateFile);
        if(File.is_open()){
            File >> buff;
            light.setState(buff);
            File >> buff;
            thermostat.setTemperature(buff);
            File >> buff;
            securitySystem.setState(buff);
            File >> buff;
            curtains.setState(buff);
            File >> buff;
            airConditioner.setState(buff);
        }
        else{
            std::cout << "No previous state found" << std::endl;
            std::cout << "Using default settings"  << std::endl;
            
            light.setState(0);
            thermostat.setTemperature(20);
            securitySystem.setState(0);
            curtains.setState(0);
            airConditioner.setState(0);
        }
        File.close();
    };
};

int main(){
    SmartHome home;
    short choose;

    home.loadState();
    home.displayStatus();

    start:
    std::cout << "=*=---------------------=*=" << std::endl;
    std::cout << "Choose: "                    << std::endl;
    std::cout << "1. TurnOnLight"              << std::endl;
    std::cout << "2. TurnOffLight"             << std::endl;
    std::cout << "3. Set temperature"          << std::endl;
    std::cout << "4. Arm security system"      << std::endl;
    std::cout << "5. Disrm security system"    << std::endl;
    std::cout << "6. Raise curtains"           << std::endl;
    std::cout << "7. Lower curtains"           << std::endl;
    std::cout << "8. Turn on air conditioner"  << std::endl;
    std::cout << "9. Turn off air conditioner" << std::endl;
    std::cout << "10. Exit"                    << std::endl;
    std::cout << "=*=---------------------=*=" << std::endl;
    std::cin >> choose;

    switch (choose)
    {
    case 1:
        home.controlLight(1);
        goto start;
        break;
    case 2:
        home.controlLight(0);
        goto start;
        break;
    case 3:
        std::cout << "Set temperature to: ";
        std::cin >> choose;
        home.setTemperature(choose);
        goto start;
        break;
    case 4:
        home.controlSecurity(1);
        goto start;
        break;
    case 5:
        home.controlSecurity(0);
        goto start;
        break;
    case 6:
        home.controlCurtains(1);
        goto start;
        break;
    case 7:
        home.controlCurtains(0);
        goto start;
        break;
    case 8:
        home.controlAirConditioner(1);
        goto start;
        break;
    case 9:
        home.controlAirConditioner(0);
        goto start;
        break;
    default:
        std::cout << "=*=---------------------=*="       << std::endl;
        std::cout << "Updated state:  "                  << std::endl;
        home.displayStatus();
        home.saveState();
        std::cout << "State saved to " << home.getFile() << std::endl;
        std::cout << "Exiting..."                        << std::endl;
        break;
    }
    return 0;
}