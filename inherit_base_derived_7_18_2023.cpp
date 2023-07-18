

//example of base class and derived class
#include<iostream>

class A{  //class A is base class its been inherited by class B

        public:
                void func_A(  ){
                        std::cout << "\ninside func_A\n";
                }
              
                void polimorpsm(  ){
                        std::cout << "\ninside polimorpsm_A\n";
                } 
};


class B: public A{  //class B is called derived class, it inherits class A

        public:
               void polimorpsm(  ){
                        std::cout << "\ninside polimorpsm_B\n";
                }

                
};


int main(  ) {//2

        B obj_b;
        A obj_a;
       
        obj_b.polimorpsm(  );  //ang original func ng class B ang mananaig
        obj_b.func_A(  );    //may acess kahit saan sa func_A

        return 0;

}//2



