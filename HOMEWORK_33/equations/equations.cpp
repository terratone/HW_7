#include <iostream>
#include <cmath>

//  Создать абстрактный базовый класс с виртуальной функцией — корни уравнения.
//  Создать производные классы:
//  класс линейных уравнений и класс квадратных уравнений.
//  Определить функцию вычисления корней уравнений.

using namespace std;

// Абстрактный базовый класс Equation
class Equation {
public:
    // Виртуальная функция для вычисления корней уравнения
    virtual void calculateRoots() = 0;
};

// Производный класс для линейных уравнений (ax + b = 0)
class LinearEquation : public Equation {
private:
    double a;
    double b;
public:
    LinearEquation(double a, double b) : a(a), b(b) {}

    // Переопределение функции для вычисления корней линейного уравнения
    void calculateRoots() override {
        if (a == 0) {
            cout << "the equation is not linear" << endl;
        }
        else {
            double root = -b / a;
            cout << "Root of the equation: x = " << root << endl;
        }
    }
};

// Производный класс для квадратных уравнений (ax^2 + bx + c = 0)
class QuadraticEquation : public Equation {
private:
    double a;
    double b;
    double c;
public:
    QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}

    // Переопределение функции для вычисления корней квадратного уравнения
    void calculateRoots() override {
        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Roots to the equation: x1 = " << root1 << ", x2 = " << root2 << endl;
        }
        else if (discriminant == 0) {
            double root = -b / (2 * a);
            cout << "the equation has one root: x = " << root << endl;
        }
        else {
            cout << "the equation doesn't have roots" << endl;
        }
    }
};

int main() {
    // Пример использования классов
    LinearEquation linearEquation(2.0, 8.0);
    QuadraticEquation quadraticEquation(1.0, -3.0, 2.0);

    cout << "Solution to a linear equation:" << endl;
    linearEquation.calculateRoots();

    cout << "\nSolution to a quadratic equation:" << endl;
    quadraticEquation.calculateRoots();

    return 0;
}