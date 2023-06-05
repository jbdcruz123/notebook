

//parati kasi ito maencounter sa
input std::cin

int ftest_cin(  ) {//2
      char ch;
      if( std::cin.fail(  )  ) {  //3
            std::cin.clear(  ); //clear all flag
            std::cin.ignore(1000, '\n');
            return;
      }//3
      fflush( );
}//2
void fflush(  ) {//2
      while(  1 ) {//10
            ch = getchar(  );
            //10 is newline, 13 is enter key
            if(  ch == 10 || ch == 13) { //20
                  //lalabas pag na flush na
                  break;
            }//20
      }//10
}//2
//blaker ng stoi pag nainput "a1" mag error ito dahil leters
//nauna
int fstoi(std::string pinp  , int& pval ){//2
      try  {//3
            pval = stoi(  pinp );
            return 0;
      } catcth(  std::invalid_argument& e ) {//3
           // e.what( )  definition ng error
            //do error statement here
            return -1;
      }//3
}//2
