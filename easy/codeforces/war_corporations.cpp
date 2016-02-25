#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
	std::string base, key, s;

	std::cin>>base;
	std::cin>>key;
	
	int cnt = 0;
	std::string::size_type cur=0, beg=0;

	while (base.length() - beg >= key.length()){
		s = base[cur];
		if (key.compare(cur-beg, 1, s) == 0){

			if (cur-beg+1 == key.length()) {cnt++; cur++; beg=cur;}
			else cur++;
		} else{
			if (beg != cur){
				beg=cur;
			} else{
				beg++; cur++;
			}
		}
	}

	std::cout << cnt << std::endl;

	
	return 0;
}