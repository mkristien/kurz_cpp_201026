
SRCS = argumenty.cpp nasobky.cpp pole_int.cpp pole_double.cpp

# Premen vsetky .cpp nazvy na rovnake .exe nazvy
EXES = $(patsubst %.cpp, %.exe, $(SRCS))

all: $(EXES)

# Pravidlo kompilacie pre vsetky .exe ciele
# a pouzitim automatickych premennych $@ (ciel, exe subor) a $< (zavislost, cpp subor)
%.exe : %.cpp
	@echo "kompilujem $< do $@"
	gcc -o $@ $<

info:
	@echo "SRCS: $(SRCS)"
	@echo "EXES: $(EXES)"

clean:
	rm *.exe