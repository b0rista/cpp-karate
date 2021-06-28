#include <iostream>
#include <sstream>
#include <vector>
#include <exception>

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
        if (denominator == 0) {
            throw invalid_argument("Invalid argument");
        }
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
    if (rhs.Numerator() == 0) {
        throw domain_error("Division by zero");
    }
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
    Rational a, b;
    char operation;
    try {
        cin >> a >> operation >> b;
        if (operation == '+') {
            cout << a + b;
        }
        if (operation == '-') {
            cout << a - b;
        }
        if (operation == '*') {
            cout << a * b;
        }
        if (operation == '/') {
            cout << a / b;
        }
    } catch (const exception& ex) {
        cout << ex.what();
    }
    cout << endl;
         
    
    return 0;
}
