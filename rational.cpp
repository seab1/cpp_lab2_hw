#include "rational.h"

Rational::Rational(int numerator, int denominator) { this->initialize(numerator, denominator); }
Rational::Rational(const Rational& copy) { this->initialize(copy.numerator(), copy.denominator()); }

Rational& Rational::operator=(const Rational& other)
{
    if (&other != this)
    {
        this -> numer = other.numerator();
        this -> denom = other.denominator();
    }

    return *this;
}

Rational& Rational::operator=(int i)
{
    this -> numer = i;
    this -> denom = 1;
    return *this;
}

int Rational::NWD(int a, int b)
{
    if(b != 0) return NWD(b, a % b);
    return a;
}

Rational Rational::normalize(const Rational& other)
{
    Rational rational = Rational((int)other.numerator()/other.gcdND, (int)other.denominator()/other.gcdND);
    return rational;
}

Rational Rational::normalized(int numerator, int denominator)
{
    return Rational::normalize(Rational(numerator, denominator));
}

Rational Rational::operator+(const Rational& other) const
{
    return Rational((this->numerator() * other.denominator()) + (other.numerator() * this->denominator()), this->denominator() * other.denominator());
}

Rational Rational::operator-(const Rational& other) const
{
    return Rational((this->numerator() * other.denominator()) - (other.numerator() * this->denominator()), this->denominator() * other.denominator());
}

Rational Rational::operator*(const Rational& other) const
{
    return Rational(this->numerator() * other.numerator(), this->denominator() * other.denominator());
}

Rational Rational::operator/(const Rational& other) const
{
    return Rational(this->numerator() * other.denominator(), this->denominator() * other.numerator());
}

Rational Rational::operator+() const { return *this; }
Rational Rational::operator-() const { return Rational(-this->numerator(), this->denominator()); }

bool Rational::operator==(const Rational& other) const
{
    Rational normalized_this = normalize(*this);
    Rational normalized_other = normalize(other);

    if (normalized_this.numerator() == normalized_other.numerator() && normalized_this.denominator() == normalized_other.denominator()) return true;
    else return false;
}

bool Rational::operator>=(const Rational& other) const
{
    Rational sub = *this - other;

    if (sub.numerator()*sub.denominator() >= 0 ) return true;
    else return false;
}

bool Rational::operator<=(const Rational& other) const
{
    Rational sub = *this - other;

    if (sub.numerator() * sub.denominator() <= 0) return true;
    else return false;
}

bool Rational::operator>(const Rational& other) const
{
    Rational sub = *this - other;

    if (sub.numerator()*sub.denominator() > 0) return true;
    else return false;
}

bool Rational::operator<(const Rational& other) const
{
    Rational sub = *this - other;

    if (sub.numerator()*sub.denominator() < 0) return true;
    else return false;
}

void Rational::initialize(int numerator, int denominator)
{
    if (denominator != 0)
    {
        this->gcdND = Rational::NWD(numerator, denominator);
        this->numer = numerator;
        this->denom = denominator;
    }
    else cout << "Denominator cannot be 0!" << endl;;
}

std::ostream& operator<<(std::ostream& os, const Rational& rational)
{
    Rational normalized = Rational::normalize(rational);
    if ((normalized.numerator() * normalized.denominator()) >= 0) os << abs(normalized.numerator()) << "/" << abs(normalized.denominator());
    else os << "(-" << abs(normalized.numerator()) << "/" << abs(normalized.denominator()) << ")";

    return os;
}

std::istream& operator>>(std::istream& is, Rational& rational)
{
   cout << "numerator = ";
   is >> rational.numer;

   cout << "denominator = ";
   is >> rational.denom;

   return is;
}

Rational operator+(const Rational& r, int i) { return Rational(i * r.denominator() + r.numerator(), r.denominator()); }
Rational operator+(int i, const Rational& r) { return operator+(r, i); }

Rational operator-(const Rational& r, int i) { return Rational(r.numerator() - i * r.denominator(), r.denominator()); }
Rational operator-(int i, const Rational& r) { return Rational(i * r.denominator() - r.numerator(), r.denominator()); }

Rational operator*(const Rational& r, int i) { return Rational(r.numerator() * i, r.denominator()); }
Rational operator*(int i, const Rational& r) { return operator*(r, i); }

Rational operator/(const Rational& r, int i) { return Rational(r.numerator(), r.denominator() * i); }
Rational operator/(int i, const Rational& r) { return Rational(i * r.denominator(), r.numerator()); }
