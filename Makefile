CC=g++
PROGRAM_NAME=numeral

$(PROGRAM_NAME): MatAlg.o EngAlg.o RusAlg.o Convert.o  main.o  
	$(CC) -o $@ $^ -L/usr/lib/gtest -lpthread  -lgtest



MatAlg.o: MatAlg.cpp 
	$(CC) -c -g $^


RusAlg.o:  RusAlg.cpp
	$(CC) -c -g $^

EngAlg.o:  EngAlg.cpp 
	$(CC) -c -g $^

Convert.o:  Convert.cpp
	$(CC) -c -g $^

main.o: main.cpp
	$(CC) -c -g $^


#auto_trgt
#auto_instr


clean:
	rm -f *.o
	rm -f $(PROGRAM_NAME)
