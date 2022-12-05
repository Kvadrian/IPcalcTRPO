all:
	g++ -std=c++17 CPP/ip_calc.cpp -c ipcalc
	g++ -std=c++17 CPP/TRPO.cpp -c TRPO
	g++ -std=c++17 -o Course ipcalc.o TRPO.o
