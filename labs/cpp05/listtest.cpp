
#include "listtest.h"

#include <random>
#include <chrono>
#include <algorithm>
#include <vector>

void listtest::sort_assign( std::list< std::string > & v )
{
	for(auto i = v.begin(); i != v.end(); ++i)
	{
		for(auto j = v.begin(); j != i; ++j)
		{
			if(*j > *i)
			{
				std::string s = *j;
				*j = *i;
				*i = s;
			}
		}
	}
}

void listtest::sort_move( std::list< std::string > & v )
{
	for(auto i = v.begin(); i != v.end(); ++i)
	{
		for(auto j = v.begin(); j != i; ++j)
		{
			if(*j > *i)
			{
				std::swap( *j, *i );
			}
		}
	}
}

std::ostream&
operator << ( std::ostream& out, const std::list< std::string > & l)
{
	out << "{";
	for(auto i = l.cbegin(); i != l.cend(); ++i)
	{
		if(i != l.begin())
			out << ",";
		out << *i << " ";
	}
	out << "}" << "\n";
	return out;
}



