#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Number {
private:
    int rawValue;

public:
    Number(int value) { this->rawValue = value; }
    int getRawValue() { return rawValue; }
    void setRawValue(int value) { this->rawValue = value; }
};

class WholeNumber : public Number {
public:
    WholeNumber(int value) : Number(value) {}
    void multiply(WholeNumber otherWhole) { setRawValue(getRawValue() * otherWhole.getRawValue()); }
    string toString() { return to_string(getRawValue()); }
};

class DecimalNumber : public Number {
private:
    int decimalPlaces;

public:
    DecimalNumber(int value, int decimalPlaces) : Number(value) { this->decimalPlaces = decimalPlaces; }
    int getDecimalPlaces() { return decimalPlaces; }
    void setDecimalPlaces(int decimalPlaces) { this->decimalPlaces = decimalPlaces; }
    void multiply(DecimalNumber decimalNumber) {
        setRawValue(getRawValue() * decimalNumber.getRawValue());
        setDecimalPlaces(getDecimalPlaces() + decimalNumber.getDecimalPlaces());
    }
    string toString() {
        int divisor = 1;
        for (int i = 0; i < decimalPlaces; ++i) { divisor *= 10; }
        double result = static_cast<double>(getRawValue()) / divisor;
        cout << fixed << setprecision(decimalPlaces);
        return to_string(result);
    }
};

int main() {
    int w1, w2;
    cout<<"Enter first whole number: "; cin>>w1;
    cout<<"Enter second whole number: "; cin>>w2;

    WholeNumber whole1(w1); WholeNumber whole2(w2);
    whole1.multiply(whole2);

    cout<<"WholeNumber Result (Multiplication): "<<whole1.toString()<<endl;

    int d1_raw, d1_places, d2_raw, d2_places;
    cout<<"\nEnter first decimal number's raw value (e.g. 125 for 1.25): "; cin>>d1_raw;
    cout<<"Enter number of decimal places for first decimal: "; cin>>d1_places;
    cout<<"Enter second decimal number's raw value (e.g. 20 for 0.20): "; cin>>d2_raw;
    cout<<"Enter number of decimal places for second decimal: "; cin>>d2_places;

    DecimalNumber dec1(d1_raw, d1_places); DecimalNumber dec2(d2_raw, d2_places);
    dec1.multiply(dec2);

    cout<<fixed<<setprecision(dec1.getDecimalPlaces());
    cout<<"DecimalNumber Result (Multiplication): "<<static_cast<double>(dec1.getRawValue())/pow(10, dec1.getDecimalPlaces())<<endl;

    return 0;
}
