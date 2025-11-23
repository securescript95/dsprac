CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

all: sll dll cll stack queue bst avl

sll: singly_linked_list.cpp
	$(CXX) $(CXXFLAGS) $< -o sll

dll: doubly_linked_list.cpp
	$(CXX) $(CXXFLAGS) $< -o dll

cll: circular_linked_list.cpp
	$(CXX) $(CXXFLAGS) $< -o cll

stack: stack_evaluation.cpp
	$(CXX) $(CXXFLAGS) $< -o stack_eval

queue: queue.cpp
	$(CXX) $(CXXFLAGS) $< -o queue

bst: bst.cpp
	$(CXX) $(CXXFLAGS) $< -o bst

avl: avl.cpp
	$(CXX) $(CXXFLAGS) $< -o avl

clean:
	rm -f sll dll cll stack_eval queue bst avl
