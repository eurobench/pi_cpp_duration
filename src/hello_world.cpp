#include <awesome_lib/awesome_class.h>

#include <filesystem>

int main (int argc, char *argv[])
{
  if(argc != 3)
  {
    std::cerr << "Wrong input parameters!:" << argc << std::endl;
    return 1;
  }

  std::filesystem::path file_in = std::filesystem::absolute(argv[1]);
  std::filesystem::path folder_out = std::filesystem::absolute(argv[2]);

  //check input parameters are good
  if (!std::filesystem::exists(file_in))
  {
    std::cerr << "Input file  " << file_in  << "  does not exist" << std::endl;
    return 1;
  }
  
  if (!std::filesystem::is_regular_file(file_in))
  {
    std::cerr << "Input file  " << file_in  << "  is not a file" << std::endl;
    return 1;
  }

  if (!std::filesystem::exists(folder_out))
  {
    std::cerr << "Ouput folder  " << folder_out  << " does not exist" << std::endl;
    return 1;
  }
    
  if (!std::filesystem::is_directory(folder_out))
  {
    std::cerr << "Ouput folder  " << folder_out  << " is not a directory" << std::endl;
    return 1;
  }

  std::string file_out = folder_out.string() + "/pi_duration.yaml";

  Awesome awesome;
  double duration = awesome.computeDuration(file_in.string());
  awesome.storeResult(file_out, duration);
  return 0;
}