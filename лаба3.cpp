#include <iostream>
#include <string>
using namespace std;

// Базовый класс Company
class Company {
protected:
    string name;  // Название компании
public:
    Company() {};  // Дефолтный конструктор
    Company(string n) : name(n) {};  // Недефолтный конструктор с инициализацией поля name

    string getName() { return name; }  // Функция для получения названия компании

    // Функция, которая связывает классы Company и Employee
    virtual string getEmployees(string n) = 0;
};

// Класс Employee, наследующийся от Company
class Employee : public Company {
private:
    string employeeName;  // Имя сотрудника
    bool isMarried;  // Статус женат/замужем
public:
    // Дефолтный конструктор
    Employee() {
        name = "N/A";
        employeeName = "N/A";
        isMarried = false;
    }

    // Недефолтный конструктор с инициализацией полей
    Employee(string cName, string eName, bool married) {
        name = cName;
        employeeName = eName;
        isMarried = married;
    }

    // Функция для получения имени сотрудника
    string getEmployeeName() { return employeeName; }

    // Функция для получения статуса женат/замужем
    bool getMaritalStatus() { return isMarried; }

    // Функция, которая связывает классы Employee и Vehicle
    virtual string getVehicle(string rNumber) = 0;
};

// Базовый класс Vehicle
class Vehicle {
protected:
    string registrationNumber;  // Регистрационный номер транспортного средства
public:
    Vehicle() {};  // Дефолтный конструктор
    Vehicle(string r) : registrationNumber(r) {};  // Недефолтный конструктор с инициализацией поля registrationNumber

    string getRegistrationNumber() { return registrationNumber; }  // Функция для получения регистрационного номера

    // Функция, которая связывает классы Vehicle и Track
    virtual int getMass(int m) = 0;
};

// Класс Track, наследующийся от Vehicle
class Track : public Vehicle {
private:
    int mass;  // Масса грузовика
public:
    // Дефолтный конструктор
    Track() {
        registrationNumber = "N/A";
        mass = 0;
    }

    // Недефолтный конструктор с инициализацией полей
    Track(string r, int m) {
        registrationNumber = r;
        mass = m;
    }

    // Функция для получения массы грузовика
    int getMass() { return mass; }

    // Функция, которая связывает классы Track и Car
    virtual string getTransmission(string t) = 0;
};

// Класс Car, наследующийся от Vehicle
class Car : public Vehicle {
private:
    string transmission;  // Коробка передач автомобиля
public:
    // Дефолтный конструктор
    Car() {
        registrationNumber = "N/A";
        transmission = "N/A";
    }

    // Недефолтный конструктор с инициализацией полей
    Car(string r, string t) {
        registrationNumber = r;
        transmission = t;
    }

    // Функция для получения типа коробки передач
    string getTransmission() { return transmission; }

    // Функция, которая связывает классы Car и Employee
    virtual string getEmployee(string eName) = 0;
};

// Наследник класса Company - FlatManagementCompany
class FlatManagementCompany : public Company {
public:
    FlatManagementCompany() { name = "Flat Management Company"; }

    // Реализация функции, которая связывает классы Company и Employee
    virtual string getEmployees(string n) {
        return "Список сотрудников " + name + ": " + n;
    }
};

// Наследник класса Vehicle - Bus
class Bus : public Vehicle {
public:
    Bus(string r) {
        registrationNumber = r;
    }

    // Реализация функции, которая связывает классы Vehicle и Track
    virtual int getMass(int m) {
        return m;
    }
};

// Наследник класса Track - DumpTruck
class DumpTruck : public Track {
public:
    DumpTruck(string r, int m) {
        registrationNumber = r;
        mass = m;
    }

    // Реализация функции, которая связывает классы Track и Car
    virtual string getTransmission(string t) {
        return "Тип трансмиссии грузовика с регистрационным номером " + registrationNumber + ": " + t;
    }
};

// Наследник класса Car - SportsCar
class SportsCar : public Car {
public:
    SportsCar(string r, string t) {
        registrationNumber = r;
        transmission = t;
    }

    // Реализация функции, которая связывает классы Car и Employee
    virtual string getEmployee(string eName) {
        return eName + " 
ездит на легковом автомобиле с регистрационным номером" + registrationNumber;
    }
};

// Создание объектов классов и использование функций-членов для демонстрации работы программы
int main() {
    FlatManagementCompany company;
    Employee employee("Flat Management Company", "Иван Петров", true);
    Bus bus("123ABC");
    DumpTruck dumpTruck("456DEF", 5000);
    SportsCar sportsCar("789GHI", "Automatic");

    cout << "Company name: " << company.getName() << endl;
    cout << "Employees: " << company.getEmployees(employee.getEmployeeName()) << endl;
    cout << "Vehicle registration number: " << bus.getRegistrationNumber() << endl;
    cout << "Vehicle mass: " << bus.getMass(2000) << " kg" << endl;
    cout << "Vehicle registration number: " << dumpTruck.getRegistrationNumber() << endl;
    cout << "Vehicle mass: " << dumpTruck.getMass() << " kg" << endl;
    cout << "Transmission type: " << dumpTruck.getTransmission("Manual") << endl;
    cout << "Vehicle registration number: " << sportsCar.getRegistrationNumber() << endl;
    cout << "Transmission type: " << sportsCar.getTransmission() << endl;
    cout << "Employee: " << sportsCar.getEmployee(employee.getEmployeeName()) << endl;

    return 0;
}

