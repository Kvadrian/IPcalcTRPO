all:
	g++ -std=c++17 TRPO.cpp -o TRPO
	g++ -std=c++17 ip_calc.cpp -lcppunit -o ipcalc
