#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>
#include <string>
using namespace std;

class HugeInt
{
	friend ostream &operator<<( ostream & , const HugeInt & );
	friend istream &operator>>( istream & , HugeInt & );

	public:
		static const int digits = 30; // maximum digits in a HugeInt
		HugeInt( long = 0 ); // conversion/default constructor
		HugeInt( const string & ); // conversion constructor
		HugeInt operator+( const HugeInt & ) const;            
		HugeInt operator+( const string & ) const; 
		HugeInt operator-( const HugeInt & ) const;
	private:
		short integer[ digits ];
};

#endif
