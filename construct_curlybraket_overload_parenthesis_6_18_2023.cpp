


//calling constructor, invoke the operator() overload
#include<iostream>

class class_class{

        int num;

        public:
                //:use colon to intialize the private members
                class_class( ):num(0){

                        std::cout << "\n\nempty constructor";
                }

                class_class(int a, int bee ){
                        (*(this)).num = a;
                        std::cout << "\n\nloaded constructor";
                }
                class_class operator()(){
                        std::cout << "\n\ninside operator( )";
                        return *this;
                }
                //create an operator return for class_class
                operator int(){
                        
                        return (*this).num;
                }

                int get_(){
                        return num;
                }

};

int input_class( class_class a ){

        std::cout << "\n\ninput_class ";
        
        return a;
}

int main(  ){//2

        //                          {} class the contructor,  () invokes the operator() overloading
        int n = input_class(  class_class{1, 2}()  );
        std::cout << n << "\n\n";

        //calling with parameter constructor, call operator() overload
        std::cout <<  class_class{100, 2}()<< "\n\n";

        //                 {}calling the empty constructor, () invoking the operator() overload
        std::cout <<  class_class{}() << "\n\n";
        
        //kaylangan mag declare ng object name para macall ung get_()
        //class_class.get_(); error: cannot call member function ‘int class_class::get_()’ without object

        return 0;
}//2
