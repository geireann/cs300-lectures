PROGRAMS = add addin
ALLPROGRAMS = $(PROGRAMS) $(TESTQSPROGRAMS)

all: $(ALLPROGRAMS)

include ../common/rules.mk

%.o: %.cc $(BUILDSTAMP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEPCFLAGS) $(O) -o $@ -c $<

add: add.o addf.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

addin: addin.o hexdump.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(O) -o $@ $^

addf.o: addf.c $(BUILDSTAMP)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPCFLAGS) $(O) -fomit-frame-pointer -o $@ -c $<

clean:
	rm -rf $(ALLPROGRAMS) *.o $(DEPSDIR) qs.jarr qsml qs.cmi qs.cmo *.class

.PHONY: all clean
