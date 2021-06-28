#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    // Everything divides 0
    if (a == 0) return b;
    if (b == 0) return a;
    if (a == b) return a;
  
    if (a > b) return gcd(a - b, b);
    
    return gcd(a, b - a);
}

class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
        numer = 0;
        denom = 1;
    }

    Rational(int numerator, int denominator) {
        // Реализуйте конструктор
        int divider = gcd(numerator, denominator);
        numer = numerator / divider;
        denom = denominator / divider;
        
        if (numer * denom < 0) {
            numer = -abs(numer);
            denom = abs(denom);
        }
        else {
            numer = abs(numer);
            denom = abs(denom);
        }
    }

    int Numerator() const {
        // Реализуйте этот метод
        return numer;
    }

    int Denominator() const {
        // Реализуйте этот метод
        return denom;
    }
    
private:
    int numer;
    int denom;
};

bool operator==(const Rational& lhs, const Rational& rhs) {
    if (lhs.Denominator() != rhs.Denominator() || lhs.Numerator() != rhs.Numerator()) {
        return false;
    }
    return true;
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    int commonDenom = lhs.Denominator() * rhs.Denominator();
    int numSum = lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator();
    
    return Rational(numSum, commonDenom);
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    int commonDenom = lhs.Denominator() * rhs.Denominator();
    int numDiff = lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator();
    
    return Rational(numDiff, commonDenom);
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    Rational invertedRhs = Rational(rhs.Denominator(), rhs.Numerator());
    return lhs * invertedRhs;
}

ostream& operator<<(ostream& output, const Rational& r) {
    output << r.Numerator() << '/' << r.Denominator();
    return output;
}


istream& operator>>(istream& input, Rational& r) {
    
    
    int numer=0, denom=1;
    char slash;
    
    input >> numer >> ws >> slash >> ws >> denom;
    if (input && slash == '/') {
        r = Rational(numer, denom);
    }
    
    return input;
    
}


bool operator<(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator();
}



int main() {
    {
            ostringstream output;
            output << Rational(-6, 8);
            if (output.str() != "-3/4") {
                cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
                return 1;
            }
        }

        {
            istringstream input("5/7");
            Rational r;
            input >> r;
            bool equal = r == Rational(5, 7);
            if (!equal) {
                cout << "5/7 is incorrectly read as " << r << endl;
                return 2;
            }
        }

        {
            istringstream input("");
            Rational r;
            bool correct = !(input >> r);
            if (!correct) {
                cout << "Read from empty stream works incorrectly" << endl;
                return 3;
            }
        }

        {
            istringstream input("5/7 10/8");
            Rational r1, r2;
            input >> r1 >> r2;
            bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
            if (!correct) {
                cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
                return 4;
            }

            input >> r1;
            input >> r2;
            correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
            if (!correct) {
                cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
                return 5;
            }
        }

        {
            istringstream input1("1*2"), input2("1/"), input3("/4");
            Rational r1, r2, r3;
            input1 >> r1;
            input2 >> r2;
            input3 >> r3;
            bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
            if (!correct) {
                cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                     << r1 << " " << r2 << " " << r3 << endl;

                return 6;
            }
        }

    cout << "OK" << endl;
    return 0;
}
