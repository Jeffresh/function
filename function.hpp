#ifndef FUNCTION_HPP_
#define FUNCTION_HPP_

class Function
{

public:

	struct Punto
	{
		double x_,y_;
		Punto(double x = 0, double y = 0):x_(x),y_(y){}
	};


	Function(double , double );
	void Add(double, double );
	void del(double);
	double value(double x)const;
	double min()const;
	double max()const;
	void trans(double w, double z);
	~Function();




private:


	Lista<Puntos> saltos;

};



inline Function::Function(double x, double y) { saltos.insertar(Punto(x,y),saltos.primera());}

void Function::dad(double x, double y)
{
	Lista<Punto>::posicion p = saltos.primera();

	while(p != saltos.fin() && saltos.elemento(p).x_ < x)
		p = p.siguiente(p);

	if(p!= saltos.fin() && saltos.elemento(p).x_==x)
		saltos.elemento(p).y_ = y;
	else if(p!= saltos.fin())
			saltos.insertar(Punto(x,y), p);



}

void Function::del(double x)
{
	Lista<Punto>::posicion p = saltos.primera();

	while(p!= saltos.fin() && saltos.elemento(p).x_ < x)
		p = p.siguiente(p);


	if(p!=saltos.fin() && p!=saltos.primera() && saltos.elementos)
		saltos.eliminar(saltos.anterior(p));

	if(p!=saltos.fin() && p!=saltos.primera() && saltos.elemento(saltos.anterior(p)).y_ == saltos.elemento(p).y_)
		saltos.eliminar(p);



}

double Function::value(double x)
{
	Lista<Punto>::posicion p = saltos.primera();
	while(p!=saltos.fin() && saltos.elemento().x_< x)
		p = saltos.siguiente(p);




}



#endif //FUNCTION_HPP_
