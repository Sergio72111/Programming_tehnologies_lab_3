#include <string>
#include <iostream>

// Абстрактный базовый класс для всех электроприборов
class AbstractElectricDevice {
protected:
    std::string _name;  // Название устройства
    double _power;      // Потребляемая мощность (в ваттах)
    bool _isOn;         // Состояние устройства (включено/выключено)

public:
    AbstractElectricDevice(const std::string& name, double power)
        : _name(name), _power(power), _isOn(false) {}

    virtual void TurnOn() {
        _isOn = true;
    }

    virtual void TurnOff() {
        _isOn = false;
    }

    virtual double GetPower() const {
        return _isOn ? _power : 0;
    }

    virtual ~AbstractElectricDevice() = default; // Виртуальный деструктор
};

// Класс для бытовой техники
class HomeAppliance : public AbstractElectricDevice {
protected:
    std::string _brand; // Бренд устройства

public:
    HomeAppliance(const std::string& name, double power, const std::string& brand)//Конструктор принимает название, мощность и бренд устройства.
        : AbstractElectricDevice(name, power), _brand(brand) {}

    std::string GetBrand() const {
        return _brand;
    }
};

// Класс для электроинструментов
class PowerTool : public AbstractElectricDevice {
protected:
    double _voltage; // Рабочее напряжение

public:
    PowerTool(const std::string& name, double power, double voltage)
        : AbstractElectricDevice(name, power), _voltage(voltage) {}

    double GetVoltage() const {
        return _voltage;
    }
};

// Класс для холодильника
class Refrigerator : public HomeAppliance {
private:
    double _capacity; // Объем холодильника

public:
    Refrigerator(const std::string& name, double power, const std::string& brand, double capacity)
        : HomeAppliance(name, power, brand), _capacity(capacity) {}

    double GetCapacity() const {
        return _capacity;
    }
};

// Класс для дрели
class Drill : public PowerTool {
private:
    int _rpm; // Обороты в минуту

public:
    Drill(const std::string& name, double power, double voltage, int rpm)
        : PowerTool(name, power, voltage), _rpm(rpm) {}

    int GetRpm() const {
        return _rpm;
    }
};

// Пример использования
int main() {
    Refrigerator fridge("Samsung Fridge", 150, "Samsung", 300);
    Drill drill("Bosch Drill", 800, 220, 3000);

    fridge.TurnOn();
    drill.TurnOn();

    std::cout << "Fridge power: " << fridge.GetPower() << " W" << std::endl;
    std::cout << "Drill power: " << drill.GetPower() << " W" << std::endl;

    return 0;
}