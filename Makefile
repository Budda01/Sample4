.PHONY: all clean test s21_matrix.a gcov_report clang

GCC = gcc -Wall -Werror -Wextra -std=c11

OS := $(shell uname -s)
TARGET=s21_calc_adelinan

ifeq ($(OS), Linux)
	LIB = -lcheck -lrt -lpthread -lsubunit -lm
	LEAK = valgrind --tool=memcheck --leak-check=yes
	OPEN = xdg-open
endif

ifeq ($(OS), Darwin)
	LIB = -lcheck
	OPEN = open
endif

all: 

install: 
	mkdir -p ../build
	cd front/adelinan_s21_SmartCalc && qmake && make && make clean && rm -rf Makefile && mv $(TARGET).app ../../build/$(TARGET).app
	cp -R ../build/$(TARGET).app ~/Desktop/$(TARGET).app

s21_SmartCalc:
	@$(GCC)  calculator/*.c -o s21_calc $(LIB)

test: clean
	@$(GCC) tests/*.c calculator/*.c $(LIB) -o s21_test
	@./s21_test

gcov_report : clean
	@$(GCC) calculator/*.c tests/*.c --coverage $(LIB) -o s21_test
	@./s21_test
	@mkdir ./report 
	@mv *.g* ./report
	@lcov -c -q -d ./report -o ./report/coverage.info
	@genhtml -q ./report/coverage.info -o ./report
	@$(OPEN) report/index.html

style: clean
	@cp ../materials/linters/.clang-format ./.clang-format
	clang-format -style=Google -n *.c
	clang-format -style=Google -n ./tests/*.c ./tests/*.h
	clang-format -style=Google -n *.h
	@rm .clang-format

clean :
	@rm -rf *.o *.a s21_calc s21_test *.gcda *.gcno coverage.info ./report tmp

leaks: test
	@$(LEAK) ./s21_test

