// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №6. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//
#include<iostream>
#include <string>
using namespace std;


class Base {
protected:
    int dat;
public:
    Base() :dat(1) {}
    Base(int d) :dat(d) {}
};

class D1 :protected Base {
protected:
    int d1;
public:
    D1() :d1(1) {}
    D1(int d) :d1(d) {}
    D1(int a, int b) :Base(a), d1(b) {}
};
class D2 :protected Base {
protected:
    int d2;
public:
    D2() :d2(1) {}
    D2(int d) :d2(d) {}
    D2(int a, int b) :Base(a), d2(b) {}
};
class D3 : protected D1 {
protected:
    int d3;
public:
    D3() :d3(1) {}
    D3(int d) :d3(d) {}
    D3(int a, int b, int c) : D1(a, b), d3(c) {}
};
class D4 :protected D3 {
protected:
    int d4;
public:
    D4() :d4(1) {}
    D4(int d) :d4(d) {}
    D4(int a, int b, int c, int d) :D3(a, b, c), d4(d) {}
};
class D5 :protected D2, protected D3 {
protected:
    int d5;
public:
    D5() :d5(1) {}
    D5(int d) :d5(d) {}
    D5(int a, int b, int c, int d, int e, int f) :D2(a, b), D3(c, d, e), d5(f) {}
};

class VD1 :virtual protected Base {
protected:
    int d1;
public:
    VD1() :d1(1) {}
    VD1(int d) :d1(d) {}
    VD1(int a, int b) :Base(a), d1(b) {}
};
class VD2 :virtual protected Base {
protected:
    int d2;
public:
    VD2() :d2(1) {}
    VD2(int d) :d2(d) {}
    VD2(int a, int b) :Base(a), d2(b) {}
};
class VD3 :virtual protected VD1 {
protected:
    int d3;
public:
    VD3() :d3(1) {}
    VD3(int d) :d3(d) {}
    VD3(int a, int b, int c) : VD1(a, b), d3(c) {}
};
class VD4 :virtual protected VD3 {
protected:
    int d4;
public:
    VD4() :d4(1) {}
    VD4(int d) :d4(d) {}
    VD4(int a, int b, int c, int d) :VD3(a, b, c), d4(d) {}
};
class VD5 :virtual protected VD2, virtual protected VD3 {
protected:
    int d5;
public:
    VD5() :d5(1) {}
    VD5(int d) :d5(d) {}
    VD5(int a, int b, int c, int d, int e, int f) :VD2(a, b), VD3(c, d, e), d5(f) {}
};

void Ex1() {
    Base b;
    D1 d1;
    D2 d2;
    D3 d3;
    D4 d4;
    D5 d5;

    VD1 vd1;
    VD2 vd2;
    VD3 vd3;
    VD4 vd4;
    VD5 vd5;
    
    cout << "----Test----\n";
    cout << "Size of Base: " << sizeof(b) << endl;
    cout << "Size of D1: " << sizeof(d1) << endl;
    cout << "Size of D2: " << sizeof(d2) << endl;
    cout << "Size of D3: " << sizeof(d3) << endl;
    cout << "Size of D4: " << sizeof(d4) << endl;
    cout << "Size of D5: " << sizeof(d5) << endl;
    cout << "Size of VD1: " << sizeof(vd1) << endl;
    cout << "Size of VD2: " << sizeof(vd2) << endl;
    cout << "Size of VD3: " << sizeof(vd3) << endl;
    cout << "Size of VD4: " << sizeof(vd4) << endl;
    cout << "Size of VD5: " << sizeof(vd5) << endl;

}


class Figure {
public:
    virtual double perimeter() = 0;
};

