
//virtual topic 7/18/2023

#include<iostream>

class A{

        public:
                int int_B;

                virtual void virtual_f(  ){

                        std::cout << "\ninside  class A virtual_f \n";
                }

                void no_virtual_f(  ){

                        std::cout << "\ninside  class A no_virtual_f \n";
                }
};


class B: public A{

        public:
                int int_B;

                void virtual_f(  ){

                        std::cout << "\ninside  class B virtual_f \n";
                }

                void no_virtual_f(  ){

                        std::cout << "\ninside  class B no_virtual_f \n";
                }

};

int main(  ) {

        A *obj_a;

        B obj_b;


        obj_a = &obj_b;

        obj_a->virtual_f( ); //will print class B
        
        obj_a->no_virtual_f( ); //will print class A

        return 0;
}











