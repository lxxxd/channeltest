# Download base image ubuntu 22.04
FROM ubuntu:22.04

# Informations about image
LABEL description="IneosTest"
LABEL version="1.0"

# Update Ubuntu Software repository and install dependencies
RUN apt-get update && apt-get install -y \
    sudo \
    apt-transport-https \
    curl \
    gnupg \
    zip \
    unzip \
    git \
    wget \
    build-essential
	
RUN apt-get update \
  && apt-get -y install build-essential \
  && apt-get install -y wget \
  && rm -rf /var/lib/apt/lists/* \
  && wget https://github.com/Kitware/CMake/releases/download/v3.24.1/cmake-3.24.1-Linux-x86_64.sh \
      -q -O /tmp/cmake-install.sh \
      && chmod u+x /tmp/cmake-install.sh \
      && mkdir /opt/cmake-3.24.1 \
      && /tmp/cmake-install.sh --skip-license --prefix=/opt/cmake-3.24.1 \
      && rm /tmp/cmake-install.sh \
      && ln -s /opt/cmake-3.24.1/bin/* /usr/local/bin

# Create workdir
WORKDIR /tmp

RUN git clone https://github.com/lxxxd/channeltest.git

#RUN cd $HOME/ineostest 
#RUN chmod +x cmake_installer_script.in
#RUN cmake_installer_script.in
