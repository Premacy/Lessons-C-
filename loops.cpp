#include <iostream>

int main(){
`
	// While Loop

	while( condition ){
		some code ...
	}

	// example 1
	int i = 0;
	while( i < 5 ){
		i = i + 1;
	}

	// example 2
	char c = 'n';
	while( c != 'y' ){
		std::cout << "Enter a symbol: ";
		std::cin >> c;
	}

	// For Loop
	for(counter; contidition; increment counter){
		// some code
	}

	// example 3
	const int N = 10;
	for(int i = 0; i < N; i++){
		std::cout << i << std::endl;
	}

	return 0;
}