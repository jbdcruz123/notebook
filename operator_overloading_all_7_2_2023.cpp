



/*
test all the overloading
        kung unary ung overload ay  
        return_type operator_etc( ) {  this   }
        isang variable this ang involve at dapat i return


        kung binary naman ung overload ay
        return_type operator_etc( obj_class ){ this.. obj_class operation  }
        dalawang variables ang involve, isa lang sa kanila ang dapat return

        note: ang binary operator ay dapat nasa labas ng class o may friend keyword
          na gamit.

        kakaiba naman ang [  ] operator
        data_type& operator[  ] ( int ) index dapat ang nasa int
                                 return_type dpat nasa member array input or output ito

          ex:         obj[1] = <--input
                       output <-- = obj[1]
*/



#include<iostream>
#include<string>

//for practice purpose b_class is not use in this test
//showing only that a_class can input other class
class b_class{

        public:
                b_class(): mem_int(0) {  };
                int mem_int;
       
};

//in operator overloading main class template can be no template use
template<typename p_tem  >
class a_class{

        std::string mem_str[10];
                
        public:
                a_class( ){ 
                        mem_tem.mem_int=20; 
                        mem_int = 10; 
                        for(int i=0 ; i< 10; i++ ){

                                mem_str[ i]= "string " + std::to_string( i+1 );
                        }
                };
                p_tem mem_tem;
                int mem_int;
               
                std::string out_str;
 
                //must use same object type in template parameter
                //defaut first parameter is this*, second parameter is b_plus
                //u can specify ur own return value in this sample it returns a_class type
                template<typename a_plus= a_class, typename b_plus= b_class >
                a_plus operator+( b_plus par){
                        (*this).mem_int  = (*this).mem_int + par.mem_int;
                        return *this;
                }
                template<typename a_minus= a_class, typename b_minus = a_class >
                a_minus operator-( b_minus par){
                        (*this).mem_int = (*this).mem_int - par.mem_int;
                        return *this;
                }
                template<typename a_multi = a_class, typename b_multi= a_class >
                a_multi operator*( b_multi par){
                        (*this).mem_int = (*this).mem_int * par.mem_int;
                        return *this;
                }
                template<typename a_divide= a_class, typename b_divide= a_class >
                a_divide operator/( b_divide par){
                        (*this).mem_int = (*this).mem_int / par.mem_int;
                        return *this;
                }

                //assignto 
                template<typename a_equal= a_class, typename b_equal= a_class >
                a_equal operator=( b_equal par){
                        (*this).mem_int = par.mem_int;
                        return *this;
                }

                //++v prefix type
                template<typename a_equal= a_class>
                a_equal operator++(){
                        (*this).mem_int = (*this).mem_int + 1;
                        return *this;
                }

                //v++ postfix type, return value is a_equal but auto convert to int
                template<typename a_equal= a_class>
                a_equal operator++(a_equal){
                        (*this).mem_int = (*this).mem_int + 1;
                        return (*this).mem_int;
                }

                //--v prefix type
                template<typename a_equal= a_class>
                a_equal operator--(){
                        (*this).mem_int = (*this).mem_int - 1;
                        return *this;
                }

                //v-- postfix type, return value is a_equal but auto convert to int
                template<typename a_equal= a_class>
                a_equal operator--(a_equal){
                        (*this).mem_int = (*this).mem_int - 1;
                        return (*this).mem_int;
                }

                // += add
                template<typename a_add = a_class>
                a_add operator+=(a_add par){
                        (*this).mem_int = (*this).mem_int + par.mem_int;
                        return *this;
                }

                // += use integer parameter
                template<typename a_add = a_class>
                a_add operator+=(int par){
                        (*this).mem_int = (*this).mem_int + par;
                        return *this;
                }

                // -= add
                template<typename a_add = a_class>
                a_add operator-=(a_add par){
                        (*this).mem_int = (*this).mem_int - par.mem_int;
                        return *this;
                }

