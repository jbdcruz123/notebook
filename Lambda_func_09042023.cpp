




//lambda function


#include<iostream>

//lambda func can be declare global
auto F =  [  ] ( int a, int b ){
  
      if( a / b <=  10) {//3
            return 1;
      } else {//3
            return 0;
      }//3
      
                      
};

int main(  ) {

      int x= 10, y=2;

      //lambda can be declare local
      //the [ ] is called capture pag [&v} ay by reference
      //pag [ v ] ay by value 
      auto cap =  [ x, y ] (  ) { //4
            if( x <=10 and  y <= 10 ){//3
                  return 1;  
            }//3
            return 0;    
      };//4
      
      //i implement the return value bool
      //10 is true 1
      auto lam = [ &x  ] ( int a )->bool{//5
            x++;
            if(  a <= 10){//7
                  return 10;
            }//7
            
            return 0;
      };//5            
                           
      //inserting F to _F                                                   
      auto _F = F( x, y ); 
      
      auto _lam = lam( 2 );//uses const value
      
      //when using auto it is shourcut 
      //nakapasok ung F sa _F
      std::cout << "\nresult _F " << _F;
      
      //normal call F()  with parentesis
      std::cout << "\nresult F " << F( 2,2 );
      
      
      std::cout << "\nresult cap " << cap(  );
      std::cout << "\nresult _lam " << _lam
         << ", x " << x;
      
      std::cout << "\n\nexit...";                
      return 0;     
}






















