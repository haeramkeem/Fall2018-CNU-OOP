OBJECTS = _main_termproject_oop2018.o board.o money.o player.o appcontroller.o appview.o

CC = g++
CFLAGS = -c
TARGET = gamefile

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

clean:
	rm -f $(OBJECTS) $(TARGET)

_main_termproject_oop2018.o: _main_termproject_oop2018.cpp
board.o: board.cpp
money.o: money.cpp
player.o: player.cpp
appcontroller.o: appcontroller.cpp
appview.o: appview.cpp