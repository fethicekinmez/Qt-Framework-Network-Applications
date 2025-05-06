# UDP Chat Example

A simple UDP-based chat application built with Qt Framework that allows users to communicate over localhost.

## Features

- Real-time messaging using UDP protocol
- User-definable names for chat participants
- Message broadcasting on localhost (port 2020)
- Simple and intuitive GUI interface

## Requirements

- Qt6 or Qt5
- C++17 compatible compiler
- CMake 3.16 or higher
- Qt Modules:
  - QtWidgets
  - QtNetwork

## Building the Project

1. Make sure you have Qt and CMake installed
2. Clone the repository
3. Create a build directory:
```bash
mkdir build && cd build
```
4. Run CMake:
```bash
cmake ..
```
5. Build the project:
```bash
cmake --build .
```

## Usage

1. Launch multiple instances of the application
2. For each instance:
   - Enter your desired name in the name field
   - Click "Set Name" button
   - Type your message in the message field
   - Click "Send" or press Enter to send the message
3. Messages will be broadcast to all instances running on port 2020

## Project Structure

- `main.cpp`: Application entry point
- `mainwindow.h/cpp`: Main window UI and logic
- `network.h/cpp`: UDP networking implementation
- `mainwindow.ui`: Qt Designer UI file
- `CMakeLists.txt`: CMake build configuration

## Network Details

- Protocol: UDP (User Datagram Protocol)
- Port: 2020
- Address: LocalHost
- Message Format: "Username : Message"