all: $(PROBLEM)_judge

%: %.c ../include/corr.h
	gcc -Wall -pedantic -std=gnu99 -O2 -I ../include -o $@ $< $(LDFLAGS) 

%: %.cc ../include/corr.h
	g++ -Wall -pedantic -O2 -I ../include -o $@ $< $(LDFLAGS) 
