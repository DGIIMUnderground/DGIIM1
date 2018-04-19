#include <iostream>
#include "functions.h"
#include "mates.h"

using namespace std;

int main(){
    print_hello();
    cout << endl;
    cout << "The factorial of 5 is " << factorial(5) << endl;
    print_sin(90.0);
    print_cos(90.0);
    print_tan(90.0);

    return 0;
}
