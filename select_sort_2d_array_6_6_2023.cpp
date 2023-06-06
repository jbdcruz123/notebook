

//nakita ko lang ung questioner sa isang gc
//try ko isolve 2darray nag sort ng select sort 6/6/2023
//assending order
#include <iostream>
#include <sstream>
#include <random>

#define LENGTH_ 5

void display( int arr[][LENGTH_], int n){//2

        for(int i = 0; i < n; i +=1){ //3

                for( int jey = 0; jey < n ; jey +=1){ //4

                        std::cout << arr[i][jey] << " ";

                }//4
                std::cout << "\n";
                
        }//3
}//2


int main(){
        
        std::random_device random_;
        std::mt19937 generator_( random_() );

        std::uniform_int_distribution<int> distribution_(1, 100 );

                
        int i_fir, jey_fir, i_sec, jey_sec, initial, n = LENGTH_;

        int arr[LENGTH_][LENGTH_] = { { 6,1 , 8}, { 4,2 ,5 }, {0 , 7,3 }   };
        
        //initial value of array

        for(int row_ind =0; row_ind < n ; row_ind +=1){

                for(int col_ind =0; col_ind < n; col_ind +=1 ){

                        arr[row_ind][ col_ind ] = distribution_(generator_ );
                }

        }

        display(arr, n);

      
        i_fir =0;
        for( ; i_fir < n; i_fir+=1 ){//3

                jey_fir = 0;
                for( ; jey_fir < n - ( i_fir / (n-1 ) ) ; jey_fir+=1 ){//4


                        i_sec = i_fir;
                        jey_sec = jey_fir + 1;
                        initial = 1;         
                        
                        //std::cout << "\ndebug L11 i_fir " << i_fir << ", jey_fir " << jey_fir << "\n";
 
                        for( ; i_sec < n ; i_sec +=1 ){//5

                                //..initial
                
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
                                      
                                        if(  arr[i_fir] [jey_fir] > arr[i_sec] [jey_sec]) {//10

                                                int t = arr[i_fir] [jey_fir];
                                                arr[i_fir] [jey_fir] = arr[i_sec] [jey_sec];
                                                arr[i_sec] [jey_sec] = t;

                                        }//10


                                } //7

                        }//5

                }//4
        }//3


        std::cout << "\n\nresult: " << "\n";
        display(arr, n);

        return 0;
}
