
SRCS = pointer1.cpp pointer2.cpp pointer3.cpp
CFLAGS = -Og
# Premen vsetky .cpp nazvy na rovnake .exe nazvy
EXES = $(patsubst %.cpp, %.exe, $(SRCS))

all: $(EXES)

# Pravidlo kompilacie pre vsetky .exe ciele
# a pouzitim automatickych premennych $@ (ciel, exe subor) a $< (zavislost, cpp subor)
%.exe : %.cpp
	@echo "kompilujem $< do $@"
	gcc -o $@ $< $(CFLAGS)

info:
	@echo "SRCS: $(SRCS)"
	@echo "EXES: $(EXES)"

clean:
	rm *.exe