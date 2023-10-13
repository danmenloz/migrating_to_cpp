FROM ubuntu:latest

ENV REFRESHED_AT 2023-03-24

# Download Linux support tools
RUN apt-get update && \
    apt-get clean &&  \
    apt-get install -y autoconf && \
    apt-get install -y libtool && \ 
    apt-get install -y \
        build-essential \
        wget \
        curl \
        git  \
    python3 python-setuptools python3 python3-pip python3-setuptools

# Set up a development tools directory
WORKDIR /home/dev
ADD . /home/dev

# Install CMake
RUN apt install -y cmake

# Install the arm toolchain and C++ support
RUN apt-get install -y --no-install-recommends gcc-arm-none-eabi
ENV PATH $PATH:/home/dev/gcc-arm-none/bin
RUN apt-get install -y --no-install-recommends libstdc++-arm-none-eabi-newlib
#RUN apt-get install -y --no-install-recommends libnewlib-arm-none-eabi

# Download Static analyzer and formatting tools
RUN apt-get install -y clang clang-tools clang-format clang-tidy cppcheck
RUN pip install cpplint

# Metric analyzers and code coverage tools
RUN apt-get install -y pmccabe 
RUN pip install metrixpp
RUN pip install gcovr

# Install the debugging tools
RUN apt-get install -y --no-install-recommends stlink-tools

# Install doxygen and graphviz for documentation
RUN apt-get install -y doxygen graphviz

# Clean up
RUN apt-get clean all

# Install and configure CppUTest
WORKDIR /home/cpputest

RUN git clone --depth 1 --branch v4.0 https://github.com/cpputest/cpputest.git .
RUN autoreconf . -i
RUN ./configure
RUN make install

ENV CPPUTEST_HOME=/home/cpputest

# Set our working directory back to app
WORKDIR /home/app
