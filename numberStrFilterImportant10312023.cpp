
//paki diaables lahat ng cout debuger

#include<iostream>
#include<string>
 
int fstrtonum( std::string par, std::string *out ) {//2

      //L20
            
      //return error flag 0 is true:
      //1 single negative (pero ala sa posisyon)
      //2  multiple negative
      //6  multiple .
      //10  error non numeric input  

      int first_zero=0, first_num=0, point=0, neg=0, last_zero = 0, ind_out =0, last_num = 0;
      
      int i, n;
      i=0;
      n = par.size(  );

      std::cout << "\nL20 n" << n << "\n";

      while( i < n) {//3
      
            //debug ito
            std::cout << "\nL21 i < ==> i " << i << " ,ind_out " << ind_out << " ,par " << par[i ] << " ,first_zero " << first_zero << " ,first_num " << first_num << " ,point " << point << " ,neg " << neg << " ,last_zero " << last_zero << " ,last_num " << last_num ;                              
            std::cout << "\n              out " << *out << "\n";            
            //getchar(  );

            if( par[i] ==  '-'){//4
                  //entering -

                  std::cout << "\nL21_2 '-' T " << "\n"; 

                  if( first_zero == 0 && first_num == 0 && point == 0 && neg == 0){//5
                        //this is initial must all flag false

                        std::cout << "\nL21_2_2 first_zero first_num T ==> " << "\n"; 

                        neg = 1;
                        out->push_back( par[ ind_out ] ); 
                        ind_out +=1;
                        i+=1;
                        continue;                
                  } if( (first_zero != 0 || first_num !=  0 || point != 0) && neg == 0){//5                        
                  
                        //error input
                        *out = "";
                        ind_out = 0;

                        return 1; // single negative (pero ala sa posisyon)                        
                  }if( neg == 1 ) {//5

                        //multi negative
                        *out = "";
                        ind_out = 0;

                        return 2; // means multiple neg
                  }//5

                
            }//4

            //encontered 0
            if( par[ i ] == '0' ){ //7

                  std::cout << "\nL21_3 '0' T " << "\n"; 

                  if( point == 1) {//9

                        last_zero +=1;
                        i+=1;
                        continue;
                  }else { //9                  

                        //ala pa so point = 1

                        if( first_num == 0 ){ //8
                              //safe na hindi kasama first_zero sa blocker

                              first_zero = 1;
                              i+=1;
                              continue;
                    
                        }//8

                  }//9

                  //asumme straight first_num = 1
                  out->push_back( par[ i ] ); 
                  ind_out +=1;
                  i+=1;
                  continue;                             
            }//7

            //1 to 9 sorting
            if( par[ i ] >= 49 && par[ i ] <= 57 ){ //10

                  std::cout << "\nL21_4 '1 to 9' T " << "\n"; 

                  if( point == 1) {//12

                        //operate last zero here

                        int s_i = 0;
                        while( s_i < last_zero) {//14

                              out->push_back( '0' ); 
                              ind_out +=1;
                              s_i+=1;
                        }//14                        
   
                        last_zero =0;
                        last_num = 1;

                  }else {//12

                        //standby no code here                                 
                       
                  }//12
                  
                  first_zero = 0;
                  first_num = 1;
                  out->push_back( par[ i ] );
                  ind_out +=1;
                  i+=1;
                              
                  continue;   
            }//10

            if( par[ i ] == '.' ) {//15

                  std::cout << "\nL21_5 '.' T " << "\n"; 

                  if( point == 1) {//17

                        //multiple point
                        *out = "";
                        ind_out = 0;
                        return 6;    //multiple point
                  }//17

                  point = 1;
                  
                  if( first_num == 0 && neg == 1) {//18

                        *out = "-0.";
                        ind_out = 3;
                        i+=1;
                        continue;
                  }//18

                  if( first_num == 0 ) {//19

                        *out = "0.";
                        ind_out = 3;
                        i+=1;
                        continue;
                  }//19

                  out->push_back( par[ i ] );
                  ind_out +=1;                
                  i+=1;
                  continue;
            }//15

            //a none number is inputed
            //return
            std::cout << "\nL21_7 a none number " << "\n"; 
            *out = "";
            ind_out = 0;
            return 10; // none numeric input
             
      }//3

      //after main looper
      if( point == 1 ){//20

            if(neg == 1 && first_zero ==1 && first_num == 0 && last_num == 0 && last_zero != 0) {//21
                  //format form -0.0 to 0
                  *out = "0";
                  ind_out = 1;
            
            }else if( neg == 1 && first_zero ==1 && first_num == 0 && last_num == 0 && last_zero == 0  ) {//21
                  //for -0. to 0
                  *out = "0";
                  ind_out = 1;           

            }else if( neg == 1 && first_zero ==0 && first_num == 0  && last_num == 0 && last_zero == 0  ) {//21

                   //for -. to 0
                  *out = "0";
                  ind_out = 1;         

            } else if( last_zero != 0 ) {//21
                  // .0 or .many0 = 0

                  //no update, cause its not process
                  last_zero = 0;
            }//21

      }//20

      if( neg == 1 && first_zero ==1 && first_num == 0 && last_num == 0 && last_zero == 0 || neg == 1 && first_zero ==0 && first_num == 0 && point == 0 && last_num == 0 && last_zero == 0  ) {//23
            //for -0 to 0 or - to 0
            *out = "0";
            ind_out = 1;
      }//23

      if( neg == 0 && first_zero ==1 && first_num == 0 && last_num == 0 && last_zero == 0 ) {//24      
            //for many 0 to 0 
            *out = "0";
            ind_out = 1;

      }//24

      return 0;
}//2

int main(void ) {//2

      //input string number
      std::string inp = "-00000.01000";
      std::string out;
    
      std::cout << "\n\ninput num: ";
      std::cin >> inp;

      int ret = fstrtonum(inp , &out);
      std::cout << "\n\n############\nreturn " << ret <<  ", out: " << out;

      std::cout << "\n\nexit...\n"; 
      return 0;
}//2

























