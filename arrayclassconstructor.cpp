


//class on double pointer to 
//create array with constructor
#include<iostream>

class MYCLASS{//2
        
        public:
                int num;
                std::string s;
                MYCLASS( int a, std::string b){//3            
                        num= a;
                        s = b; 
                }//3
        
                ~MYCLASS(void ) {//4
                        std::cout << "\n~MYCLASS ";        
                }//4
}; //2

int main( void){//2

        MYCLASS **myclass;
        myclass = new MYCLASS *[ 3];
        for( int i= 0, x = 1 ;  i< 3 ; i+=1, x+=1 ){//3
                  
                myclass[ i ] = new MYCLASS( x, "" + std::to_string(  x) );            
                std::cout << "\nindex " << i 
                  << ", num " << myclass[ i ]->num
                  << ", s " << myclass[ i ]->s ;   
        }//3
        return 0;
}//2



