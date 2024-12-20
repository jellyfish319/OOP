#TODO: Set your googletest directory path
GTEST_DIR = /home/jellyfish319/OOP/assignment/8th/googletest-main/googletest

CC=clang++
CXXFLAGS = -fsanitize=address --std=c++17
CPPFLAGS += -isystem $(GTEST_DIR)/include

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
				$(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

#TODO: Set your executable target
all : hw8

hw8: hw8.cc car.o car_builder.o part.o door.o roof.o wheel.o hyundai_parts_factory.o kia_parts_factory.o
	$(CC) --std=c++17 $^ -o $@

#TODO: Change 'util.h' and 'util.cc' to your source files
car.o : car.cc
	$(CC) --std=c++17 -c $^ -o $@

car_builder.o : car_builder.cc
	$(CC) --std=c++17 -c $^ -o $@

part.o : part.cc
	$(CC) --std=c++17 -c $^ -o $@

door.o : door.cc
	$(CC) --std=c++17 -c $^ -o $@

roof.o : roof.cc
	$(CC) --std=c++17 -c $^ -o $@ 

wheel.o : wheel.cc
	$(CC) --std=c++17 -c $^ -o $@ 

hyundai_parts_factory.o : hyundai_parts_factory.cc
	$(CC) --std=c++17 -c $^ -o $@ 

kia_parts_factory.o : kia_parts_factory.cc
	$(CC) --std=c++17 -c $^ -o $@ 

#TODO: Change 'util_test.cc' to your test file
test.o : test.cc $(GTEST_HEADERS)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) --std=c++17 -c $< -o $@

#TODO: Change 'util_test.o'and 'util.o' to your object targets
test: test.o car.o car_builder.o part.o door.o roof.o wheel.o hyundai_parts_factory.o kia_parts_factory.o gtest_main.a
	$(CC) $(CPPFLAGS) $(CXXFLAGS) --std=c++17 $^ -o $@

#TODO: Change 'main' and 'main_test' to your executable and test respectively
clean:
	 rm -f gtest.a gtest_main.a *.o hw8 test

gtest-all.o: $(GTEST_SRCS_) 
	$(CC) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) --std=c++17 -c\
		$(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CC) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) --std=c++17 -c\
		$(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

.PHONY: all clean
