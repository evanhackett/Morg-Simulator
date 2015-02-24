
#include "stdafx.h"
#include <iostream>
#include "Simulator.h"
#include "MorgFactory.h"
#include "MorgReader.h"
#include "FileReader.h"



using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	Simulator simulator;
	MorgFactory factory;
	MorgReader mr(&factory, new FileReader("input.txt"));

	if (mr.open()) {
		Morg * m;
		while (m = mr.readMorg()) {
			simulator.addMorg(m);
		}
		mr.close();
	}
	else {
		cout << "Failed to open reader!" << std::endl;
		return -1;
	}

	simulator.simulate(10);

	return 0;
}

