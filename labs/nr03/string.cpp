
#include "string.h"

//#if 0

// as usual: Take the functions out one by one when you write them.

string& string::operator += ( char c )
{
   	char * temp = new char [string::size() + 1];
  	for (size_t i = 0; i < len; i++)
  	 {
        temp[i] = this->p[i]; //copy assignment
  	 }
  	temp[len] = c;
  	
    this->p = temp;
  	this->len = this->len + 1;
  	
  	//delete[] p;

  	return *this;

}


string& operator += ( string& s1, const string& s2 )
{
	size_t size = s2.size();
	for (size_t i = 0; i < size; i++)
	{
		s1 += s2[i];
	}
	return s1;
}

string operator + ( string s1, const string& s2 )
{
	/*
	string temp = "";
	temp += s1;
	temp += s2;
	return temp;
	*/
  /*
	string temp;
  	for(size_t i = 0; i < s1.size(); i++)
  	{
    	temp += s1[i];
  	}
  	for(size_t i = 0; i < s2.size(); i++)
  	{
    	temp += s2[i];
  	}
  	return temp;*/

  s1 += s2;
  return s1;
}


bool operator == ( const string& s1, const string& s2 )
{
	if(s1.size() != s2.size()) return false;

	for(size_t i = 0; i < s1.size(); i++)
	{
		if(s1[i]!= s2[i]) return false;
	}
	return true;
}
bool operator < ( const string& s1, const string& s2 )
{
	//if(s1.size() == s2.size()) return false;
    //else if(s2.size() > s1.size()) return true;
    size_t i = 0;
    while ( ((s1.size() - i) != 0) || ((s2.size() - i)!= 0) )
    {
    	if(s1[i] > s2[i]) return false;
    	//else return true;
    	i++;
    }
    return true;
}
const string& greater( const string& s1, const string& s2 )
{
	if(s1 > s2) return s1;
	else return s2;
}

//#endif

/*
std::ostream& operator << ( std::ostream& out, const string& s )
{
   for( size_t i = 0; i < s.len; ++ i )
      out << s.p[i];
   return out;   // Always return the stream!
}
*/

std::ostream& operator << ( std::ostream& out, const string& s ) 
{
	for( char c : s )
	  out << c;
	return out; 
}

