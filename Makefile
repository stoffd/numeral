CC=g++
PROGRAM_NAME=numeral

$(PROGRAM_NAME): main.o #main_section
	$(CC) -o $@ $^ -L/usr/lib/gtest -lpthread  -lgtest

main.o: main.cpp
	$(CC) -c $^

#auto_trgt
#auto_instr


clean:
	rm -f *.o
	rm -f $(PROGRAM_NAME)
