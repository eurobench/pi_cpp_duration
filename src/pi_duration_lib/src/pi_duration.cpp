#include <pi_duration_lib/pi_duration.h>
#include <pi_duration_lib/rapidcsv.h>

#include <vector>

PIDuration::PIDuration()
{
}

double PIDuration::computeDuration(std::string filename)
{
  rapidcsv::Document doc(filename, rapidcsv::LabelParams(0, -1), rapidcsv::SeparatorParams(','));
  std::vector<float> timestamps = doc.GetColumn<float>("timestamp");
  return timestamps[timestamps.size()-1]-timestamps[0];
}