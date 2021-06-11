NAME = programm

EX126SRC = ex126.cpp Point3D.cpp Vector3D.cpp
EX129SRC = ex129.cpp

ex126 :
	g++ $(EX126SRC) -o $(NAME)

ex129 :
	g++ $(EX129SRC) -o $(NAME) --std=c++11

run:
	./programm

clean:
	rm -rf $(NAME)

.PHONY: ex126 ex129 clean run