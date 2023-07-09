
#include<iostream>

class b_class;

class a_class{

        int num;
        public:
                a_class( ):num(1) { }
            
                friend b_class friend_( a_class A, b_class B );
};


class b_class{

        int num;    

        public:
                   
                void set(int n ){
                        num = n;
                }             

                friend b_class friend_( a_class A, b_class B );
               
                int get( ){
                        return num;
                }        
};

b_class friend_( a_class A, b_class B ) {

        b_class C;                     

        C.num = A.num + B.num + 10;
        return C;
}      

       

int main( void ) {//2

        a_class a_obj;
        b_class b_obj;

        b_class c_obj;

        b_obj.set(20 );
        c_obj = friend_(a_obj, b_obj);
        
        std::cout << c_obj.get( );

        std::cout << "\n\nexit... \n";
        return 0;
}//2
