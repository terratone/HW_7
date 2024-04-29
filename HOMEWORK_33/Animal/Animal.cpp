#include <iostream>
#include <string>

//  Создать базовый класс «Домашнее животное» и производные классы «Собака», «Кошка», «Попугай».С помощью
//  конструктора установить имя каждого животного и его
//  характеристики.

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

class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}

    void doAction() override {
        cout << "Dog: " << name << " barks" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}

    void doAction() override {
        cout << "Cat: " << name << " meows" << endl;
    }
};

class Parrot : public Animal {
public:
    Parrot(string n) : Animal(n) {}

    void doAction() override {
        cout << "Parrot: " << name << " talks" << endl;
    }
};

int main() {
    Dog dog("Jack");
    Cat cat("Chloe");
    Parrot parrot("Angel");

    dog.doAction();
    cat.doAction();
    parrot.doAction();

    return 0;
}