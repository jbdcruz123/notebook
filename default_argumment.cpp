

//default arguments for func parameter
//using nullptr
#include <iostream>

void myFunction(char *A = nullptr, char B[][100] = nullptr, int C = 0) {
    if (A == nullptr) {
        std::cout << "A: No pointer provided." << std::endl;
    } else {
        std::cout << "A: " << A << std::endl;
    }

    if (B == nullptr) {
        std::cout << "B: No array provided." << std::endl;
    } else {
        std::cout << "B: Array received." << std::endl;
    }

    std::cout << "C: " << C << std::endl;
}

int main() {
    char array[][100] = {"Hello", "World"};
    myFunction("Pointer", array, 5); // Providing all arguments
    myFunction("Pointer"); // Providing only A
    myFunction(nullptr, array); // Providing only B
    myFunction(); // Providing no arguments

    return 0;
}
////////////////
test  has error

#include<iostream>

void test( char *inp = nullptr , char inp2[  ][ 100 ] = nullptr , int way = 0 , int first = 0  , int second = 0 ){ //2            

        if(  way == 1  ){//3
                //1dimen
                for( int i = 0 ;  i < first ; i +=1){//4
                        std::cout << int( inp[ i ] ) << "  ";
                }//4
        } else if(way == 2  ) {//3
                //2 dimen
                 for( int i = 0 ;  i < first ; i +=1){//5
                         for( int j = 0 ;  j < second ; j +=1){//7
                                std::cout << int( inp2[ i ][ j ]  ) << "  ";
                         }//7
                        std::cout << "  ";
                }//5
        } else {//3
                std::cout << "\n1 to 2 way only selection\n" ;
        }//3
}//2

int main( void ) {//2
        char single[ 100 ] ;
        char multiple[ 100 ][ 100 ] ;
        
        std::cout << "\ntest blank\n" ;
        test(  ) ;
        
        std::cout << "\ntest param\n" ;
        test("abc" , 1 , 0 , 0  ) ; // got error here
          //test( "abc" , nullptr , 1 , 0 , 0 ) ;
        return 0 ;
}//2


output
~/cpp $ g++ -o aa aa.cpp
aa.cpp:34:9: error: no matching function for call to 'test'
        test("abc" , 1 , 0 , 0  ) ;
        ^~~~
aa.cpp:6:6: note: candidate function not viable: no known conversion from 'int' to 'char (*)[100]' for 2nd argument
void test( char *inp = nullptr , char inp2[  ][ 100 ] = nullptr , int way = 0 , int first = 0  , int second = 0 ){ //2        
     ^
1 error generated.






