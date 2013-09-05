CC=g++
PROGRAM_NAME=numeral

$(PROGRAM_NAME): main.o MatAlg.o ConvertAlg.o 
	$(CC) -o $@ $^ -L/usr/lib/gtest -lpthread  -lgtest

main.o: main.cpp
	$(CC) -c -g $^


MatAlg.o: MatAlg.cpp 
	$(CC) -c -g $^

ConvertAlg.o: ConvertAlg.cpp 
	$(CC) -c -g $^

#auto_trgt
#auto_instr


clean:
	rm -f *.o
	rm -f $(PROGRAM_NAME)
