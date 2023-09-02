

//sep 2, 2023
//example ito  ng 2dimension array ng vector
//pero sa environment ng class object
//at hindi manually input ng user

#include<iostream>
#include<vector>

void init(  std::vector<  std::vector <  int  > > &A ) {//2

      
      for(int I = 0, X =0;  I < 3 ; I+=1  ) {//3
            
            //input a brach in array of 2d  
            A.push_back( {  } ); 
            
            for( int J = 0 ;   J < 3 ; J+=1, X+=1  ){//4
                  A[ I ].push_back( X + 1 ) ;
                      
            }//4
       }//3      
}//2


void disp(  std::vector<  std::vector <  int  > > A ) {//22                  
    
       for(int I = 0;  I < 3 ; I+=1  ) {//3
                        
            for( int J = 0 ;   J < 3 ; J+=1  ){//4
            
                      std::cout << "\n I "<<  I 
                         << " J " <<  J 
                         << " A  " <<  A[ I ][ J ];          
            }//4
       }//3      

}//2

int main(void) {//2

      std::vector<  std::vector <  int  > > A;
      init( A );
      
       disp( A);      
       std::cout << "\nexit...";          
       return 0;            
}//2

/*

output is

I 0 J 0 A  1                                    
  I 0 J 1 A  2
 I 0 J 2 A  3
 I 1 J 0 A  4                                 
  I 1 J 1 A  5
 I 1 J 2 A  6
 I 2 J 0 A  7
 I 2 J 1 A  8                                
  I 2 J 2 A  9
/*





