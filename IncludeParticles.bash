## Program is designed to modify BESData_sorted.txt to inlude more particles
## NOTE: all pre-root programs should be entered here!!
##       these programs MUST reformat data to match BESData_sorted.txt!!


root -b -l -q BESData_InclPi0.cpp
root -b -l -q BESData_InclEta.cpp

##future programs
##root -b -l -q BESData_InclOmega.cpp
##root -b -l -q BESData_InclSIGMA.cpp
##root -b -l -q BESData_InclOthers.cpp
