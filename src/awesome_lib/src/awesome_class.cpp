#include <awesome_lib/awesome_class.h>
#include <awesome_lib/rapidcsv.h>

#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip> 

Awesome::Awesome()
{
}

double Awesome::computeDuration(std::string filename)
{
  rapidcsv::Document doc(filename, rapidcsv::LabelParams(0, -1), rapidcsv::SeparatorParams(','));
  std::vector<float> timestamps = doc.GetColumn<float>("timestamp");
  return timestamps[timestamps.size()-1]-timestamps[0];
}

void Awesome::storeResult(std::string filename, double value)
{
  std::ofstream myfile;
  myfile.open (filename);
  myfile << std::fixed << std::setprecision(5) << "type: \'scalar\'\nvalue: [[" << value << "]]";
  myfile.close();
}