
//nakita ko lng sa gc ung questionaire, try ko sagot  6/6/2023
#include<iostream>
#include<iomanip>
#include<random>
#include<string>

#define MAX 10

void initial_col( int arr[MAX] , int n){//2

        for( int i =0; i < n ; i+=1 ){//3
                arr[i] = 0;
        }//3

}//2

void initial_2dimension( int arr[ ] [MAX] , int n,std::uniform_int_distribution<int> distribution_ , std::mt19937 generator_ ){//2
        
        for( int i =0 ; i < n; i+=1 ){//3

                for( int jey = 0; jey < n ; jey+=1  ){//4

                        arr[i][jey] = distribution_( generator_ );

                }//4

        }//3


}//2

void display( int arr[][MAX], int n){//2

        for(int i = 0; i < n; i +=1){ //3

                for( int jey = 0; jey < n ; jey +=1){ //4

                        std::cout << std::setw(3 ) << std::left << arr[i][jey] << " ";

                }//4

                std::cout << "\n";
                
        }//3
}//2

void display_all( int arr[][MAX], int n, int row_total[MAX],  int col_total[MAX], int diagonal_total, int alternate_total){//2                    

        std::cout << "\n\ndisplay all \n";
        
        std::cout << std::setw(7 ) << std::left << "index";
        for(int i =0; i < n; i+=1   ){ //20
        
                std::cout << std::setw(5 ) << std::left << i;
        }//20

        std::cout << std::setw(5 ) << std::left << "total\n\n";

        for(int i = 0; i < n; i +=1){ //3

                std::cout << std::setw(7 ) << std::left << i; 
                for( int jey = 0; jey < n ; jey +=1){ //4

                        std::cout << std::setw(5 ) << std::left << arr[i][jey];

                }//4

                std::cout << std::setw(5 ) << std::left  << row_total[i]<< "\n";
                
        }//3

        
        std::cout << "\n" <<  std::setw(7 ) << std::left  << "total";
        for(int i = 0; i < n; i +=1){ //10

                std::cout << std::setw(5 ) << std::left  << col_total[i];
        }//10

        std::cout << "\n\n";
        std::cout << std::setw(5 ) << std::left  << "diagonal total " <<  diagonal_total<< "\n";

        std::cout << std::setw(5 ) << std::left  << "alternate total " << alternate_total<< "\n";

}//2


void main_process( int arr[][MAX], int n ){//2

        int row_total[MAX];

        int col_total[MAX];

        initial_col( row_total, MAX);

        initial_col( col_total, MAX);

        int row_diagonal = 0, col_diagonal = 0, diagonal_total=0;

        int row_alternate=0, col_alternate= n-1, alternate_total=0;


        //main body of prog
        for( int row_index =0 ; row_index < n; row_index+=1 ){//3

                for( int col_index = 0; col_index < n ; col_index+=1  ){//4

                        //diagonal
                        if ( row_index == row_diagonal  && col_index == col_diagonal){//5

                                //      std::cout << "\ndebug L11 row_diagonal " << row_diagonal << ", col_diagonal " << col_diagonal
                          
                                diagonal_total += arr[row_diagonal][col_diagonal];
                                
                                row_diagonal +=1;
                                col_diagonal +=1;
                        }//5

                        //alternate diagonal
                        if ( row_index == row_alternate  && col_index == col_alternate){//5

                                alternate_total += arr[row_alternate][col_alternate];

                                row_alternate +=1;
                                col_alternate -=1;
                                
                        }//5


                        row_total[row_index] += arr[row_index][col_index];  

                        col_total[col_index] += arr[row_index][col_index];  

                }//4

        }//3

        display_all(arr, MAX, row_total, col_total, diagonal_total  , alternate_total   );
        
}//2

void ascend(int arr[][MAX], int n, std::string category){//2

        if( category != "ascend" && category != "descend" ) {//21

                std::cout << "\n\nerror must input ascend or descend ";
                return;
        }//21

        int i_fir, jey_fir, i_sec, jey_sec, initial;
     
        i_fir =0;
        for( ; i_fir < n; i_fir+=1 ){//3

                jey_fir = 0;
                for( ; jey_fir < n - ( i_fir / (n-1 ) ) ; jey_fir+=1 ){//4

                        i_sec = i_fir;
                        jey_sec = jey_fir + 1;
                        initial = 1;         
                        
                        //std::cout << "\ndebug L11 i_fir " << i_fir << ", jey_fir " << jey_fir << "\n";
 
                        for( ; i_sec < n ; i_sec +=1 ){//5
                
                                if( initial == 0) {//8

                                        jey_sec = 0;
                                }//8 
                          
                                initial = 0;

                                //std::cout << "\ndebug L11_2 i_sec " << i_sec << ", jey_sec " << jey_sec << "\n";
 
                                for( ;  jey_sec < n ; jey_sec +=1 ){ //7

                                          /*std::cout << "\ndebug L11_3 i_fir " << i_fir << ", jey_fir " << jey_fir
                                           << ", i_sec " << i_sec << ", jey_sec " << jey_sec << "\n"
                                           << ", arr[i_fir] [jey_fir] " << arr[i_fir] [jey_fir] << ", arr[i_sec] [jey_sec] " << arr[i_sec] [jey_sec] << "\n";
                                        */
                                        if( category == "ascend") { //20

                                                if(  arr[i_fir] [jey_fir] > arr[i_sec] [jey_sec]) {//10

                                                        int t = arr[i_fir] [jey_fir];
                                                        arr[i_fir] [jey_fir] = arr[i_sec] [jey_sec];
                                                        arr[i_sec] [jey_sec] = t;

                                                }//10
                                   
                                        } else { //20

                                               if(  arr[i_fir] [jey_fir] < arr[i_sec] [jey_sec]) {//10

                                                        int t = arr[i_fir] [jey_fir];
                                                        arr[i_fir] [jey_fir] = arr[i_sec] [jey_sec];
                                                        arr[i_sec] [jey_sec] = t;

                                                }//10

                                        }//20

                                } //7

                        }//5

                }//4
        }//3


}//2


int main(void){ //2

        int arr[MAX][MAX];

        std::random_device random_;
        std::mt19937 generator_( random_() );

        std::uniform_int_distribution<int> distribution_(1, 10);
 
        //nasa initial 2dimension ung input ng user, random muna gamit me
        initial_2dimension( arr, MAX, distribution_ , generator_ );

        display(arr, MAX);

        int total_col[MAX];

        //displaying all total 
        main_process(arr, MAX  );

        ascend(arr, MAX, "ascend");

        std::cout << "\n\ndisplay in ascend \n";
        display(arr, MAX);
        
        ascend(arr, MAX, "descend");

        std::cout << "\n\ndisplay in descend \n";
        display(arr, MAX);

        std::cout << "\n\naexit...";

}//2








