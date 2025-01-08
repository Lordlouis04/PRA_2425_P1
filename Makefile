bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp ListArray.h

clean:
	rm -r *.o *.gch bin

bin/testListLinked: testListLinked.cpp ListLinked.h List.h
	mkdir -p bin
	g++ -o bin/testListLinked testListLinked.cpp ListLinked.h
Point2D.o: Point2D.h Point2D.cpp
	g++ -c Point2D.cpp
bin/testPoint2D: testPoint2D.cpp Point2D.o
	g++ -c testPoint2D.cpp
	mkdir -p bin
	g++ -o bin/testPoint2D testPoint2D.o Point2D.o
Shape.o: Shape.h Shape.cpp
	g++ -c Shape.cpp
bin/testCircle: testCircle.cpp Circle.o Shape.o Point2D.o
	g++ -c testCircle.cpp
	mkdir -p bin
	g++ -o bin/testCircle testCircle.o Circle.o Shape.o Point2D.o
bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.h
bin/testRectangle: testRectangle.cpp Rectangle.o Shape.o Point2D.o
	g++ -c Rectangle.cpp
	mkdir -p bin
	g++ -o bin/testRectangle testRectangle.cpp Rectangle.o Shape.o Point2D.o
bin/testSquare: testSquare.cpp Square.o Rectangle.o Shape.o Point2D.o
	g++ -c Square.cpp
	
	make Point2D.o
	make Shape.o
	g++ -c Rectangle.cpp
	
	mkdir -p bin
	g++ -o bin/testSquare testSquare.cpp Square.o Rectangle.o Shape.o Point2D.o	
bin/testDrawing: testDrawing.cpp Drawing.o Square.o Rectangle.o  Circle.o Shape.o Point2D.o 
	g++ -c Drawing.cpp
	g++ -c Square.cpp
	g++ -c Rectangle.cpp
	g++ -c Shape.cpp
	g++ -c Circle.cpp
	g++ -c Point2D.cpp
	g++ -o bin/testDrawing testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o
