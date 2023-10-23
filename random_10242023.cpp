
//random sample
/* gumamit ng once assign ng range 
napipili  na number
gagawa pa ako ng ibang lecture

*/
#include<random>
#include<iostream>

int random_f( int fir, int last ){//2

      std::random_device rd;
      std::uniform_int_distribution<int> dist( fir, last);
      return dist(rd);
      
}//2
int main( ){//2

      std::cout << "\n\n";

      for( int I =0 ;   I <10; I+=1 ){//3
            std::cout << random_f(  1, 1000) << "\n";
      }//3
      return 0;
}//2
