g++ main.cpp;
./a.out < test.in > test.temp;
diff -b -B test.temp test.outputg;
