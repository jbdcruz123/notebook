

#include<chrono>
#include<iostream>
#include<curses.h>
#include<thread>
#include<fstream>

int exit_ = 0;
double bullet_limit, enemy_limit, print_limit
, bullet_tick, enemy_tick, print_tick;

std::ofstream write_text;

void t_clock(void){//2
        
        //using sec = std::chrono::duration<double>;
        // for milliseconds, use using ms = std::chrono::duration<double, std::milli>;            
        using clock = std::chrono::system_clock;
        
        //bullet, player
        using mil = std::chrono::duration<double, std::milli>;
        auto start= clock::now();
       
        int bullet_count = 0;
        int enemy_count = 0;
        int print_count = 0;
        int loop = 0;
        while( exit_ != 1 ){//4
        
                auto end= clock::now();
                const mil total = end - start;
                bullet_tick += total.count( );        
                enemy_tick += total.count( );
                print_tick += total.count( );    
                
                move( 2 , 1);
                printw(  "                                 " );               
                move( 2 , 1);
                printw(  "count %f, bullet %f ", total.count( ), bullet_tick );
                refresh( );
                
                write_text << "\ndebug loop " << loop
                   << ", bullet_tick " << bullet_tick
                   << ", total.count " << total.count( ) << "\n";    
                if( loop == 100){//10
                        write_text.close( );
                        //break;
                }//10
                
                //std::cout << "It took " << double( duration.count() ) << "s" << std::endl;
                //movement of bulletc
                if( bullet_tick >= bullet_limit){//3
                        bullet_tick = 0;
                        bullet_count +=1;
                        move( 5 , 1);
                        printw(  "                             ");                 
                        move( 5 , 1);
                        printw(  "bullet count %d ",  bullet_count);
                        refresh( );
                                
                }//3
                //the movement of the enemy
                if( enemy_tick >= enemy_limit ){//5
                        enemy_tick = 0;
                        enemy_count +=1;
                        move( 7 , 1);
                        printw(  "                                   ");
                        move( 7 , 1);
                        printw(  "enemy count %d ",  enemy_count);
                        refresh( );
                }//5
                
                if( print_tick >= print_limit ){//7
                        print_tick = 0;
                        print_count +=1;
                        move( 9 , 1);
                        printw(  "                                   ");
                        move( 9 , 1);
                        printw(  "print count %d ",  print_count);
                        refresh( );
                }//7
                start = end;   
                loop +=1;         
        }//4
}//2

//Using <chrono>, the code you need could look like this:

int main( void){//2
       
       
        initscr( );
        curs_set( 0 );
        noecho( );
        clear( );
        
        write_text.open(  "debug.txt");
        bullet_limit = 1000;
        enemy_limit = 100;
        print_limit = 50;
        std::thread t_( t_clock );
        move( 1 , 1);
        printw(  "pause " );
        getch( );
        exit_ = 1;
        //write_text.close( );
        move(15, 1 );
        printw("exit...");
        t_.join( );
        endwin( );
}//2


