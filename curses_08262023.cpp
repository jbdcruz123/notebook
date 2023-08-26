
//compile it on
//g++ curses.cpp -lcurses
#include<curses.h>


int main( void ) {//2

        int X=0, Y=0, L=-1;
        int ROW= 5, COL =20;

        initscr(  );
        for( ; Y < ROW ; Y+=1){//3

                if( L == -1 ) {//4

                        L += 2;
                } else {//4
                        L -= 2;

                }//4

                for( int J=0 ; J < COL ; J+=1){//3

                        X += L;

                        
                        clear(  );
                        napms(100); //delaying printout                       
                        move( Y, X );
                        
                        //printw("\nX %d, L %d", X, L  );    
                        printw("A");
                        refresh(  ); //refresh the window
                         
                }//3

        }//3

        printw( "\n\nexiting..." );
        getch(  ); //get user input
        endwin(  );
}//2
