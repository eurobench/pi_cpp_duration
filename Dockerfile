# Get the GCC preinstalled image including cmake
FROM rikorose/gcc-cmake

RUN apt-get update \
    && apt-get install -y less \
    && apt-get install -y wget \
    && rm -rf /var/lib/apt/lists/* \
    && apt-get clean

# create user account, and create user home dir
RUN useradd -ms /bin/bash pi_runner

WORKDIR /home/pi_runner
# cp source files
RUN mkdir /home/pi_runner/src
COPY src /home/pi_runner/src/

# Building process
RUN mkdir /home/pi_runner/build
RUN cd /home/pi_runner/build && cmake ../src && make && make install

ADD run_pi /home/pi_runner

# set the user as owner of the copied files.
RUN chown -R pi_runner:pi_runner /home/pi_runner/

USER pi_runner
WORKDIR /home/pi_runner