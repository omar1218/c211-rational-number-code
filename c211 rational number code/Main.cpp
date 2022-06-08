#include "rat.h"
#include <iostream>

using namespace std;

int main()
{
    Rat r1;
    Rat r2;
    Rat sum;
    Rat diff;
    Rat prod;
    Rat quot;

    char ans;

    do
    {
        r1.input();
        r2.input();
        sum = r1.add(r2);
        diff = r1.sub(r2);
        prod = r1.mult(r2);
        quot = r1.div(r2);

        cout << "r1 = ";
        r1.output();
        cout << "r2 = ";
        r2.output();
        cout << "r1 + r2 = ";
        sum.output();
        cout << "r1 - r2 = ";
        diff.output();
        cout << "r1 * r2 = ";
        prod.output();
        cout << "r1 / r2 = ";
        quot.output();

        cout << "Do you want to continue (y/n): ";
        cin >> ans;
    } while (ans == 'y');

    return 0;
}

//rat as struct
/*



#include <iostream>
#include <cmath>
#include <cstdlib>

struct Rat
{
    int num;
    int denom;
};

void input(Rat& r);
void output(Rat r);

Rat add(Rat r1, Rat r2);
Rat sub(Rat r1, Rat r2);
Rat mult(Rat r1, Rat r2);
Rat div(Rat r1, Rat r2);
Rat reduce(Rat r);

int lcm(int a, int b);
int gcd(int a, int b);

int main()
{
    char ch;
    do
    {
        Rat r1;
        Rat r2;
        Rat rsum;
        Rat rdiff;
        Rat rprod;
        Rat rquot;

        input(r1);
        input(r2);

        rsum = add(r1, r2);
        rdiff = sub(r1, r2);
        rprod = mult(r1, r2);
        rquot = div(r1, r2);

        std::cout << "r1 = ";
        output(r1);

        std::cout << "r2 = ";
        output(r2);

        std::cout << "r1 + r2 = ";
        output(rsum);

        std::cout << "r1 - r2 = ";
        output(rdiff);

        std::cout << "r1 * r2 = ";
        output(rprod);

        std::cout << "r1 / r2 = ";
        output(rquot);

        std::cout << "Do you want to continue (y/n): ";
        std::cin >> ch;
    } while (ch == 'y');


    return 0;
}

void input(Rat& r)
{
    std::cout << "num: ";
    std::cin >> r.num;
    std::cout << "denom: ";
    std::cin >> r.denom;

    if (r.denom == 0)
    {
        std::cout << "Denominator cannot be zero" << std::endl;
        std::exit(1);
    }

    else if (r.denom < 0)
    {
        r.denom = -r.denom;
        r.num = -r.num;
    }
}

void output(Rat r)
{
    std::cout << r.num << "/" << r.denom << std::endl;
}

Rat add(Rat r1, Rat r2)
{
    Rat r;
    int ell = lcm(r1.denom, r2.denom);
    r.num = r1.num * ell / r1.denom + r2.num * ell / r2.denom;
    r.denom = ell;

    return reduce(r);
}

Rat sub(Rat r1, Rat r2)
{
    Rat r;
    int ell = lcm(r1.denom, r2.denom);
    r.num = r1.num * ell / r1.denom - r2.num * ell / r2.denom;
    r.denom = ell;

    return reduce(r);
}


Rat mult(Rat r1, Rat r2)
{
    Rat r;
    r.num = r1.num * r2.num;
    r.denom = r1.denom * r2.denom;

    return reduce(r);
}


Rat div(Rat r1, Rat r2)
{
    Rat r;

    if (r2.num == 0)
    {
        std::cout << "Cannot divide by 0 rational number" << std::endl;
        exit(1);
    }

    r.num = r1.num * r2.denom;
    r.denom = r1.denom * r2.num;

    if (r.denom < 0)
    {
        r.denom = -r.denom;
        r.num = -r.num;
    }

    return reduce(r);
}

int gcd(int a, int b)
{
    a = static_cast<int> (std::abs(a));
    b = static_cast<int> (std::abs(b));

    while (b != 0)
    {
        int c = a;
        a = b;
        b = c % b;
    }

    return a;
}

int lcm(int a, int b)
{
    a = static_cast<int> (std::abs(a));
    b = static_cast<int> (std::abs(b));

    return (a * b) / gcd(a, b);
}

Rat reduce(Rat r)
{
    int g = gcd(r.num, r.denom);
    Rat rr;
    rr.num = r.num / g;
    rr.denom = r.denom / g;

    return rr;
}
*/

