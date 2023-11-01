

//Example of input and output in C
//always use newline drainer
#include<stdio.h>

void fflush_( void );

void fflush_( void ){//2
      char c;
      int I=1;
      while(  c != '\n' ){//3
            c = getchar( );
            printf( "\nI %d, c %c, d %d", I, c, c );
            I+=1;
      }//3
      
}//2


int main(void ){//2

      char ch;
      char s[10];
      int n;
      float fl;
      
      while( ch != 'q' && ch != 'Q' ){//2
      
            printf("\n\ninput int: " );
            scanf( "%d", &n ); 
             // ex input 1   will newline stream
             //ex: input ab will "ab" and newline stream 
             //ex: input  12ab , 12 =n, ab \n on stream
            
            fflush_( );                              
            printf("\ninput str: " );
            scanf( "%s", s ); //newline in 2 string
            /* ex: input ab  newline on stream
                 ex: i nput   ab   cd   will be cd and newline on stream
            */
            
            fflush_( );
                        
            printf("\ninput float: " );
            scanf( "%f", &fl );  //same as int
            
            fflush_( );
      
            printf( "\n\ndisplay all value\nint %d\nstr %s\n%0.2f\n", n, s, fl);                                                      
            printf("press q to leave: " );
      
            scanf( "%c", &ch ); 
            /* example input blank ch is '\n' and blank on stream
            input a  newline on stream       
            */
            //printf( "\nc %c ", ch );
            
            if( ch != 10 ) {//3
            
                  fflush_( );
            }//3
              
      }//2
      
      return 0;
}//2

