#if ! defined (CONTROL_H)
#define CONTROL_H

#include <iostream>

class Control {

	private:
	bool isrunning;

	public:
	Control();
	void readin();
	void run();
	
};

#endif