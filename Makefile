all: luTimer

luTimer: luTimer.cpp
	g++ -o luTimer `pkg-config --cflags --libs libnotify` luTimer.cpp

