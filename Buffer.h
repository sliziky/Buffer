#include <iostream>
#include <vector>
#include <algorithm>
class Buffer {
	using item = std::pair<int, int>;

public:
	void get() const {
		if ( _buffer.empty() ) {
			std::cout << "Empty buffer\n";
			return;
		}
		std::cout << _buffer[ 0 ].first << '\n';
	}

	void print() {
		if ( _buffer.empty() ) {
			std::cout << "Empty buffer\n";
			return;
		}
		std::cout << *this;
		_buffer.clear();
	}

	void insert( const item& i ) {
		auto lower_b = std::lower_bound( _buffer.begin(), _buffer.end(), i,
										[]( const item& x, const item& y ) { return x.second >= y.second; } );
		_buffer.insert( lower_b, i );
	}

private:
	std::vector< item > _buffer;
	friend std::ostream& operator<<( std::ostream& os, const Buffer& buffer );
};


inline std::ostream& operator<<( std::ostream& os, const Buffer& buffer ) {
	for ( const auto& item : buffer._buffer ) {
		os << item.first;
	}
	os << '\n';
	return os;
}
