//nakuha ko sa chat gpt
//pero kinompile ko sa -lcurses na dapat ay -lncurses
#include <iostream>
#include <curses.h>  //dating ncurses.h

int main() {
    // Initialize NCurses
    initscr();

    // Create a main window
    WINDOW *mainwin = newwin(LINES, COLS, 0, 0);

    // Check if window creation failed
    if (mainwin == nullptr) {
        endwin(); // End NCurses mode
        std::cerr << "Error creating window." << std::endl;
        return 1;
    }

    // Enable keypad input for the main window
    keypad(mainwin, TRUE);

    // Print a border around the main window
    box(mainwin, 0, 0);

    // Refresh the main window to display the border
    wrefresh(mainwin);

    // Add content to the main window
    mvwprintw(mainwin, 1, 1, "This is a window example.");
    mvwprintw(mainwin, 2, 1, "Press any key to exit.");

    // Refresh again to display the added content
    wrefresh(mainwin);

    // Wait for user input before exiting
    wgetch(mainwin);

    // Clean up and end NCurses mode
    delwin(mainwin);
    endwin();

    return 0;
}
/*
output ay display ng isang borderline at 
print ung
"This is a window example."
"Press any key to exit."

/*
