CC=clang
PROGRAMS = add addin mexplore mexplore-with-dynamic mexplore-string mexplore-uninitialized mexplore-array mexplore-struct mexplore-order.opt mexplore-order.noopt linked-list ptr-intro
ALLPROGRAMS = $(PROGRAMS) $(TESTQSPROGRAMS)

all: $(ALLPROGRAMS)

include ../common/rules.mk

CFLAGS += -Wno-unused-parameter

%.o: %.c $(BUILDSTAMP)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPCFLAGS) $(O) -o $@ -c $<

%.opt.o: %.c $(BUILDSTAMP)
	$(CC) $(CPPFLAGS) $(CFLAGS) -O3 $(DEPCFLAGS) -o $@ -c $<

%.noopt.o: %.c $(BUILDSTAMP)
	$(CC) $(CPPFLAGS) $(CFLAGS) -O0 $(DEPCFLAGS) -o $@ -c $<

mexplore mexplore-with-dynamic mexplore-string mexplore-array mexplore-uninitialized mexplore-struct linked-list: %: %.o hexdump.o
	$(CC) $(CFLAGS) $(LDFLAGS) -O0 -o $@ $^

mexplore-order.noopt: %.noopt: %.noopt.o hexdump.o
	$(CC) $(CFLAGS) $(LDFLAGS) -O0 -o $@ $^

mexplore-order.opt: %.opt: %.opt.o hexdump.o
	$(CC) $(CFLAGS) $(LDFLAGS) -O3 -o $@ $^

add: add.o addf.o hexdump.o
	$(CC) $(CFLAGS) $(LDFLAGS) $(O) -o $@ $^

addin: addin.o hexdump.o
	$(CC) $(CFLAGS) $(LDFLAGS) $(O) -o $@ $^

addf.o: addf.c $(BUILDSTAMP)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPCFLAGS) $(O) -fomit-frame-pointer -o $@ -c $<

ptr-intro: ptr-intro.o
	$(CC) $(CFLAGS) $(LDFLAGS) $(O) -o $@ $^

clean:
	rm -rf $(ALLPROGRAMS) *.o $(DEPSDIR)

.PHONY: all clean
