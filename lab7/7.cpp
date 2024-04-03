#include <iostream>

using namespace std;

// Класс прямоугольника
class Rectangle {
    // protected поля, чтобы был доступ из наследников
protected:
    int x, y;
    int width, height;

public:
    Rectangle(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}

    // Метод вывода на консоль
    virtual void print() {
        cout << "Rectangle: (" << x << ", " << y << "), width = " << width << ", height = " << height << endl;
    }
};

// Класс квадрата, наследует прямоугольник
class Square : public Rectangle {
public:
    Square(int x, int y, int sideSize) : Rectangle(x, y, sideSize, sideSize) {}

    // Переопределенный метод
    void print() override {
        cout << "Square: (" << x << ", " << y << "), sideSize = " << width << endl;
    }
};

int main() {
    Rectangle rect = Rectangle(10, 20, 100, 50);
    Square square = Square(30, 40, 40);

    // Печатаем прямоугольник
    rect.print();
    // Печатаем квадрат
    square.print();
    // Печатаем квадрат как прямоугольник
    ((Rectangle) square).print();

    return 0;
};