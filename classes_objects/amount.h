#include <string>
#include <iostream>
using namespace std;
class DollarAmount

{

public:
    DollarAmount(float stake) : balance(stake){};
    void add(DollarAmount x){

    };
    void subtract(DollarAmount y){};
    void add_interest(){};
    string toString() { return ""; };

private:
    float balance;
};