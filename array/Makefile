OBJS = \
	  binary_search.o \

TESTCASE_OBJ = testcase.o

tests: $(OBJS) $(TESTCASE_OBJ)
		ld -o testcase $(OBJS) $(TESTCASE_OBJ)

clean:
		rm $(OBJS) $(TESTCASE_OBJ)
