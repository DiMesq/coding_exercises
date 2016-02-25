#include <iostream>
#include <vector>
#include <string>

bool is_beaut(std::string s){

	if (s.compare(0, 1, "1") != 0) return false;
	else{
		for (std::string::size_type i = 1; i < s.length(); i++){
			if (s.compare(i, 1, "0") != 0) return false;
		}
		return true;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	std::cin >> n;

	std::string zeroes = "", special = "1", str;

	for (int i = 0; i<n; i++){
		std::cin >> str;

		if (is_beaut(str)){
			if (str.length() > 1) zeroes += str.substr(1);
		} else if (str.compare(0, 1, "0") == 0){special=""; zeroes="0"; break;}
		else{
			special = str;
		}
		
	}

	std::cout<<special << zeroes<<std::endl;
	return 0;
}