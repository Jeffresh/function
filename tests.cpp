#include "function.hpp"
#include<iostream>


int main()
{


	Function f(1,2); 
	f.add(2,5); f.add(4,2); 


	std::cout<<f;

	f.del(1);

	std::cout<<f;










}