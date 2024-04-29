#include <iostream>
#include <string>

//  Добавьте механизм виртуального наследования в задание 1

using namespace std;

// Базовый класс "Домашнее животное"
class Animal {
protected:
    string name;

public:
    // Конструктор класса "Домашнее животное" для установки имени
    Animal(string n) : name(n) {}
    // Виртуальная функция для действия каждого животного
    virtual void doAction() = 0;
};

// Производный класс "Собака" от "Домашнее животное" с виртуальным наследованием
class Dog : public virtual Animal {
public:
    // Конструктор класса "Собака" для установки имени и действия
    Dog(string n) : Animal(n) {}

    // Реализация действия для собаки
    void doAction() override {
        cout << "Dog:\t\t" << name << " barks" << endl;
    }
};

// Производный класс "Кошка" от "Домашнее животное" с виртуальным наследованием
class Cat : public virtual Animal {
public:
    // Конструктор класса "Кошка" для установки имени и действия
    Cat(string n) : Animal(n) {}

    // Реализация действия для кошки
    void doAction() override {
        cout << "Cat:\t\t" << name << " meows" << endl;
    }
};

// Производный класс "Попугай" от "Домашнее животное" с виртуальным наследованием
class Parrot : public virtual Animal {
public:
    // Конструктор класса "Попугай" для установки имени и действия
    Parrot(string n) : Animal(n) {}

    // Реализация действия для попугая
    void doAction() override {
        cout << "Parrot:\t\t" << name << " flies" << endl;
    }
};

// Производный класс "Летающий попугай" от "Попугай" и "Птица"
class TalkingParrot : public Parrot {
public:
    // Конструктор класса "Летающий попугай" для установки имени и действия
    TalkingParrot(string n) : Animal(n), Parrot(n) {}

    // Реализация действия для летающего попугая
    void doAction() override {
        cout << "Talking parrot:\t" << name << " flies & talks" << endl;
    }
};

int main() {
    Dog dog("Jack");
    Cat cat("Chloe");
    Parrot parrot("Angel");
    TalkingParrot tparrot("Paulie");

    dog.doAction();
    cat.doAction();
    parrot.doAction();
    tparrot.doAction();

    return 0;
}