//del me 



#include<random>
#include<iostream>

std::random_device rd;
std::uniform_int_distribution<int> dist;

int random_f( int fir, int last ){//2
  
      // good ito para kang nag call ng constructor
      //dist = std::uniform_int_distribution<int> (fir, last);

     //good ito gamit ang library objectparam_type
     // auto new_ = std::uniform_int_distribution<int>::param_type( 20, 23);     
      //dist.param( new_ );                               

      //good ito gumawa ng object name
      //at call ubg constructor
      std::uniform_int_distribution<int>::param_type new_( 20, 23);     
      dist.param( new_ );                               

      //error ito hindi part ng dist ung param_type object
      //dist.param( dist.param_type( 20, 23 )  );
      
      return dist(rd);
      
}//2

int* sort(int *A, int N  ){//2

      for( int I= 0;  I < N-1; I+=1 ){//3
             
            for( int J= I+1;  J < N;  J+=1 ){//4
            
                  if( A[ I] > A[ J] ){//5
                        int t = A[I];
                        A[ I ] = A[ J ];
                        A[J ] = t;      
                  }//5
                  
            }//4      
      }//3
      return A;  
}//2

int main( ){//2

      std::cout << "\n\nbb input: \n";
      
      int A[ 10];
      int *B;
      for( int I =0 ;   I <10; I+=1 ){//3
      
            A[ I ] = random_f(  1, 3);
      
            std::cout << A[I] << " ";
      }//3
      std::cout << "\n\nresult\n";
      
      B = sort( A, 10 );
      for( int I =0 ;   I <10; I+=1 ){//3
            
          std::cout << B[I] << " ";
      }//3
      
      std::cout << "\n\n";      
      
      return 0;
}//2
