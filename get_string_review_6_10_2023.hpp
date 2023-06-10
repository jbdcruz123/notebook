
//dpat kabisadohin madalas magamit ito bilang input /output ng numbers or strings
//kasama din dito ung output alignment
#include<sstream>
#include<iostream>
#include<cstring>
#include<iomanip>

//this overloading for press any key
bool get_string( ){

        std::string output; //use for input but not use outside this func
        std::getline( std::cin, output );

        bool return_= std::cin.fail(  );
        std::cin.clear(  );
        
        return return_;
}

/* 
note   std::string::substr( int , int) first param starting index formated -1 in length
        second param is the length ex: ..substr( 2, 3 )     
 index           0 1 2 3 4 5  
 looping cut         0 1 2     it will loop 3 times starting at 2 = 2 3 4                                                        
 char value      a b c d e f
 output will be  "cde"
*/
//overloading has alimit
bool get_string(std::string& output, int length){ //2

        std::getline( std::cin, output );

        bool return_ = std::cin.fail(  );
        std::cin.clear(  );
        
        //std::cout << "\ndebug return_ " << return_ << ", output.size( ) " << output.size( ) << "\n";

        if(output.size( ) > length and !return_ ){//3
                output = output.substr( 0, length);
        }//3

        return return_;
} //2

bool get_string( char *char_output, int length){ //2

        std::string output;
        std::getline( std::cin, output );

        bool return_ = std::cin.fail(  );
        std::cin.clear(  );
        
        //std::cout << "\ndebug return_ " << return_ << ", output.size( ) " << output.size( ) << "\n";

        if(output.size( ) > length and !return_ ){//3
                output = output.substr( 0, length);
        }//3

        strcpy( char_output , output.c_str(  ) );

        return return_;
} //2


bool get_string(std::string& output) {
        // If an error occurs, `output` is left empty.
        std::getline(std::cin, output);

        bool fail = std::cin.fail();
        std::cin.clear(); // clear error flags

        return fail;
}

bool get_integer(int& output) {
        std::string s;
        std::istringstream iss;

        if ( get_string(s) ) {
                return false;
        }

        iss.str(s); // assign a new string buffer to the input stream
        output = 0;
        // If an error occurs, `output` is not modified.
        iss >> output;

        return iss.fail();
}

bool get_floating_point(double& output) {
        std::string s;
        std::istringstream iss;

        if ( get_string(s) ) {
                return false;
        }

        iss.str(s); // assign a new string buffer to the input stream
        output = 0;
        // If an error occurs, `output` is not modified.
        iss >> output;

        return iss.fail();
}


std::string center_string(std::string x, int width  ){

        //assume theres no  > width

        std::string s;
        int len_ = x.size(  );

        int start_x = ( (width - 1) /2 ) - ( (len_-1) / 2 ); 
        int last_width = (width-1) - (start_x + (len_ -1) ) ;

        //std::cout << "\ndebug x" << x << ", start_x " << start_x << ", last_width " << last_width << "\n";
        

        s = std::string(start_x ,' ' ) + x + std::string(last_width ,' ' );
                
        return s;
}

std::string truncate(std::string s, int max_length) {
        if ((int)s.size() > max_length) {
                s.erase(s.begin() + max_length - 1, s.end());
                s += '~'; // signify that truncation has occurred
        }

        return s;
}

//all of this cell datas 2nd parameter char_ ay may code na l left, m middle, r right
//ito ang format na susundin lahat ng overload ng cell_data
std::string cell_data(std::string x, std::string char_, int width) {
        std::ostringstream oss;

        if( char_ == "l" )  {
                oss << std::setw(width) << std::left << truncate(x, width);
        }if( char_ == "r" ) {
                oss << std::setw(width) << std::right << truncate(x, width);
        }if( char_ == "m" ) {
                oss << std::setw(width) << std::right << center_string( truncate(x, width), width );
        }

        return oss.str();
}
 
std::string cell_data(int x, std::string char_, int width) {
        std::string s;
        std::ostringstream oss;

        oss << x;
        s = truncate(oss.str(), width);
        oss.str(""); // reset internal string buffer

        if( char_ == "l" ) {
                oss << std::setw(width) << std::left << s;
        }else if(char_ == "r"){
                oss << std::setw(width) << std::right << s;
        }else if( char_ == "m" ) {
                oss << std::setw(width) << std::right << center_string( s, width );           
        }

        return oss.str();
}
 
std::string cell_data(double x, std::string char_, int width) {
        std::string s;
        std::ostringstream oss;

        oss << std::fixed << std::setprecision(2) << x;
        s = truncate(oss.str(), width);
        oss.str(""); // reset internal string buffer
        
        if( char_ == "l") {
                oss << std::setw(width) << std::left << s;
        }else if(char_ == "r") {
                oss << std::setw(width) << std::right << s;
        }else if( char_ == "m" ) {
                oss << std::setw(width) << std::right << center_string( s, width );
               
        }
        return oss.str();
}

/*
//on test mode, i cut mo nalng ung code at paste sa get_string.hpp
// mag lagay ng #include"get_string.hpp" sa taas,kaylangan nasa working folder ang
//file get_string.hpp
 

#include"get_string.hpp"

#include<iostream>


int main(  ){//2
        
        int int_= 123456789;
        double double_ = 12.0456;
        std::string str_ = "ron";
        
        
        std::cout << "str_ |" << cell_data( str_ , "l", 10) <<  "|" ;
        std::cout << "str_ |" << cell_data( str_ , "m", 10) <<  "|" ;
        std::cout << "str_ |" << cell_data( str_ , "r", 10) <<  "|\n" ;
        
        std::cout << "\nint_ |" << cell_data( int_ , "l", 5) <<  "|" ;
        std::cout << "int_ |" << cell_data( int_ , "m", 5) <<  "|" ;
        std::cout << "int_ |" << cell_data( int_ , "r", 5) <<  "|\n" ;
        
        std::cout << "\ndouble_ |" << cell_data( double_ , "l", 10) <<  "|" ;
        std::cout << "double_ |" << cell_data( double_ , "m", 10) <<  "|" ;
        std::cout << "double_ |" << cell_data( double_ , "r", 10) <<  "|\n" ;
        
        return 0;
}//2


*/


