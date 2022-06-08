
#ifndef RAT_H
#define RAT_H

class Rat
{
private:
    int num;
    int denom;

public:
    void input();
    void output() const;

    const Rat add(const Rat& r2) const;
    const Rat sub(const Rat& r2) const;
    const Rat mult(const Rat& r2) const;
    const Rat div(const Rat& r2) const;
    const Rat reduce() const;

    // Constructors
    Rat();
    Rat(int n);
    Rat(int n, int d);

    // Accessors
    int getNum() const;
    int getDenom() const;

    // mutators
    void setNum(int n);
    void setDenom(int d);

    // utility functions
    static int lcm(int a, int b);
    static int gcd(int a, int b);
};

#endif