#include<iostream>
#include<string>
using namespace std;

class HugeInt{
	friend ostream &operator<<( ostream &out,const HugeInt &num ){
		int i;
		for( i=0 ; (num.integer[i]==0)&&(i<=HugeInt::digit) ; i++ );
		if( i==HugeInt::digit ){
			out << 0;
		}
		else{
			for( ; i<HugeInt::digit ; i++ ){
				out << num.integer[i];
			}
		}
		return out;
	}

	friend istream &operator>>( istream &in,HugeInt &num ){
		string str;
		in >> str;
		int length = str.length();
		for( int i=HugeInt::digit-length ; i<HugeInt::digit ; i++ ){
			num.integer[i] = str[length-(HugeInt::digit-i)] - 48;
		}
		return in;
	}
	public:
		static const int digit = 30;
		int integer[digit];
		
		HugeInt( long value ){
			for( int i=0 ; i<digit ; i++ ){
				integer[i] = 0;
			}
			for( int j=digit-1 ; value!=0 && j>=0 ; j-- ){
				integer[j] = value % 10;
				value /= 10;
			}
		}

		HugeInt( const string &number ){
			for( int i=0 ; i<digit ; i++ ){
				integer[i] = 0;
			}
			int length = number.size();
			for( int j=digit-1,k=0 ; j<digit ; j++,k++ ){
				if( isdigit(number[k]) ){
					integer[j] = number[k] - '0';
				}
			}
		}

		HugeInt operator+( const HugeInt &add ) const{
			HugeInt temp;
			int carry = 0;
			for( int i=digit-1 ; i>=0 ; i-- ){
				temp.integer[i] = integer[i] + add.integer[i] + carry;
				if( temp.integer[i]>9 ){
					temp.integer[i] %= 10;
					carry = 1;
				}
				else{
					carry = 0;
				}
			}
			return temp;
		}



};

int main(){
	HugeInt x;
	HugeInt y(28825252);
	HugeInt z("314159265358979323846");
	HugeInt result;

	//cin >> x;
	//result = x + y;
	//cout << x << "+" << y << "=" << result << endl;

	//result = z - x;
	//cout << result << endl;
	
	cout << y << endl;
	cout << z << endl;

	return 0;
}
