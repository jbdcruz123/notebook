




#include<iostream>

int get_item ( int& );
int get_item ( char& );
void flush_( void ) ;
int test_cin( void );
int get_item( double &a );
int get_item( char *&a );


int test_cin( void ){//2

      int ret = std::cin.fail( ) ; 
            
      if( ret == true) {//3
      
            std::cin.clear(  );
            std::cin.ignore( 1000, '\n');
      
            return ret;                         
      }//3
      
      flush_( );
      return ret;      
}//2

int get_item( char *&a ){//2

      std::cin >> a;

      return test_cin( );
}//2

int get_item( double &a ){//2

      std::cin >> a;

      return test_cin( );
}//2

int get_item( int &a ){//2

      std::cin >> a;

      return test_cin( );
}//2

int get_item( char &a ){//2

      std::cin >> a;
      
      return test_cin( ); 
}//2

void flush_( void ) {//2
      char ch = 0;
      
      while( ch != '\n' ) {//3
            ch = getchar( );
      }//3
}//2

int main( void) {//2
      
      double *d;
      int n=-1, res= 0, resCh = 0,  *p, 
         resDouble=0, resSc =0;            
      p = &n;
      
      char *ch = new char;
      d = new double;      
      *d = 0;

      char *sc = new char[ 10 ];
      strcpy( sc, "test_str" );            
                        
      while( *ch != 'q' ){//4
                  
            std::cout << "\nget char ";
            resCh = get_item(  *ch);

            if(  resCh == true ){//3

                  std::cout << "\nerror ch " << "\n";                   
            }//3

            std::cout << "\nget name ";
            resSc = get_item(  sc);

            std::cout << "\nthe name is " << sc << "\n";                  
            
            if(  resSc == true ){//3

                  std::cout << "\nerror name " << "\n";                   
            }//3
            
            std::cout << "\nget int ";
            res = get_item(  *p );
     
            std::cout << "\naresult is  *p " << *p << "\n";                  
            
            if(  res== true ){//3
                  std::cout << "\nerror int " << "\n"; 
            }//3
      
            std::cout << "\nget double ";
            resDouble = get_item(  *d );
     
            std::cout << "\naresult is  *p " << *d << "\n";                  
            
            if(  resDouble== true ){//3
                  std::cout << "\nerror double " << "\n"; 
            }//3
     
      }//4 
      return 0;
}//2










