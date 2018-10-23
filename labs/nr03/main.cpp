
#include <iostream>
#include <fstream> 
#include <stdexcept>
#include <list>
#include <map> 
#include <unordered_map> 
#include <vector> 
#include <sstream>
#include "string.h"


int main( int argc, char* argv [ ] )
{
	/*
   string s1 = "good";
   string s2 = " evening";

   s1 += s2;
   std::cout<<s1<<std::endl;
	*/
	
	/*
   string s1 = "good";
   string s2 = " evening";
   string s3 = " dasten";
   s1 = s1 + s2;
   s1 = s1 + s3;

   string sum = s2 + s3;
   std::cout<<s1<<std::endl;
   std::cout<<sum<<std::endl;



   string a = "A";
   string b = "B";


   //a = a + b;
   //std::cout<<a<<std::endl;

   

   if(a == b){
     std::cout << "A = B \n";
   }else{
     std::cout << "A != B\n";
   }
   if(a == a){
     std::cout << "A = A \n";
   }else{
     std::cout << "A != A \n";
   }
   std::cout << (a < b) << std::endl;
   std::cout << (s1 < s3) << std::endl;

	*/
  
   string s1 = "Dasten"; 
   //std::cout<<s1<<"\n"<<"\n";

   string s2 = "hallo";
   //std::cout<<s2<<"\n"<<"\n";


	std::swap( s1, s2 );
	std::cout<<"\n"<<"\n"<<"\n";

  //copy constr, moving semantics constr, hallo Dasten
	std::cout << string( s1 + ", " + s2 ) << "\n" ; 
	///std::cout<<"\n"<<"\n";


  //destructors x4, this is a string
	std::cout << "\n"<<"\n"<< string( "this is a string" ) << "\n"<< "\n"; 
	//std::cout<<"\n"<<"\n";

  //destructor, copy constr, moving semantics constructor, operator,
  //destructor x4
	s2 = ( s1 + "dasten" );
	std::cout<<s2<<"\n"<<"\n"<<"\n";
  

  //string zz = "zz";
  //std::cout << "before:\n";

//  string a = "A";
  //string b = "B";

  string max = greater( s1, s2 );
  std::cout << "max = " << max << "\n";
/*
  std::cout<<string("good") + string("good")<<std::endl;
  std::cout<<"good" + string("good")<<std::endl;
  std::cout<<string("good") + "good"<<std::endl;
  std::cout<<"good" + "good"<<std::endl;
*/
  string have = "have";
  string nice = "nice";
  std::cout<<have + string("a") + nice + string ("day"); 
  
}
/*
   if(a < b){
     std::cout << "A < B\n";
   }else{
     std::cout << "A >= B \n";
   }
*/
	
   



