
//vector class constructor destructor
#include<iostream>
#include<vector>

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

void disp( std::vector<MYCLASS> myclass, int n){//2

        for( int i= 0;  i< n ; i+=1 ){//3
                              
                std::cout << "\nindex " << i 
                  << ", num " << myclass[ i ].num
                  << ", s " << myclass[ i ].s ;   
        }//3
        
}//2
int main( void){//2

        int n = 3;
        std::vector<MYCLASS> myclass( 3, MYCLASS( 1, "20" )  );         
        
        disp( myclass, n);
        n+=1;      
        myclass.push_back( MYCLASS(2, "dag dag" ) );
        
        disp( myclass, n);
          
        return 0;
}//2
