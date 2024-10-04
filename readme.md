#include <iostream>
#include <string>
#include <cstdlib>    // for atof()

using namespace std;


void Add()
{
    cout << "Please enter two numbers you wish "
         << "to add, separated by a white space:"
         << endl;

    string num1, num2;

    cin >> num1;
    if( num1.find_first_not_of("1234567890.-") != string::npos )
    {
        cout << "invalid number: " << num1 << endl;
        return;
    }

    cin >> num2;
    if( num2.find_first_not_of("1234567890.-") != string::npos )
    {
        cout << "invalid number: " << num2 << endl;
        return;
    }

    float x = 0, y = 0, z = 0;
    x = atof( num1.c_str() );
    y = atof( num2.c_str() );
    z = x+y;

    cout << x << " + " << y << " = " << z << "." << endl;
}

int main(void)
{
    Add();
    return 0;
}