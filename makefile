wbc: wbc.cc
	${CXX} wbc.cc `pkg-config --libs --cflags opencv4` -o wbc
