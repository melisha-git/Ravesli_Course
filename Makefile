NAME = programm
NAME_TWO = programm_utils

EX126SRC = ex126.cpp Point3D.cpp Vector3D.cpp
EX129SRC = ex129.cpp
TEST8SRC = test8.cpp
TEST8_3SRC = test8_3.cpp

ex126 :
	g++ $(EX126SRC) -o $(NAME)

ex129 :
	g++ $(EX129SRC) -o $(NAME) --std=c++11

test8 :
	g++ $(TEST8SRC) -o $(NAME)
	g++ $(TEST8_3SRC) -o $(NAME_TWO)

run:
	./programm
	./programm_utils

clean:
	rm -rf $(NAME)

.PHONY: ex126 ex129 clean run