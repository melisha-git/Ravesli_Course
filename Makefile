NAME = programm
NAME_TWO = programm_utils

EX126SRC = ex126.cpp Point3D.cpp Vector3D.cpp
EX129SRC = ex129.cpp
EX131SRC = ex131.cpp
133 = ex133.cpp

TEST11SRC = test11.cpp
TEST11_3SRC = test11_3.cpp
TEST9SRC = test9.cpp
TEST8SRC = test8.cpp
TEST8_3SRC = test8_3.cpp

ex126 :
	g++ $(EX126SRC) -o $(NAME)

ex129 :
	g++ $(EX129SRC) -o $(NAME) --std=c++11

ex131:
	g++ $(EX131SRC) -o $(NAME) --std=c++11

ex133:
	g++ $(133) -o $(NAME) --std=c++11

test8 :
	g++ $(TEST8SRC) -o $(NAME)
	g++ $(TEST8_3SRC) -o $(NAME_TWO)

test9 :
	g++ $(TEST9SRC) -o $(NAME)

test11 :
	g++ $(TEST11SRC) -o $(NAME)
	g++ $(TEST11_3SRC) -o $(NAME_TWO) --std=c++11

run:
	./programm
	@bash bashtest

clean:
	rm -rf $(NAME)
	rm -rf $(NAME_TWO)

.PHONY: test8 ex126 ex129 clean run