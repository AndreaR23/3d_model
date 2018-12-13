#include <fstream>
#include <vector>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "stdio.h"
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
using namespace std;

class readData {
public:
    readData(string fileName, int sx, int sy, int sz);
	readData(string path);
    inline unsigned char get(int x, int y, int z){
        return data[z * (sx * sy) + y * sx + x];
    }
    inline void put(int x, int y, int z, unsigned char value) {
        data[z * (sx * sy) + y * sx + x] = value;
    }

	const int &getXdim() const {
		return sx;
	}
	const int &getYdim() const {
		return sy;
	}
	const int &getZdim() const {
		return sz;
	}


private:
	string path;
	std::vector<string> getAllImagesInPath(string path);
	void loadImages(const std::vector<string> &images);
    void readFile();
    string fileName;
    //vector<unsigned char> data;
    unsigned char* data;
    int totalSize;
    int sx, sy, sz;
};
