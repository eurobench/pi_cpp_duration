/**
 * @file   pi_main.cpp
 * @author Alfonso Domínguez <alfonso.dominguez@tecnalia.com>
 * @date   2020
 *
 * Copyright 2020 Tecnalia Research & Innovation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @brief Class which contains the main. It takes two input arguments (the 
 * name of the file which contains tha data of a trial and the name of the 
 * folder in which the results will be stored), calls a method of the 
 * library which computes the metrics and stores the result in the folder 
 * provided as parameter
 */

#include <pi_duration_lib/pi_duration.h>

#include <filesystem>
#include <iostream>
#include <fstream>
#include <iomanip> 

void storeResult(std::string filename, double value)
{
  std::ofstream myfile;
  myfile.open (filename);
  myfile << std::fixed << std::setprecision(5) << "type: \'scalar\'\nvalue: [[" << value << "]]";
  myfile.close();
}

int main (int argc, char *argv[])
{
  if(argc != 3)
  {
    std::cerr << "Wrong number of input parameters! The app needs 2 (an input file and an output folder) and you provide " << argc << std::endl;
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

  PIDuration pi;
  double duration = pi.computeDuration(file_in.string());
  storeResult(file_out, duration);
  return 0;
}