CC					= g++
CCLINK			= g++
LIBS				=
CCOPTIONS		= -Wall -pedantic -g
LDOPTIONS		=
HDRS				= bank_account.h test_bank_account.h shortcut.h

TEST = test_bank_account
PROGRAM = bank_account

TESTOBJECT = bank_account_test_driver.o
MAINOBJECT = bank_account_main_driver.o
OBJS = shortcut.o bank_account.o test_bank_account.o

DOXY            = /Applications/Doxygen/Doxygen.app/Contents/Resources/doxygen

all: $(PROGRAM)
	./$(PROGRAM)

$(TEST): $(OBJS) $(TESTOBJECT)
	$(CCLINK) -o $@ $(LDOPTIONS) $(OBJS) $(TESTOBJECT)

$(PROGRAM): $(OBJS) $(MAINOBJECT)
	$(CCLINK) -o $@ $(LDOPTIONS) $(OBJS) $(MAINOBJECT)

.PHONY: clean cleanall doxy test setsample setassignment definesample defineassignment assignmentfolder

clean:
	rm -f $(PROGRAM) $(TEST) $(TESTOBJECT) $(MAINOBJECT) $(OBJS)

cleanall:
	rm -f $(PROGRAM) $(TEST) $(TESTOBJECT) $(MAINOBJECT) $(OBJS) index.html
	rm -R html

doxy:
	$(DOXY)
	ln -s html/index.html index.html

test: $(TEST)
	./$(TEST)

#sets project as sample solution
setsample:
	cp bank_account.cpp.sample bank_account.cpp
	cp bank_account.h.sample bank_account.h

#sets project as assignment
setassignment:
	cp bank_account.cpp.assignment bank_account.cpp
	cp bank_account.h.assignment bank_account.h

# defines current state of project as sample solution
definesample:
	cp bank_account.cpp bank_account.cpp.sample
	cp bank_account.h bank_account.h.sample

# defines current sate of project as assignment
defineassignment:
	cp bank_account.cpp bank_account.cpp.assignment
	cp bank_account.h bank_account.h.assignment

# creates a folder which can serve as a publishable assignment
assignmentfolder:
	make setsample
	make doxy
	make setassignment
	mkdir ../assignment
	cp -R * ../assignment
	rm ../assignment/*.sample
	rm ../assignment/*.assignment
	make cleanall

%.o: %.cpp $(HDRS)
	$(CC) $(CCOPTIONS) -c $<
