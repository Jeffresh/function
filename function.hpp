#ifndef FUNCTION_HPP_
#define FUNCTION_HPP_


#include "Lista.h"
#include <iostream>

struct Punto
	{
		double x_,y_;
		Punto(double x = 0, double y = 0):x_(x),y_(y){}
	};





class Function
{

public:

	

	Function(double , double );
	void add(double, double );
	void del(double);
	double value(double x)const;
	double min()const;
	double max()const;
	void trans(double w, double z);
	~Function();


	friend std::ostream& operator <<(std::ostream& os, const Function& f);




private:


	Lista<Punto> saltos{};

};



inline Function::Function(double x, double y) { saltos.insertar(Punto(x,y),saltos.primera());}

void Function::add(double x, double y)
{
	Lista<Punto>::posicion p = saltos.siguiente(saltos.primera());

	while(p != saltos.fin() && saltos.elemento(p).x_ < x)
		p = saltos.siguiente(p);

	if(p!= saltos.fin() && saltos.elemento(p).x_==x)
		saltos.elemento(p).y_ = y;
	else if(p!= saltos.fin())
			saltos.insertar(Punto(x,y), p);
		else
			saltos.insertar(Punto(x,y),p);



}

void Function::del(double x)
{
	Lista<Punto>::posicion p = saltos.siguiente(saltos.primera());

	while(p!= saltos.fin() && saltos.elemento(p).x_ < x)
		p = saltos.siguiente(p);


	if(p!=saltos.fin() && saltos.elemento(p).x_ == x)
		saltos.eliminar(p);
	else if(p!=saltos.fin())
			saltos.eliminar(saltos.anterior(p));

	// p = saltos.siguiente(p);

	 if(p!=saltos.fin() && p!=saltos.primera() && saltos.elemento(saltos.anterior(p)).y_ == saltos.elemento(p).y_)
		saltos.eliminar(p);



}

double Function::value(double x)const
{
	Lista<Punto>::posicion p = saltos.primera();
	while(p!=saltos.fin() && saltos.elemento(p).x_< x)
		p = saltos.siguiente(p);


	return (saltos.elemento(p).x_ == x) ? saltos.elemento(p).y_ : 0 ;

}

double Function::min()const
{
	Lista<Punto>::posicion p = saltos.primera();
	double min{saltos.elemento(p).y_};
	p = saltos.siguiente(p);


	while(p!= saltos.fin())
	{
		if(saltos.elemento(p).y_ < min)
			min = saltos.elemento(p).y_;

		p = saltos.siguiente(p);
	}


	return min;
}

double Function::max()const
{
	Lista<Punto>::posicion p = saltos.primera();
	double max{saltos.elemento(p).y_};
	p = saltos.siguiente(p);

	while(p!= saltos.fin())
	{	
		if(saltos.elemento(p).y_>max)
			max = saltos.elemento(p).y_;

		p = saltos.siguiente(p);
	}

	return max;
	
}


void Function::trans(double w, double z)
{

	Lista<Punto>::posicion p = saltos.primera();

	while(p!=saltos.fin())
	{
		saltos.elemento(p).x_ += w; saltos.elemento(p).y_ += z;
		p = saltos.siguiente(p);

	}
}

Function::~Function(){saltos.~Lista();}

std::ostream& operator <<(std::ostream& os, const Function& f)
{
	os<<"<| |";
	for(Lista<Punto>::posicion p = f.saltos.primera(); p!= f.saltos.fin(); p = f.saltos.siguiente(p))
	{
		os<<" Punto("<<f.saltos.elemento(p).x_<<" , "<<f.saltos.elemento(p).y_<<") | ";
	}

	os<<"|>"<<std::endl;

	return os;
}



#endif //FUNCTION_HPP_
