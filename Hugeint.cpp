#include <cctype> // isdigit function prototype
#include "Hugeint.h"
using namespace std;

HugeInt::HugeInt( long value ){
	for ( int i = 0; i < digits; i++ )
		integer[ i ] = 0;
	for ( int j = digits - 1; value != 0 && j >= 0; j-- ){
		integer[ j ] = value % 10;
		value /= 10;
	}
}

HugeInt::HugeInt( const string &number ){
	for ( int i = 0; i < digits; i++ )
		integer[ i ] = 0;
	int length = number.size();
	for ( int j = digits - length, k = 0; j < digits; j++, k++ )
		if ( isdigit( number[ k ] ) )
			integer[ j ] = number[ k ] - '0';
}

HugeInt HugeInt::operator+( const HugeInt &op2 ) const{
	HugeInt temp;
	int carry = 0;
	for ( int i = digits - 1; i >= 0; i-- ){
		temp.integer[ i ] = integer[ i ] + op2.integer[ i ] + carry;
		if ( temp.integer[ i ] > 9 ){
			temp.integer[ i ] %= 10;
			carry = 1;
		}
		else
			carry = 0;
	}
	return temp;
}

HugeInt HugeInt::operator+( const string &op2 ) const{
	return *this + HugeInt( op2 ); 
}

HugeInt HugeInt::operator-( const HugeInt & ln )const{
	HugeInt r;
	for( int i=0 ; i<HugeInt::digits ; i++ )
		r.integer[i] = integer[i] - ln.integer[i];
	for( int i=HugeInt::digits-1 ; i>=0 ; i-- ){
		if( r.integer[i]<0 ){
			r.integer[i-1]--;
			r.integer[i] += 10;
		}
	}
	return r;
}

ostream& operator<<( ostream &output , const HugeInt & num ){
	   int i;
		for ( i = 0; ( num.integer[ i ] == 0 ) && ( i <= HugeInt::digits ); i++ );
		if ( i == HugeInt::digits )
			output << 0;
		else
			for ( ; i < HugeInt::digits; i++ )
				output << num.integer[ i ];
		return output;
}

istream& operator>>( istream &input , HugeInt & num ){
	string str;
	input >> str;
	int length = str.size();
	for( int i=0 ; i<HugeInt::digits ; i++ )
		num.integer[i] = 0;
	for( int i=HugeInt::digits-length ; i<HugeInt::digits ; i++ )
		num.integer[i] = ( str[length-(HugeInt::digits-i)] - 48 );
	return input;
}
