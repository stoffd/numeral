CC=g++
PROGRAM_NAME=numeral

$(PROGRAM_NAME): Numeral.o Algo.o EngAlg.o RusAlg.o Convert.o  main.o  
	$(CC) -o $@ $^ -L/usr/lib/gtest -lpthread  -lgtest 


Numeral.o:  Numeral.cpp
	$(CC) -c -g -DVELALG_TEST $^

Algo.o: Algo.cpp 
	$(CC) -c -g -DVELALG_TEST $^


RusAlg.o:  RusAlg.cpp
	$(CC) -c -g -DVELALG_TEST $^

EngAlg.o:  EngAlg.cpp 
	$(CC) -c -g -DVELALG_TEST $^

Convert.o:  Convert.cpp
	$(CC) -c -g -DVELALG_TEST $^

main.o: main.cpp
	$(CC) -c -g -DVELALG_TEST $^


#auto_trgt
#auto_instr


clean:
	rm -f *.o
	rm -f $(PROGRAM_NAME)
