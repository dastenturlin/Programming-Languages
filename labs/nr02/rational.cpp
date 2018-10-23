
#include "rational.h"

// Complete these methods:

//#if 1

int rational::gcd( int n1, int n2 )
{
    int i;
    int rem;
    if (n1==0 || n2==0)
        return i = 1;
    else {
        rem = (n1%n2);
        while (rem!=0) {
            n1 = n2;
            n2 = rem;
            rem = (n1%n2);
        }
        i = n2;
    }
    return i;
};


void rational::normalize( )
{
    int k = rational::gcd(num, denum);
    
    num = num/k;
    denum = denum/k;
    
    if(denum < 0)
    {
        num = -num;
        denum = -denum;
    }
};




rational operator - ( rational r )
{
    r.num = -(r.num);
    return r;
}

rational operator + ( const rational& r1, const rational& r2 )
{
    rational temp;
    
    temp.num = r1.num * r2.denum + r2.num * r1.denum;
    temp.denum = r1.denum * r2.denum;
    
    
    temp.rational::normalize();
    return temp;
}

rational operator - ( const rational& r1, const rational& r2 )
{
    return r1 + (-r2);
}

rational operator * ( const rational& r1, const rational& r2 )

{
    rational temp;
    temp.num = r1.num * r2.num;
    temp.denum = r1.denum * r2.denum;
    temp.rational::normalize();
    return temp;
}

rational operator / ( const rational& r1, const rational& r2 )

{
    rational temp;
    temp.num = r1.num * r2.denum;
    temp.denum = r1.denum * r2.num;
    
    temp.rational::normalize();
    return temp;
}

bool operator == ( const rational& r1, const rational& r2 )
{
    rational temp1 = r1;
    rational temp2 = r2;
    
    temp1.rational::normalize();
    temp2.rational::normalize();
    return (temp1.num == temp2.num && temp1.denum == temp2.denum);
}
bool operator != ( const rational& r1, const rational& r2 )
{
    return !(r1==r2);
}

std::ostream& operator << ( std::ostream& out, const rational& r )
{
    if(r.denum == 0)
    {
        out<<"Division by zero";
    }
    else
    out<<r.num;
    
    if ( (r.denum != 1) && ( r.num != 0 ) && (r.denum != 0) ) out<<"/"<<r.denum;
    return out;
}




