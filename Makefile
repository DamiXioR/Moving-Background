main:
	g++ main.cc background.cc backgroundLoader.cc brick.cc -std=c++17
test:
	g++ gtestMain.cc backgroundLoader.cc backgroundLoader-test.cc background.cc background-test.cc brick.cc -lgtest -lgmock -pthread -std=c++17
