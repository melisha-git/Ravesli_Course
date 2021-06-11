NAME = programm

EX126SRC = ex126.cpp Point3D.cpp Vector3D.cpp

ex126 :
	g++ $(EX126SRC) -o $(NAME)

run:
	./programm

clean:
	rm -rf $(NAME)

.PHONY: ex126 clean run