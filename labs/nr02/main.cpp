#include "rational.h"
#include "matrix.h"

int main( int argc, char* argv [ ] )
{
   rational r1( -5, 6);
   rational r2( 4, 3 );
   rational r3( 5, 6 );
   rational r4( 1, 2 );
   
    
    std::cout<< rational::gcd(-5, 6) <<std::endl;
    std::cout<< rational::gcd(4, 8) <<std::endl;
    std::cout<< rational::gcd(8, 2) <<std::endl;
    std::cout<< rational::gcd(8, 6) <<std::endl;

    std::cout<<std::endl;
    

    r1.rational::normalize();
    std::cout<< r1 <<std::endl;
    
    r2.rational::normalize();
    std::cout<< r2 <<std::endl;
    
    r3.rational::normalize();
    std::cout<< r3 <<std::endl;

    r4.rational::normalize();
    std::cout<< r4 <<std::endl;
    
    matrix m1 = { { {1,2}, {-2,7} }, { {1,3}, {2,8} } };
   std::cout << m1 << "\n";

   matrix m2 = { { {-1,3}, {2,5} }, { { 2,7 }, { -1,7 } } };
   std::cout << m2 << "\n";

   std::cout << m1 * m2 << "\n";
   std::cout << m1. inverse( ) << "\n";

   matrix m3 = { { 4,5}, { -1, 2 }};

   std::cout << m1. determinant( ) << "\n";

   std::cout << m1. adjugate( ) << "\n";
   std::cout << m1. inverse( ) * m1 << "\n";
    
    std::cout<< "Associativity: " << "\n" << (m1 * m2) * m3 << "\n" << m1 * (m2 * m3)<< "\n";
    std::cout<< "Distributivity: " << "\n" << m1 * ( m2 + m3) << "\n" << m1 * m2 + m1 * m3<< "\n";
    
    std::cout<< "Composition:" << "\n" << m1 * (m2 * r1) << "\n" << (m1 * m2) * r1<< "\n";
    std::cout<< "Determinant:" << "\n" << m1.determinant() * m2.determinant() << " " << (m1*m2).determinant() << "\n";
    
    std::cout<< "Inverse equality:" << "\n" << m1*m1.inverse()  << "\n" << m1.inverse() * m1 << "\n" << matrix::identity();
    
}

