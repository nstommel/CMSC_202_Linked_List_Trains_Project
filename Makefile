CFLAGS = -std=c++98 -Wall -ansi -gstabs -c

all: mytest.out station_test.out

station_test.out: TrainCar.o Time.o Train.o TrainStation.o station_test.o
	g++ -gstabs TrainCar.o Time.o Train.o TrainStation.o station_test.o -o station_test.out

mytest.out: TrainCar.o Time.o Train.o TrainStation.o mytest.o 
	g++ -gstabs TrainCar.o Time.o Train.o TrainStation.o mytest.o -o mytest.out

station_test.o: station_test.cpp TrainStation.h Train.h TrainCar.h Time.h
	g++ $(CFLAGS) station_test.cpp

mytest.o: mytest.cpp Time.h TrainCar.h Train.h
	g++ $(CFLAGS) mytest.cpp

TrainCar.o: TrainCar.cpp TrainCar.h
	g++ $(CFLAGS) TrainCar.cpp

Time.o: Time.cpp Time.h
	g++ $(CFLAGS) Time.cpp

Train.o: Train.cpp Train.h TrainCar.h Time.h
	g++ $(CFLAGS) Train.cpp

TrainStation.o: TrainStation.cpp TrainStation.h Train.h TrainCar.h Time.h
	g++ $(CFLAGS) TrainStation.cpp

clean:
	rm -f *~ *.o *.out

submit:
	cp Train.h Train.cpp TrainCar.cpp Time.h Time.cpp mytest.cpp ~/cs202proj/proj3/
