#include "../headers/Control.h"
#include <iostream>
using namespace std;

int main (void) 
{
	bool run = true;
	Control yup;
	
	yup.setup();
	if (yup.isRunning())
		yup.run();
	else
		cout << "ERROR: Guilt cannot run right now." << endl;
	
	yup.quit();
}