//rat as an array
/*
#include <iostream>
#include <cstdlib>

using namespace std;

void input(int r[]);
void output(int r[]);
void add(int r[], int r1[], int r2[]);
void sub(int r[], int r1[], int r2[]);
void mult(int r[], int r1[], int r2[]);
void div(int r[], int r1[], int r2[]);
int lcm(int a, int b);  // lcm(12, 15) = 60
int gcd(int a, int b);  // gcd(12, 15) = 3

//
//12 24 36 48 60
//15 30 45 60
//
//12 = 2^2 * 3^1 * 5^0
//15 = 2^0 * 3^1 * 5^1
//
//gcd(12, 15) = 2^0 * 3^1 * 5^0 = 3
//lcm(12, 15) = 2^2 * 3^1 * 5^1 = 60
//
//gcd(12, 15) * lcm(12, 15) = 12 * 15
//gcd(a, b) * lcm(a, b) = a * b
//
//gcd(a,b) if b == 0 then gcd(a,b) = a
//         else gcd(a,b) = gcd(b, a % b)
//
//gcd(12, 15) = gcd(15, 12)
//gcd(15, 12) = gcd(12, 3) = gcd(3, 0) = 3





int main()
{
    int r1[2];
    int r2[2];
    int sum[2];
    int diff[2];
    int prod[2];
    int quot[2];

    char ans;

    do
    {
        input(r1);
        input(r2);
        add(sum, r1, r2);
        sub(diff, r1, r2);
        mult(prod, r1, r2);
        div(quot, r1, r2);

        cout << "r1 = ";
        output(r1);
        cout << "r2 = ";
        output(r2);
        cout << "r1 + r2 = ";
        output(sum);
        cout << "r1 - r2 = ";
        output(diff);
        cout << "r1 * r2 = ";
        output(prod);
        cout << "r1 / r2 = ";
        output(quot);

        cout << "Do you want to continue (y/n): ";
        cin >> ans;
    } while (ans == 'y');

    return 0;
}

void input(int r[])
{
    cout << "Input num: ";
    cin >> r[0];
    cout << "Input denom: ";
    cin >> r[1];

    if (r[1] == 0)
    {
        cout << "Denominator cannot be zero" << endl;
        exit(1);
    }
    else if (r[1] < 0)
    {
        r[0] = -r[0];
        r[1] = -r[1];
    }
}

void output(int r[])
{
    cout << r[0] << "/" << r[1] << endl;
}

int gcd(int a, int b)
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

int lcm(int a, int b)
{
    a = static_cast<int>(abs(a));
    b = static_cast<int>(abs(b));

    return (a * b) / gcd(a, b);
}


void add(int r[], int r1[], int r2[])
{
    int m = lcm(r1[1], r2[1]);
    r[0] = r1[0] * m / r1[1] + r2[0] * m / r2[1];
    r[1] = m;
}


void sub(int r[], int r1[], int r2[])
{
    int m = lcm(r1[1], r2[1]);
    r[0] = r1[0] * m / r1[1] - r2[0] * m / r2[1];
    r[1] = m;
}

void mult(int r[], int r1[], int r2[])
{
    r[0] = r1[0] * r2[0];
    r[1] = r1[1] * r2[1];
}


void div(int r[], int r1[], int r2[])
{
    if (r2[0] == 0)
    {
        cout << "Cannot divide by zero" << endl;
        exit(1);
    }
    r[0] = r1[0] * r2[1];
    r[1] = r1[1] * r2[0];
}
*/

//rat as class
/*
#include <iostream>
#include <cstdlib>

using namespace std;

class Rat
{
   private:
      int num;
      int denom;
   public:
      void input();
      void output();
      Rat add(Rat r2);
      Rat sub(Rat r2);
      Rat mult(Rat r2);
      Rat div(Rat r2);
      Rat reduce();
};

int lcm(int a, int b);
int gcd(int a, int b);

int main()
{
   Rat r1;
   Rat r2;
   Rat sum;
   Rat diff;
   Rat prod;
   Rat quot;

   char ans;

   do
   {
      r1.input();
      r2.input();
      sum = r1.add(r2);
      diff = r1.sub(r2);
      prod = r1.mult(r2);
      quot = r1.div(r2);

      cout << "r1 = ";
      r1.output();
      cout << "r2 = ";
      r2.output();
      cout << "r1 + r2 = ";
      sum.output();
      cout << "r1 - r2 = ";
      diff.output();
      cout << "r1 * r2 = ";
      prod.output();
      cout << "r1 / r2 = ";
      quot.output();

      cout << "Do you want to continue (y/n): ";
      cin >> ans;
   } while (ans == 'y');

   return 0;
}

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

void Rat::output()
{
   cout << num << "/" << denom << endl;
}

int gcd(int a, int b)
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

int lcm(int a, int b)
{
   a = static_cast<int>(abs(a));
   b = static_cast<int>(abs(b));

   return (a * b) / gcd(a,b);
}


Rat Rat::add(Rat r2)
{
   Rat r;
   int m = lcm(denom, r2.denom);
   r.num = num * m / denom + r2.num * m / r2.denom;
   r.denom = m;
   return r.reduce();
}

Rat Rat::sub(Rat r2)
{
   Rat r;
   int m = lcm(denom, r2.denom);
   r.num = num * m / denom - r2.num * m / r2.denom;
   r.denom = m;
   return r.reduce();
}

Rat Rat::mult(Rat r2)
{
   Rat r;
   r.num = num * r2.num;
   r.denom = denom * r2.denom;
   return r.reduce();
}


Rat Rat::div(Rat r2)
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

Rat Rat::reduce()
{
   int d = gcd(num, denom);
   Rat rr;
   rr.num = num / d;
   rr.denom = denom / d;
   return rr;
}
*/