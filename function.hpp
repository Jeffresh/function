#ifndef FUNCTION_HPP_
#define FUNCTION_HPP_

class Function
{

public:

	struct
	{
		double x_,y_;
		Punto(double x = 0, double y = 0):x_(x),y_(y){}
	};


	Function(double x, double y);
	void Add(double x, double y);
	void del(double x);
	double value(double x)const;
	double min()const;
	double max()const;
	void trans(double w, double z);
	~Function();




private:


	Lista<Puntos> saltos;

};

#endif