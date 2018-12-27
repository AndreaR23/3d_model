# include <iostream>
# include <string>
# include <vector>
# include <experimental/filesystem>
# include "readData.h"

namespace fs = std::experimental::filesystem;


int main()
{
	std::string path = "./obrazky";
	readData* data = new readData(path);
	std::cout << __cplusplus << std::endl;

	return 1;
}
