/*it behave somewhat like a pointer that is automatically dereferenced. 
However, unlike pointers, references cannot be null and they must be 
initialized when they are created.*/

#include <iostream>
using namespace std;

int main()
{

    int a = 10;
    int &r = a; // reference to variable a --> different name for a // need to be declared and initialized at same time
    // Reference doesn't consumes memory it occupies the same memory as that of the variable

    cout << a << " " << r << " ";
    int b = 25;

    r = b;
    cout << a << " " << r << " " << endl;

    return 0;
}