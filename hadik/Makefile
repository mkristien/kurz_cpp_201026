
SRCS=$(shell find src | grep cpp)
OBJS=$(patsubst src/%.cpp, bin/%.o, $(SRCS))

hadik: $(OBJS)
	@echo Linkujem $@
	@gcc -o $@ $^

$(OBJS): bin/%.o : src/%.cpp
	@mkdir -p bin
	@echo Kompilujem $<
	@gcc -MT $@ -MMD -MP -MF bin/$*.d -o $@ -c -Iinc  $<

clean:
	rm *.exe
	rm -r bin

info:
	@echo SRCS=$(SRCS)
	@echo OBJS=$(OBJS)

-include $(OBJS:.o=.d)
