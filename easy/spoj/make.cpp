#include <iostream>
#include <cstdlib>
int main(int argc, char const *argv[])
{
	int t = 2000, max=20000, min=1;
	std::cout<<t<<"\n";
	srand (time(NULL));

	for (int i=0; i<t; ++i){
		int v = rand() % max + min;
		std::cout<<v<<"\n";
	}

	return 0;
}
