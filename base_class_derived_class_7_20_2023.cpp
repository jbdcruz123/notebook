//testing sa base class at derived class
#include<iostream>

class A{//2

        public:
                void show( ){ //3
                        std::cout << "\nA show \n";
                }//2

                
                void proc_A( ) { //4
                       
                        std::cout << "\nproc_A  \n";
                }//4

}; //2



class B: public A{//2

        public:
                void show( ){ //3
                       
                        std::cout << "\nB show \n";
                }//2

                void proc_B( ) { //4
                       
                        std::cout << "\nproc_B  \n";
                }//4

}; //2

int main( ) {//2

        std::cout << "\n\ntest for none virtual\n";
        A *obj_a;
        B obj_b;


        obj_a = &obj_b;

        (*obj_a).show( );  //tatawagin ang original member show ng class A

        return 0;
}//2

