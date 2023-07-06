





#include<iostream>


class b_class{
        public:
                b_class( ): str_("start"), num(1) {  } 
                int num;
                std::string str_;
                
};

template<typename T = b_class>                
class a_class{

        public:
                
                T obj_class[10];

                template<typename T_return = b_class>
                T_return& operator[](int I){

                        
                        return obj_class[I];
                }
};

int main( void ) {//2

        a_class<b_class> a_obj;
        b_class b_obj;

        b_obj.str_ = "test101";
        b_obj.num = 10;

        a_obj[1] = b_obj;

        std::cout << ( a_obj[1] ).str_;

        std::cout << "\n\nexit... \n";
        return 0;
}//2


/*output is
er/test$ ./a.out
test101

exit... 
*/


