DEFAULT_FLAGS = -O3
DEBUG_FLAGS = -fsanitize=address -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual -Wno-suggest-attribute=format

STUDENT_PATH = ../student
LIST_NODE_PATH = ../student/list_node
LIST_PATH = ../student/list_node/list

%.out: %.o
	g++ $(DEFAULT_FLAGS) $^ -o $@
%_debug.out: %_debug.o
	g++ $(DEBUG_FLAGS) $^ -o $@

%.o: %.cpp
	g++ $(DEFAULT_FLAGS) -c $< -o $@
%_debug.o: %.cpp
	g++ $(DEBUG_FLAGS) -c $< -o $@

all: num_const_part.out num_const_part_debug.out

num_const_part.out: num_const_part.o main.o $(LIST_PATH)/list.o $(LIST_NODE_PATH)/list_node.o $(STUDENT_PATH)/student.o
num_const_part_debug.out: num_const_part_debug.o main_debug.o $(LIST_PATH)/list_debug.o $(LIST_NODE_PATH)/list_node_debug.o $(STUDENT_PATH)/student_debug.o

mrproper:
	rm -f *.o *.out
mrproper_student: $(STUDENT_PATH)
	rm -f $</*.o
mrproper_list_node: $(LIST_NODE_PATH)
	rm -f $</*.o
mrproper_list: $(LIST_PATH)
	rm -f $</*.o
mrproper_all: mrproper mrproper_student mrproper_list_node mrproper_list
