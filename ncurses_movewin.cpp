
//curse.h reference desame with ncurses
//https://pubs.opengroup.org/onlinepubs/7908799/xcurses/curses.h.html
#include <ncurses.h>

int main() {
    // Initialize ncurses
    initscr();
    curs_set(0); //hide ang cursor pag 0, show sa 1

    // Create a window
    WINDOW *myWindow = newwin(10, 30, 5, 10); // Rows, Columns, Y, X
    
    // Draw something in the window
    box(myWindow, 0, 0);

    mvwprintw( myWindow, 2, 1, (char*) "lipat" ) ;
    clear( );
    refresh( );
        
    wgetch(myWindow);
    
    //wclear( myWindow ); //mabubura ung box
    //wrefresh(myWindow); //mawawala ung box, kaya kaylangan i draw ulit ang box    
    //box(myWindow, 0, 0);


    // Move the window to a new position
    mvwin(myWindow, 8, 20); // New Y, New X
    
    clear( );   //nabubura ang screen hindi kasama ung box
    refresh( );

    // Redraw the window after moving
    //wrefresh(myWindow);
    
    // Wait for user input and clean up
    wgetch(myWindow);
    delwin(myWindow);
    endwin();
    
    return 0;
}
