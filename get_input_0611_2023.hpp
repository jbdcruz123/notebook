




//use this in get_input.hpp an old style c function formater
#include<iostream>
#include<string>
#include<cstring>

void flush_char();
void get_input( int &n, std::string text );
void get_input( double &n, std::string text );
void get_input( std::string &s, int length, std::string text );
void get_input( char* inp_s, int length, std::string text );

void get_input( std::string &s, int length, std::string text ){//2

        //pag > length ay putulin 
        while( true ) {// 4
                std::cin >> s;
                if ( std::cin.fail(  ) ) {//3   
                        //other errors             
                        std::cin.clear(  );                             
                        std::cout << "\nerror: " << text << "\n";
                        continue;
                }//3

                if( s.size(  ) > length ){ //4
                        s = s.substr( 0, length );
                }//4

                break;
        }//4
}//2


void get_input( char* inp_s, int length, std::string text ){//2

        std::string s;
        //pag > length ay putulin 
        while( true ) {// 4
                std::cin >> s;
                if ( std::cin.fail(  ) ) {//3   
                        //other errors             
                        std::cin.clear(  );                             
                        std::cout << "\nerror: " << text << "\n";
                        continue;
                }//3

                if( s.size(  ) > length ){ //4
                        s = s.substr( 0, length );
                }//4

                break;
        }//4

        strcpy( inp_s, s.c_str( ) );
}//2

void get_input( int &n, std::string text ){//2

        while( true ) {// 4

                std::cin >> n;
                if ( std::cin.fail(  ) ) {//3
                
                        std::cin.clear(  );      
                        flush_char(  );
                        std::cout << "\nerror: " << text << "\n";
                        continue;
                }//3

                break;
        }//4
}//2


void get_input( double &n, std::string text ){//2

        while( true ) {// 4

                std::cin >> n;
                if ( std::cin.fail(  ) ) {//3
                
                        std::cin.clear(  );      
                        flush_char(  );
                        std::cout << "\nerror: " << text << "\n";
                        continue;
                }//3

                break;
        }//4
}//2

void flush_char(){//2

        char c = getchar(  );
        while( c!= '\n' and c !=13 ){//3

                c = getchar( );
        }//3

}//2
