CC = g++
CFLAGS = -c -g -Wall -std=c++11

seach_enginee : main.o text_analysis.o
				$(CC) main.o text_analysis.o -o $@
main.o        : main.cpp  text_analysis.h
				$(CC) $(CFLAGS) $< -o $@

text_analysis.o : text_analysis.cpp text_analysis.h
				$(CC) $(CFLAGS) $< -o $@


clear:
	rm -rf *.o seach_enginee