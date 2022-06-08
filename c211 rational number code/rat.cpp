#include "rat.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void Rat::input()
{
    cout << "Input num: ";
    cin >> num;
    cout << "Input denom: ";
    cin >> denom;

    if (denom == 0)
    {
        cout << "Denominator cannot be zero" << endl;
        exit(1);
    }
    else if (denom < 0)
    {
        num = -num;
        denom = -denom;
    }
}

void Rat::output() const
{
    cout << num << "/" << denom << endl;
}

int Rat::gcd(int a, int b)
{
    a = static_cast<int>(abs(a));
    b = static_cast<int>(abs(b));
    int c;
    while (b != 0)
    {
        c = a;
        a = b;
        b = c % b;
    }
    return a;
}

int Rat::lcm(int a, int b)
{
    a = static_cast<int>(abs(a));
    b = static_cast<int>(abs(b));

    return (a * b) / gcd(a, b);
}


const Rat Rat::add(const Rat& r2) const
{
    Rat r;
    int m = lcm(denom, r2.denom);
    r.num = num * m / denom + r2.num * m / r2.denom;
    r.denom = m;
    return r.reduce();
}

const Rat Rat::sub(const Rat& r2) const
{
    Rat r;
    int m = lcm(denom, r2.denom);
    r.num = num * m / denom - r2.num * m / r2.denom;
    r.denom = m;
    return r.reduce();
}

const Rat Rat::mult(const Rat& r2) const
{
    Rat r;
    r.num = num * r2.num;
    r.denom = denom * r2.denom;
    return r.reduce();
}


const Rat Rat::div(const Rat& r2) const
{
    if (r2.num == 0)
    {
        cout << "Cannot divide by zero" << endl;
        exit(1);
    }
    Rat r;
    r.num = num * r2.denom;
    r.denom = denom * r2.num;
    return r.reduce();
}

const Rat Rat::reduce() const
{
    int d = gcd(num, denom);
    Rat rr;
    rr.num = num / d;
    rr.denom = denom / d;
    return rr;
}

// Constructors
Rat::Rat() : num(0), denom(1)
{
    // empty
}

Rat::Rat(int n) : num(n), denom(1)
{
    // empty
}

Rat::Rat(int n, int d) : num(n), denom(d)
{
    if (denom == 0)
    {
        cout << "Denominator cannot be zero" << endl;
        exit(1);
    }
    else if (denom < 0)
    {
        num = -num;
        denom = -denom;
    }
}

// Accessors
int Rat::getNum() const
{
    return num;
}

int Rat::getDenom() const
{
    return denom;
}

// Mutators
void Rat::setNum(int n)
{
    num = n;
}

void Rat::setDenom(int d)
{
    denom = d;

    if (denom == 0)
    {
        cout << "Denominator cannot be zero" << endl;
        exit(1);
    }
    else if (denom < 0)
    {
        num = -num;
        denom = -denom;
    }
}