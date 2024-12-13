#include <iostream>

int main()
{
	int value=1; /* value to test, starts at first (lowest) bit */
	for (int bit=0;bit<100;bit++) {
		std::cout<<"at bit "<<bit<<" the value is "<<value<<"\n";
		value=value+value; /* moves over by one bit */
		if (value==0) break;
	}
	return 0;
}

