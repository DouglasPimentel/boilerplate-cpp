FROM ubuntu:latest

# Update apps on the base image
RUN apt-get -y update && apt-get install -y

# Install the gcc compiler
RUN apt-get -y install gcc

# Install the CMAKE
RUN apt-get update && apt-get -y install cmake

# Copy everything to the container
COPY . /boilerplate_cpp
WORKDIR /boilerplate_cpp

# Add permission to execute shell scripts 
RUN chmod +x /boilerplate_cpp/configure.sh
RUN chmod +x /boilerplate_cpp/entrypoint.sh

# Runs the installation when creating the containers
RUN /boilerplate_cpp/configure.sh

# Script run on docker run
ENTRYPOINT ["/boilerplate_cpp/entrypoint.sh"]