                // -= use integer parameter
                template<typename a_add = a_class>
                a_add operator-=(int par){
                        (*this).mem_int = (*this).mem_int - par;
                        return *this;
                }

                // *= add
                template<typename a_add = a_class>
                a_add operator*=(a_add par){
                        (*this).mem_int = (*this).mem_int * par.mem_int;
                        return *this;
                }

                // *= use integer parameter
                template<typename a_add = a_class>
                a_add operator*=(int par){
                        (*this).mem_int = (*this).mem_int * par;
                        return *this;
                }

                // /= add
                template<typename a_add = a_class>
                a_add operator/=(a_add par){
                        (*this).mem_int = (*this).mem_int / par.mem_int;
                        return *this;
                }

                // /= use integer parameter
                template<typename a_add = a_class>
                a_add operator/=(int par){
                        (*this).mem_int = (*this).mem_int / par;
                        return *this;
                }

                //== operator overloading
                template<typename R = a_class>
                bool operator==( R rigth ){

                        return (*this).mem_int == rigth.mem_int;
                }

                //!= operator overloading
                template<typename R = a_class>
                bool operator!=( R rigth ){

                        return (*this).mem_int != rigth.mem_int;
                }


                 //< operator overloading
                template<typename R = a_class>
                bool operator<( R rigth ){

                        return (*this).mem_int < rigth.mem_int;
                }


                 //> operator overloading
                template<typename R = a_class>
                bool operator>( R rigth ){

                        return (*this).mem_int > rigth.mem_int;
                }

                //<= operator overloading
                template<typename R = a_class>
                bool operator<=( R rigth ){

                        return (*this).mem_int <= rigth.mem_int;
                }


                 //>= operator overloading
                template<typename R = a_class>
                bool operator>=( R rigth ){

                        return (*this).mem_int >= rigth.mem_int;
                }

                //<< left shift operator overloading
                template< typename L = a_class >
                L& operator<<( L& left ){

                        //the outcome affects on object left only
                        //u need to use & to affect it on the parameter
                        // a  << b  it affects on b only
                        std::cout << "\n\ninside operator<<";
                        left.mem_int +=1;

                        return left;
                }

                //>> right shift operator overloading
                template< typename L = a_class >
                L& operator>>( L& left ){

                        //the outcome affects on object left only
                        // a  << b  it affects on b only
                        std::cout << "\n\ninside operator>>";
                        left.mem_int -=1;

                        return left;
                }

                //% right shift operator overloading
                template< typename L = a_class, typename R = a_class >
                L operator%( R right ){

                        (*this).mem_int = (*this).mem_int + right.mem_int + 10;

                        return *this;
                }

               
                // & and operator overloading
                template< typename L = a_class, typename R = a_class >
                L operator&( R right ){

                        (*this).mem_int = ( (*this).mem_int * right.mem_int )+ 70 ;

                        return *this;
                }

                  // | or operator overloading
                template< typename L = a_class, typename R = a_class >
                L operator|( R right ){

                        (*this).mem_int = (*this).mem_int + right.mem_int + 80;

                        return *this;
                }

                  // ! not operator overloading
                template< typename L = a_class, typename R = a_class >
                L operator!( ){

                        (*this).mem_int = (*this).mem_int +90;

                        return *this;
                }

                // ~  operator overloading
                template< typename L = a_class, typename R = a_class >
                L operator~( ){

                        (*this).mem_int = (*this).mem_int + 100;

                        return *this;
                }


                 // ^ operator overloading
                template< typename L = a_class, typename R = a_class >
                L operator^( R right ){

                        (*this).mem_int = (*this).mem_int + right.mem_int + 110;

                        return *this;
                }

                // && operator overloading
                template< typename L = a_class, typename R = a_class >
                L operator&&( R right ){

                        (*this).mem_int = (*this).mem_int + right.mem_int + 200;

                        return *this;
                }

                 // || operator overloading
                template< typename L = a_class, typename R = a_class >
                L operator||( R right ){

                        (*this).mem_int = (*this).mem_int + right.mem_int + 200;

                        return *this;
                }

