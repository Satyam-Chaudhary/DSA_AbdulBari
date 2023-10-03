#include <stdio.h>
struct Rectangle
{
    int length;
    int breadth;
    //char x; --> allocated 4 bytes but uses only 1 byte // easy for machine to access easily --> PADDING OF MEMORY(takes nearest biggest memory size)
} rec3; // declared in the struct block only


int main()
{
    struct Rectangle rec1 = {5 , 10}; // declaration and initialization at once
    printf("Area of rectanglr --> %d\n" , rec1.length * rec1.breadth);
    //or
    struct Rectangle rec2; // declaration
    rec2.length = 20; // initialization
    rec2.breadth = 30;
    printf("Area of rec2 --> %d\n" , rec2.length*rec2.breadth);
    //rec3 = {40, 50}; --> can't do this if declared outside the main block
    rec3.length = 2;
    rec3.breadth = 5;
    printf("Area of rec3 --> %d\n" , rec3.length*rec3.breadth);
    struct Rectangle rec4;
    rec4.length = 2;
    rec4.breadth = 4;
    printf("Area of rec4 --> %d\n" , rec4.length*rec4.breadth);

    printf("Size of struc rec1 --> %lu\n" , (unsigned long)sizeof(rec1));

    return 0;
}