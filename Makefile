COMPILE.C=$(COMPILE.cc)
COMPILE.cc=$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
CXXFLAGS=-g3 -I headers 
CPPFLAGS= -Wall -Wextra -Wpedantic 
CXX= g++
OUTPUT_OPTION = -o $@
#Linking:
LINK.o = $(CC) $(LDFLAGS) $(TARGET_ARCH)
CC= g++

vpath %.cc sources
vpath %.h headers

#rules:

%: %.o 
	$(LINK.o) $(OUTPUT_OPTION) $^
# all of the files must be linked together, that means that $^ has to be applied, not
#only $<
%.o: %.c++
	$(COMPILE.C) $(OUTPUT_OPTION) $^

run: namespaces
	valgrind ./namespaces

namespaces: namespaces.o namespaces_add.o
namespaces_add.o: namespaces_add.cc
# .PHONY: namespaces
# namespaces: $(files)
namespaces.o: namespaces.cc namespaces.h
# c++: c++.o
# templates: templates.o
# templates.o: templates.cc templates.h
# c++.o: c++.cc c++.h

.INTERMEDIATE: *.o

.PHONY: depend #Now the file will be updated each time it is called.
depend: c++.cc
	g++ -I headers -M $(CPPFLAGS) $^ > $@
	more depend

.PHONY:clean
clean:
	rm -rf *.o c++