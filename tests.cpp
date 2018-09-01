#include "function.hpp"


int main()
{


	Function f(1,2); 
	f.add(2,5); f.add(4,2), f.add(3,1),f.add(2.8,2);

	std::cout<<"Function: \n"<<f;


	std::cout<<"max of function: "<<f.max()<<std::endl; 
	std::cout<<"Min of function: "<<f.min()<<std::endl; 
	std::cout<<"Function's value on point 2.6: "<<f.value(2.6)<<std::endl; 



	f.del(2);

	std::cout<<"Function deleting jump on 2: \n"<<f;

	f.trans(1,1);

	std::cout<<"Function adding 1,1 to all parts: \n"<<f;










}