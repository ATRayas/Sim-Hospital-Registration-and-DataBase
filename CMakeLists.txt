cmake_minimum_required(VERSION 3.14)
project(Sim-Hospital-Registration-and-Database)

set(CMAKE_CXX_STANDARD 14)

add_executable(Patients Patient.cpp Alergy.h Alergy.cpp Patient.h OverArch.cpp OverArch.h gender.h Address.cpp Address.h)