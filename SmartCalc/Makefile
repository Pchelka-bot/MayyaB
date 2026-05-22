GTESTFLAGS = -lgtest
CC = g++ -g -std=c++17 -lm
GCOV = -fprofile-arcs -ftest-coverage


all: clean install test

polka.o:
	$(CC) $(GTESTFLAGS) polka.cpp -o polka.o
	
test.o:
	$(CC) $(GTESTFLAGS) test.cpp -o test.o


tests:
	g++ -g -std=c++17 -lm test.cpp polka.cpp -lgtest -o test
	./test


build:
	mkdir build
	cd ./build/ && qmake ../ && make
	
install: build
	mkdir $(HOME)/SmartCalc/
	cp -rf build/Smartcalc.app $(HOME)/SmartCalc/
	make clean


clean:
	rm -rf *.o  *.gc* report *.a test build SmartCalc gcov_report *.info

uninstall:
	rm -rf $(HOME)/SmartCalc/


polka.a: polka.o
	ar rcs polka.a polka.o


valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --log-file=log.txt ./gcov_report

leaks:
	CK_FORK=no leaks --atExit -- ./gcov_report

format:
	clang-format -n polka.h polka.cpp main*.cpp main*.h

cppcheck:
	cppcheck --language=c++ --std=c++17 --enable=all --suppress=missingInclude --suppress=unusedFunction --suppress=useStlAlgorithm  *.h *.cpp

gcov_report:
	g++ -g -std=c++17 $(GCOV) -lm test.cpp polka.cpp -lgtest -o gcov_report
	./gcov_report
	rm -f *test.gcda *test.gcno
	lcov -t "gcov_report" -o gcov_report.info -c -d .
	genhtml -o report gcov_report.info
	open ./report/index.html


test:
	g++ -g -std=c++17 -lm test.cpp polka.cpp -lgtest -o gcov_report
	./gcov_report


dvi:
	open dvi.html

dist: 
	rm -rf build
	mkdir SmartCalc
	mkdir SmartCalc/src
	cp Makefile *.h *.cpp *.ui *.pro *.pro.user *.html SmartCalc/src/
	tar -cvzf SmartCalc.tar.gz SmartCalc
	mv SmartCalc.tar.gz $(HOME)/
	rm -rf SmartCalc/
