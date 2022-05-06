objs = main.o kbd.o command.o display.o \
	insert.o search.o files.o utils.o

# This is the default goal.
edit: $(objs)
	cc -o edit $(objs)

# NOTE: make has an implicit rule that runs cc -c x.c and also adds the .c file
# 		as a depdency. hence, such commands can be omitted to simplify the rules.
main.o: defs.h
kbd.o: defs.h command.h
command.o: defs.h command.h
display.o: defs.h buffer.h
insert.o: defs.h buffer.h
search.o: defs.h buffer.h
files.o: defs.h buffer.h command.h
utils.o: defs.h

# This is a PHONY target since it has not target nor depedencies - it is an action
.PHONY: clean
clean:
	rm edit $(objs)
