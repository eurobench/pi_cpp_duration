/**
 * @file   pi_duration.h
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

#include <string>

class PIDuration
{
  public:
    PIDuration();

    /**
    * @brief Computes the duration of a trial from a file
    * @param filename name of the file which contains the data about the trial
    * @return duration of a trial
    */
    double computeDuration(std::string filename);
};