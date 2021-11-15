CFLAGS+=-Wall -Wextra -pedantic -O2
LDLIBS+=-lm

dbfloat:

.PHONY: clean
clean:
	$(RM) dbfloat
