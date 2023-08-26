//see my other lecture for compiling process
#include<curses.h>

int main(void) {
        initscr(  );

        char A[  ] = "\n\nstarting to print\nstring:\ngetchar: ";
        char ch;   
        int x= 0, y= 0;     
        printw( " %s", A );  //output from user its like printf in c
        ch = getch(  );
        
        printw("\ni presss : %c", ch );

        refresh(  );

        printw("\nscan string: ");   
        scanw( "%s", A );//input from  user its like scanf in c
        
        printw("\noutput string: %s", A);

        printw( "\ninput x" );
        scanw( "%d", &x);
        
        printw( "\ninput y" );
        scanw( "%d", &y);
        
        clear( ); //clear the screen

        move(y,x); //move y,x its like gotoxy

        refresh(  );
        printw( "%s", A );

        printw("\n\nexiting...");
        getch(  );
        endwin(  );
        return 0;
}
