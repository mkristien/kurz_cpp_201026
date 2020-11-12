
# SRCS = faktorial.cpp fibonacii.cpp heap.cpp
# vyfiltruj subory ktore maju v nazve cpp a nemaju v nazve parne
SRCS = $(shell find . | grep cpp | grep -v parne)
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