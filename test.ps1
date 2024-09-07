clear
echo "Running Test"
g++ -Wall -g classtest.cpp -o testProgram -L/ucrt64/lib -lncursesw 
./testProgram