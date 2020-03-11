/**
 * @file   pi_duration.cpp
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
 * @brief Class with a method which computes an example of a simple 
 * Performance Indicator (duration of a trial in this case)
 */

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