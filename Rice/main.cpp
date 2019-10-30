#include <gtest/gtest.h>
#include "computerVision.hpp"

using namespace cv;
using namespace std;

int main(int argc, char *argv[]) 
{
  testing::InitGoogleTest(&argc, argv);
  int code = RUN_ALL_TESTS();
  std::string dirName = "/home/oem/Practice/Rice/";
  std::vector<std::string> files= getFileList(dirName);

  ofstream myfile;
  myfile.open ("res.csv");
  for (int i = 0; i < files.size(); ++i) 
  {
    vector<double> length;
    vector<double> width;
    vector<double> area;
    Mat image = imread(string(dirName+files.at(i)));
  }

  myfile.close();

  return 0;
}