class Rectangle : public Figure {
private:
    double width, length;
public:
    Rectangle(double w, double l) {
        width = w;
        length = l;
    }
    double perimeter() {
        return 2 * (width + length);
    }
};
class Circle : public Figure {
private:
    double radius;
public:
    Circle(double r) {
        radius = r;
    }
    double perimeter() {
        return 2 * 3.14159 * radius;
    }
};
class RightTriangle : public Figure {
private:
    double side1, side2, hypotenuse;
public:
    RightTriangle(double s1, double s2) {
        side1 = s1;
        side2 = s2;
        hypotenuse = sqrt(s1 * s1 + s2 * s2);
    }
    double perimeter() {
        return side1 + side2 + hypotenuse;
    }
};
class Trapezoid : public Figure {
private:
    double side1, side2, height, base;
public:
    Trapezoid(double s1, double s2, double h, double b) {
        side1 = s1;
        side2 = s2;
        height = h;
        base = b;
    }
    double perimeter() {
        return side1 + side2 + 2 * base;
    }
};

void Ex2() {
    Rectangle r(4, 6);
    Circle c(3);
    RightTriangle t(3, 4);
    Trapezoid p(4, 6, 5, 8);

    // Test
    Figure* arr[4];
    arr[0] = &r;
    arr[1] = &c;
    arr[2] = &t;
    arr[3] = &p;

    for (int i = 0; i < 4; i++) {
        cout << "Perimeter of figure " << i + 1 << ": " << arr[i]->perimeter() << endl;
    }

}


class Person {
protected:
    string name;
public:
    Person(string n) : name(n) {}
    virtual ~Person() {}
    virtual void info() { cout << "Person: " << name << endl; }
    friend ostream& operator<<(ostream& os, const Person& p) {
        os << "Person: " << p.name;
        return os;
    }
    friend istream& operator>>(istream& is, Person& p) {
        is >> p.name;
        return is;
    }
};

class Woman : public Person {
public:
    Woman(string n) : Person(n) {}
    ~Woman() {}
    void info() { cout << "Woman: " << name << endl; }
    friend ostream& operator<<(ostream& os, const Woman& w) {
        os << "Woman: " << w.name;
        return os;
    }
    friend istream& operator>>(istream& is, Woman& w) {
        is >> w.name;
        return is;
    }
};

class Employee {
protected:
    string jobTitle;
public:
    Employee(string j) : jobTitle(j) {}
    virtual ~Employee() {}
    virtual void info() { cout << "Employee: " << jobTitle << endl; }
    friend ostream& operator<<(ostream& os, const Employee& e) {
        os << "Employee: " << e.jobTitle;
        return os;
    }
    friend istream& operator>>(istream& is, Employee& e) {
        is >> e.jobTitle;
        return is;
    }
};

class WomanEmployee : public Woman, public Employee {
public:
    WomanEmployee(string n, string j) :
        Woman(n), Employee(j) {}
    ~WomanEmployee() {}
    void info() { cout << "WomanEmployee: " << name << ", " << jobTitle << endl; }
    friend ostream& operator<<(ostream& os, const WomanEmployee& w) {
        os << "WomanEmployee: " << w.name << ", " << w.jobTitle;
        return os;
    }
    friend istream& operator>>(istream& is, WomanEmployee& w) {
        is >> w.name;
        is >> w.jobTitle;
        return is;
    }
};


void Ex3()
{
    Woman W1("Alice");
    cout << W1 << endl;
    cout << "Change name: ";
    cin >> W1;
    W1.info();

    Employee E1("Engineer");
    cout << E1 << endl;
    cout << "Change occupation: ";
    cin >> E1;
    E1.info();

    WomanEmployee WE1("Anna", "Manager");
    cout << WE1 << endl;
    cout << "Change emploee`s info: ";
    cin >> WE1;
    WE1.info();

}

#include "Lab6Example.h"
int main()
{
    cout << " Lab #6  !\n";
    //  Код виконання завдань
    //  Головне меню завдань
    //  Функції та класи можуть знаходитись в інших файлах проекту
    int a;
    cout << "Choose the exercise:" << endl;
    cin >> a;
    if (a == 1) {
        Ex1();
    }
    if (a == 2) {
        Ex2();
    }
    if (a == 3) {
        Ex3();
    }
    if (a == 4) {
        Example();
    }
    return 0;

}