Debug:
	gcc sdl_test.cpp `pkg-config --cflags --libs sdl2 libavcodec libavformat` -o bin/Debug/standby
#	g++ standby.cpp `pkg-config --cflags --libs mlt++` -o bin/Debug/standby
