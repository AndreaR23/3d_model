#include "readData.h"
namespace fs = std::experimental::filesystem;
using namespace std;

readData::readData(string fileName, int sx, int sy, int sz) {
    this->fileName = fileName;
    this->sx = sx;
    this->sy = sy;
    this->sz = sz;
    totalSize = sx * sy * sz;
    data = new unsigned char[totalSize];
    //data.resize(totalSize);
    readFile();
}

readData::readData(string path)
{
	this->path = path;
	std::vector<string> images;
	images = getAllImagesInPath(path);
	loadImages(images);
}

std::vector<string> readData::getAllImagesInPath(string path)
{
	std::vector<string> images;
	for (auto &file : fs::directory_iterator(path)) {
		images.push_back(file.path().string());
	}
	return images;
}

void readData::loadImages(const std::vector<string>& images)
{
	sz = images.size();
	sf::Image image;
	image.loadFromFile(images[0]);
	sx = image.getSize().x;
	sy = image.getSize().y;
	data = new unsigned char[sx * sy * sz];
	int z = 0;
	unsigned char value;
	for (const auto &image_file : images) {
		std::cout << "Processing image: " << image_file << std::endl;
		image.loadFromFile(image_file);
		for (int x = 0; x < sx; x++) {
			for (int y = 0; y < sy; y++) {
				value = image.getPixel(x, y).r / 3 + image.getPixel(x, y).g / 3 + image.getPixel(x, y).b / 3;
				data[z * (sx * sy) + y * sx + x] = value;
			}
		}
		z++;
	}

}

void readData::readFile() {
    ifstream ifs(fileName.c_str(), ios::binary);
    ifs.seekg(0, ifs.beg);
    ifs.read((char*) &data[0], totalSize);
    ifs.close();
}
