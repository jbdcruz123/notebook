#include<iostream>

void flush_( void ){//2
      char ch; 
      while( ch != '\n' and ch != 13 ){//3
            ch =getchar( );
            std::cout << "\ndebug L11 ch " << ch
               << ", ch " << (int) ch << '\n';
      }//3
      
}//2

int main(void) {//2

      int num;
      double double_;
      char  ch;
      std::string s;

      while(  ch != 'Q' and  ch != 'q'){       
            std::cout << "\ninput s:  ";
            std::cin >> s;
            flush_( );
            std::cout << "\nresult s " << s;           

            std::cout << "\ninput ch :  ";
            std::cin >> ch;
            flush_( );      
            std::cout << "\nresult ch " << ch;
            
            //if non numbers inputed in num
            //all non numbers will be on stream output
            //and can be discharge thru getchar( )
            //lahat ng non number pati last \n newline 
            //ay madischarge sa getchar
            //pero dala na nito ang error
            //kaya alang stream input na mainput
            //sa susunod na cin >> var           
            //ANOTHER test
            //pag input ng 12ab sa num
            //papasok ang 12 sa num at ung ab ay mastock 
            //sa stream output last char ang \n newline
            //ang next input ay babaktaw
            //note masmagandang sundin na alang error
            //input sa numbers, 
            std::cout << "\ninput num:  ";
            std::cin >> num;
            flush_( );
            std::cout << "\nresult num " << num;
            
            std::cout << "\ninput double_" ;
            std::cin >> double_;
            std::cout << "\nresult double_ " << double_;           
            flush_( );            
            
            std::cout << "\ninput q to leave :  ";
            std::cin >> ch;
            flush_( );      
            std::cout << "\nresult input leave ch " << ch;

       }//3

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
      return 0;
}//2
