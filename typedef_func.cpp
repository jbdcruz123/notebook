

#include<iostream>

typedef int Fn(int); // Fn is a type-of function
// that accepts an int and returns an int

// Note that MyFn() is of type 'Fn'
int MyFn(int i) { return 2*i; }

class Class {
public:
    // Note that Static() is of type 'Fn'
    static int Static(int i) { return 3*i; }
}; // Class

int main() {
        Fn *fn;    // fn is a pointer to a type-of Fn
        int out;
        fn = &MyFn;          // Point to one function
        out = fn(3);               // Call it
        std::cout << "\nfir " << out;
        
        fn = &Class::Static; // Point to the other function
        out = fn(4);               // Call it
        std::cout << "\nfir " << out;
        
    
 } // main()

