#include <iostream>
#include <cstdlib>

#define N 1000
#define MAX_N 1000000
int main(int argc, char const *argv[])
{
	std::string s = "999999.9996";
	srand (time(NULL));
	std::cout<<N<<std::endl;
	for (int i=0; i<N; i++){
		
		printf("%s\n", s.c_str());
	}
	return 0;
}
