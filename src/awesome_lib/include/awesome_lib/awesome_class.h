#include <iostream>

class Awesome
{
  public:
    Awesome();
    double computeDuration(std::string filename);
    void storeResult(std::string filename, double value);
};