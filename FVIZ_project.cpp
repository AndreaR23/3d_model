# include <iostream>
# include <string>
# include <vector>
# include <experimental/filesystem>
# include "readData.h"

namespace fs = std::experimental::filesystem;


int main()
{
	std::string path = "/home/ajuska/CLionProjects/projekt_3D/obrazky";
	readData* data = new readData(path);
	std::cout << __cplusplus << std::endl;

    float a = data->get(10, 10, 10);
    std::cout << a <<std::endl;
	return 1;
}
