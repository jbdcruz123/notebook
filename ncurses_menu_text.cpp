


//nakita ko lang sa youtube tuiorial
//menu selection

#include<ncurses.h>
#include<string>

int main( int argc, char **argv ){ //2

        initscr(  );
        noecho( );
        cbreak( );
        
        int yMax, xMax;
        getmaxyx( stdscr, yMax, xMax);
        //original code use
        //WINDOW *menuwin = newwin( 6, yMax-12, xMax-5 , 2 );

        WINDOW *menuwin = newwin( 6, 20, 1 , 1 );
        box(menuwin, 0, 0);
        refresh(  );
        wrefresh(menuwin);

        keypad( menuwin, true);

        std::string choices[3] = {"walk", "Jog", "Run"};

        int choice;
        int highlight = 0;

        while(1) {

                wrefresh(menuwin);
                for( int i =0; i < 3 ; i++) {
                        if( i == highlight ) {
                                wattron( menuwin, A_REVERSE);
                        }            
                        mvwprintw( menuwin, i+1, 1, choices[ i].c_str(  ) ) ;
                        wattroff(menuwin, A_REVERSE);
    
                }
                choice = wgetch( menuwin);

                switch( choice){
                case KEY_UP:	
                        highlight--;
                        if( highlight == -1 ){
                                highlight = 0;
                        }
                        break;
                case KEY_DOWN:
                        highlight++;
                        if( highlight == 3 ){
                                highlight = 2;
                        }
                        break;
                default: 
                        break;

                }

                if( choice == 10){
                        break;
                }
           
        }
  
        std::string sub_s = "you select: " + choices[ highlight ] ;
        //wattron( menuwin, A_REVERSE );

        mvwprintw( menuwin, 4, 1, sub_s.c_str( ) ); 
        //wattroff( menuwin, A_REVERSE );

        wgetch(menuwin );//kung gagamit ako ng getch mawawalang bisa ung sa windows
                //separate kasi ung wgetch sa getch
        endwin(  );
        return 0;
}//2











































