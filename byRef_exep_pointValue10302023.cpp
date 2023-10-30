
//by ref, pointer variable can be
//aces by param func by ref
#include<iostream>
#include<sstream>

int  get_str( std::string& );

int get_str( std::string &s ){//2

      std::getline( std::cin, s );
      
      std::cin.clear( );
      return std::cin.fail( );      

}//2

int main( void) {//2
      std::string a= "test";
      
      std::string *p;
      int resS= 0;
            
      std::cout << "\nget str ";
      p= &a;
      
      //use pointer value operator
      //para ma acces ng param by ref
      resS = get_str(  *p);

                  
     
      std::cout << "\nresult is  *p " << *p << "\n" ;
      if(  resS == true){//3
            std::cout << "\nerror str " << "\n";      
      }//3
                      
      return 0;
}//2


