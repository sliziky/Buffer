#include <algorithm>
#include <exception>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

#include "Buffer.h"

size_t count_of( const std::string& str, char to_find ) {
	return std::count( str.begin(), str.end(), to_find );
}

int main() {
	Buffer buffer;
	std::string line;
	for ( ;; ) {
		std::getline( std::cin, line );
		if ( line == "exit" ) { 
			return 0; 		
		} else if ( line == "print" ) { 
			buffer.print(); 
		} else if ( line == "get" ) { 
			buffer.get(); 
		} else {
			auto colon_pos = line.find( ":" );
			try {
				if ( colon_pos == std::string::npos || count_of(line, ':') != 1) throw std::exception("");
				auto key = std::stoi( line.substr( 0, colon_pos ) );
				auto priority = std::stoi( line.substr( colon_pos + 1, std::string::npos ) );
				buffer.insert( { key, priority } );
			}
			catch ( const std::exception& exc ) {
				std::cout << "Expected one of print / get / exit / NUMBER:NUMBER\n";
			}
		}
	}
}
 
