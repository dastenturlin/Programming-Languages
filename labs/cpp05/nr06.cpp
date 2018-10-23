
#include <fstream>
#include <iostream>
#include <random>
#include <map>
#include <unordered_map>
#include <vector>

#include "listtest.h"
#include "vectortest.h"
#include "timer.h"


std::list<std::string> convertStringToList( std::vector<std::string> v);


void readfile( std::istream& input, std::vector< std::string > & vect );


struct case_insensitive_hash
{
  size_t operator ( ) ( const std::string& s ) const{
    std::string lower_s = "";
    for(size_t i = 0; i < s.size(); i++){
      lower_s += std::tolower(s[i]);
    }
    std::hash<std::string> hash;
    return hash(lower_s);

  }
};

struct case_insensitive_equality
{
  bool operator ( ) ( const std::string& s1, const std::string& s2 ) const{
    if(s1.size() != s2.size()) return false;

    for(size_t i = 0; i < s1.size(); i++){
      if(std::tolower(s1[i]) != std::tolower(s2[i])) return false;
    }
    return true;
  }
};

struct case_insensitive_cmp
{
  bool operator( ) ( const std::string& s1, const std::string  & s2 ) const{

    size_t min = s1.size();

    

    if(s2.size() < min) min = s2.size();

    for(size_t i = 0; i < min ; i++){
      char a = std::tolower(s1[i]);
      char b = std::tolower(s2[i]);
      if(a != b){
        return a < b;
      }
    }

    if(s1.size() < s2.size()) return true;
    else if (s1.size() > s2.size()) return false;
   
    return false;
   }
};


std::unordered_map< std::string, unsigned int, case_insensitive_hash, case_insensitive_equality > 
hashed_frequencytable( const std::vector< std::string >& text ){
  std::unordered_map< std::string, unsigned int, case_insensitive_hash, case_insensitive_equality > result;
  for(auto element : text){
    result[element]++;
  }
  return result;
}

std::map< std::string, unsigned int, case_insensitive_cmp > 
frequencytable(const std::vector< std::string > & text){
  std::map< std::string, unsigned int, case_insensitive_cmp > result;
  for(auto word : text){
    result[word]++;
  }
  return result;
}

std::ostream&
operator << ( std::ostream& stream,
const std::map< std::string, unsigned int, case_insensitive_cmp > & freq ){
  for(auto element : freq){
    stream << "( " << element.first << ", " << element.second << " )" << " ";
  }
  return stream;
}

std::pair <std:: string, unsigned int>  most_frequent(std::map< std::string, unsigned int, case_insensitive_cmp > my_map ){
  size_t max = 0;
  std::string ans = "";
  for(auto iter = my_map.begin(); iter != my_map.end(); iter++){
    if(iter->second > max){
      max = iter->second;
      ans = iter->first;
    }
  }
  std::pair <std:: string, unsigned int> pr(ans, max);
  return pr;
}

*/


int main( int argc, char* argv [] )
{
   
   std::ifstream inp {"new.txt"};
   std::cout << vectortest :: readfile (inp) << "\n";

   std::vector< std::string > vect;

   std::cout << vect << "\n";

   vect.clear();
   vect = vectortest::randomstrings(5000, 50);
   std::list< std::string > list;
   list = convertStringToList(vect);

   // Performance test   
   auto vect1 = vect;
   auto vect2 = vect;
   //std::cout << vect1 << "\n";
   {
      timer t( "***sort move vector", std::cout ); 
      vectortest::sort_move( vect1 );
   }
   //std::cout << vect1 << "\n";

   std::cout << " ========= " << "\n";

   
   //std::cout << vect2 << "\n";
   {
      timer t( "***sort assign vector", std::cout ); 
      vectortest::sort_assign( vect2 );
   }
   //std::cout << vect2 << "\n";

   std::cout << " ========= " << "\n";
auto vect3 = vect;
   //std::cout << vect3 << "\n";
   {
      timer t( "***sort std vector", std::cout ); 
      vectortest::sort_std( vect3 );
   }
   //std::cout << vect3 << "\n";
   auto list2 = list;
   //std::cout << lst2 << "\n";
   {
      timer t( "***sort move list", std::cout ); 
      listtest::sort_move( list2 );
   }
   //std::cout << lst2 << "\n";
   
   //std::cout << " ========= " << "\n";
   
   auto list3 = list;
   //std::cout << lst3 << "\n";
   {
      timer t( "***sort assign list", std::cout ); 
      listtest::sort_assign( list3 );
   }
   //std::cout << lst3 << "\n";

   //std::cout << " ========= " << "\n";
   

   //std::cout << frequencytable( std::vector< std::string > { "AA", "aA", "Aa", "this", "THIS" } );
   /*
   case_insensitive_cmp c;
   std::cout << c( "aa", "A" ) << c( "a","b" ) << c( "A", "b" ) << "\n";

   case_insensitive_hash h;
   std::cout << h( "xxx" ) << " " << h( "XXX" ) << "\n"; 
   std::cout << h( "Abc" ) << " " << h( "abC" ) << "\n";

   case_insensitive_equality e;
   std::cout << e( "xxx", "XXXX" ) << "\n";


   std::cout << frequencytable( std::vector< std::string > { "AA", "aA", "Aa", "this", "THIS" } );
   //std::map<std::string, unsigned int> map;
   //map.insert(std::pair <std::string, unsigned int> ("dasten", 40));


   std::ifstream inp{ "book.txt" };
   std::vector< std::string> vect;
   readfile (inp, vect);

   std::map< std::string, unsigned int, case_insensitive_cmp > map = frequencytable(vect);

   std::cout << "Using std::map \n";
   std::cout <<"’magnus’ frequency - " <<map["magnus"] << "\n";
   std::cout <<"’hominum’ frequency - " <<map["hominum"] << "\n";
   std::cout <<"’memoria’ frequency - " <<map["memoria"] << "\n";
   std::cout << most_frequent(map).first << " : " << most_frequent(map).second<<std::endl;

*/

   return 0;
}

std::list<std::string> convertStringToList( std::vector<std::string> v)
{
   std::list<std::string> l;
   for(auto i = v.begin(); i != v.end(); ++i)
   {
      l.push_front (v.back());
      v. pop_back(); 
   }
   return l;
}

void readfile( std::istream& input, std::vector< std::string > & vect )
{
  char c;
  std::string s;

  while(true){
      c = input.get();
      if (input.good()) {
         if (isalpha(c) == true) {
         s += c;
         } 
      else {
         if(s.size() > 0) vect.push_back(s);
         s = "";
      }
      } 
    else {
      break;
    }
  }
  if(s.size() > 0) vect.push_back(s);
}