                // [  ] operator overloading
                //nakakalito ito kaylangan may array ko na member ng class
                //input at output ay papasok dito, mukhang sa return ung acess
                //ng assignto na input at output
                //gamitan ng byref ung return type
                std::string& operator[]( int index){

                        return  (*this).mem_str[index];
                }
                

};

using use_b_class = b_class;

int main(void){

        //hindi maipapasok sa template ang sariling class object
        a_class<use_b_class> a_obj;
        a_class<use_b_class> b_obj;
        a_class<use_b_class> c_obj;

        use_b_class d_obj_b_class;

        a_obj.mem_int = 1;
        
        b_obj.mem_int = 2;

        d_obj_b_class.mem_int = 3;
        
        c_obj = a_obj + d_obj_b_class;

        std::cout << "\n\ntotal add mem_int " << c_obj.mem_int;

        //minus

        a_obj.mem_int = 10;
        
        b_obj.mem_int = 2;

        c_obj = a_obj - b_obj;

        std::cout << "\n\ntotal minus mem_int " << c_obj.mem_int;

          //multi

        a_obj.mem_int = 10;
        
        b_obj.mem_int = 2;

        c_obj = a_obj * b_obj;

        std::cout << "\n\ntotal multiply mem_int " << c_obj.mem_int;

          //divide

        a_obj.mem_int = 10;
        
        b_obj.mem_int = 2;

        c_obj = a_obj / b_obj;

        std::cout << "\n\ntotal divide mem_int " << c_obj.mem_int;

        //equal        
        a_obj.mem_int = 10;
        
        b_obj.mem_int = 2;

        c_obj = b_obj;
        std::cout << "\n\ntotal assign to, mem_int " << c_obj.mem_int;   

        //++v prefix type         
        
        c_obj.mem_int = 1;
        ++c_obj;
        std::cout << "\n\ntotal ++v, mem_int " << c_obj.mem_int;       
               
        //v++ postfix type
        c_obj.mem_int = 5;
        c_obj++;
        std::cout << "\n\naatotal v++, mem_int " << c_obj.mem_int;       
       
        //--v prefix type                 
        c_obj.mem_int = 1;
        --c_obj;
        std::cout << "\n\ntotal --v, mem_int " << c_obj.mem_int;       
               
        //v-- postfix type
        c_obj.mem_int = 5;
        c_obj--;
        std::cout << "\n\naatotal v--, mem_int " << c_obj.mem_int;       
       
        //var += var
        b_obj.mem_int =1;
        c_obj.mem_int = 2;

        c_obj+=b_obj;
        std::cout << "\n\ntotal var += obj, mem_int " << c_obj.mem_int;       

        //var += 1
        c_obj.mem_int = 1;

        c_obj+=1;
        std::cout << "\n\ntotal var += int, mem_int " << c_obj.mem_int;       


        //var -= var
        b_obj.mem_int =1;
        c_obj.mem_int = 2;

        c_obj-=b_obj;
        std::cout << "\n\ntotal var -= obj, mem_int " << c_obj.mem_int;       

        //var -= 1
        c_obj.mem_int = 1;

        c_obj-=1;
        std::cout << "\n\ntotal var -= int, mem_int " << c_obj.mem_int;       


        //var *= var
        b_obj.mem_int =2;
        c_obj.mem_int = 2;

        c_obj*=b_obj;
        std::cout << "\n\ntotal var *= obj, mem_int " << c_obj.mem_int;       

        //var *= 1
        c_obj.mem_int = 2;

        c_obj*=3;
        std::cout << "\n\ntotal var *= int, mem_int " << c_obj.mem_int;       


        //var /= var
        b_obj.mem_int =2;
        c_obj.mem_int = 2;

        c_obj /=b_obj;
        std::cout << "\n\ntotal var /= obj, mem_int " << c_obj.mem_int;       

        //var /= 1
        c_obj.mem_int = 9;

        c_obj /=3;
        std::cout << "\n\ntotal var /= int, mem_int " << c_obj.mem_int;       

        // v == v
        a_obj.mem_int = 1;
        b_obj.mem_int = 10;

        std::cout << "\n\nresult 1 == 10 " <<  (a_obj == b_obj);       

        // v != v
        a_obj.mem_int = 1;
        b_obj.mem_int = 10;

        std::cout << "\n\nresult 1 != 10 " <<  (a_obj != b_obj);       

        // v < v
        a_obj.mem_int = 1;
        b_obj.mem_int = 10;

        std::cout << "\n\nresult 1 < 10 " <<  (a_obj < b_obj);       


        // v > v
        a_obj.mem_int = 1;
        b_obj.mem_int = 10;

        std::cout << "\n\nresult 1 > 10 " <<  (a_obj > b_obj);       

        // v <= v
        a_obj.mem_int = 2;
        b_obj.mem_int = 2;

        std::cout << "\n\nresult 2 <= 2 " <<  (a_obj <= b_obj);       


        // v >= v
        a_obj.mem_int = 1;
        b_obj.mem_int = 1;

        std::cout << "\n\nresult 1 >= 1 " <<  (a_obj >= b_obj);

        // << left shift
        a_obj.mem_int = 1;
        
        b_obj.mem_int = 2;

        c_obj.mem_int = 0;

        //    affects on a_obj  and b_obj only
        c_obj << a_obj << b_obj;

        std::cout << "\n\nresult << " <<  a_obj.mem_int;
       

         // << left shift
        a_obj.mem_int = 1;
        
        b_obj.mem_int = 2;

        c_obj.mem_int = 0;

        c_obj >> a_obj >> b_obj;

        std::cout << "\n\nresult >> " <<  b_obj.mem_int;
        
         //% modulus overloading
        a_obj.mem_int = 1;
        
        b_obj.mem_int = 2;

        c_obj = a_obj % b_obj;

        std::cout << "\n\nresult (1 % 2 )+ 10=  " <<  c_obj.mem_int;

        //  & and overloading
        a_obj.mem_int = 1;
        
        b_obj.mem_int = 2;

        c_obj = a_obj & b_obj;

        std::cout << "\n\nresult (1 & 2) multi + 70=  " <<  c_obj.mem_int;

        //  | or overloading
        a_obj.mem_int = 1;
        
        b_obj.mem_int = 2;

        c_obj = a_obj | b_obj;

        std::cout << "\n\nresult (1 & 2) + 80=  " <<  c_obj.mem_int;


         //  ! not overloading
        a_obj.mem_int = 1;
        
        c_obj = !a_obj ;

        std::cout << "\n\nresult (!1  ) + 90=  " <<  c_obj.mem_int;

        //  ~ not overloading
        a_obj.mem_int = 1;
                
        c_obj = ~a_obj;

        std::cout << "\n\nresult (~1 ) + 100=  " <<  c_obj.mem_int;

         //  ^ xor overloading
        a_obj.mem_int = 1;
        
        b_obj.mem_int = 2;

        c_obj = a_obj ^ b_obj;

        std::cout << "\n\nresult (1 ^ 2) + 110=  " <<  c_obj.mem_int;

         //  && and overloading
        a_obj.mem_int = 1;
        
        b_obj.mem_int = 2;

        c_obj = a_obj && b_obj;

        std::cout << "\n\nresult (1 && 2) + 200=  " <<  c_obj.mem_int;

         //  || or overloading
        a_obj.mem_int = 1;
        
        b_obj.mem_int = 2;

        c_obj = a_obj || b_obj;

        std::cout << "\n\nresult (1 || 2) + 210=  " <<  c_obj.mem_int;


        //  [  ] array overloading

        c_obj[1] = "wait";
        
        std::cout << "\n\nresult   " <<  c_obj[1];

        std::cout << "\n\nexit... \n" ;  
        return 0;
}        





















