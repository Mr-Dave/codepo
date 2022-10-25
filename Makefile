
CC=gcc
CXX      := -c++
CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror
LDFLAGS  := -L/usr/lib -lstdc++ -lm

OBJS = codepo.o
SRC=codepo

%.o: %.c $(DEPS)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

codepo: $(OBJS)
	$(CXX) -o codepo $(OBJS) $(LDLIBS)

