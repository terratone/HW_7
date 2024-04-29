#include <iostream>
#include <fstream>

//  Создайте иерархию классов по работе с файлами.Базовый класс умеет открывать файл и отображать 
//  его содержимое в консоль, первый класс потомка открывает файл и отображает содержимое в виде ascii - кодов символов, 
//  расположенных в файле, второй класс потомка открывает файл и показывает его содержимое в двоичном виде и т.д.
//  Для отображения содержимого файла в базовом классе определена виртуальная функция 
//  void Display(const char* path); path — путь к файлу.Потомки создают свою реализацию виртуальной функции

using namespace std;

// Базовый класс
class FileProcessor {
public:
    // Виртуальная функция отображения содержимого файла
    virtual void Display(const char* path) {
        ifstream file(path);
        if (file.is_open()) {
            string content((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
            cout << "File content: " << content << endl << endl;
            file.close();
        }
        else {
            cout << "Unable to open file" << endl;
        }
    }
};

// Первый класс потомок
class ASCIIFileProcessor : public FileProcessor {
public:
    // Реализация функции Display для отображения содержимого файла в виде ASCII-кодов символов
    void Display(const char* path) override {
        ifstream file(path);
        if (file.is_open()) {
            char ch;
            while (file.get(ch)) {
                cout << static_cast<int>(ch) << " ";
            }
            cout << endl;
            file.close();
        }
        else {
            cout << "Unable to open file" << endl;
        }
    }
};

// Второй класс потомок
class BinaryFileProcessor : public FileProcessor {
public:
    // Реализация функции Display для отображения содержимого файла в двоичном виде
    void Display(const char* path) override {
        ifstream file(path, ios::binary);
        if (file.is_open()) {
            char ch;
            while (file.get(ch)) {
                for (int i = 7; i >= 0; --i) {
                    cout << ((ch >> i) & 1);
                }
                cout << " ";
            }
            cout << endl;
            file.close();
        }
        else {
            cout << "Unable to open file" << endl;
        }
    }
};

int main() {
    const char* filePath = "test.txt";

    // Создаем экземпляры классов
    FileProcessor fileProcessor;
    ASCIIFileProcessor asciiFileProcessor;
    BinaryFileProcessor binaryFileProcessor;

    // Отображаем содержимое файла с помощью каждого класса
    fileProcessor.Display(filePath);
    asciiFileProcessor.Display(filePath);
    binaryFileProcessor.Display(filePath);

    return 0;
}