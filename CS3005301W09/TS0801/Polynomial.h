
class Polynomial {
public:
	Polynomial();
	Polynomial(double param[], int size);
	Polynomial(const Polynomial& poly);
	int mySize() const;

	double* param = new double[0];
	friend double evaluate(const Polynomial& poly, const double& var);

	void operator = (const Polynomial& poly);
	double operator [] (int index);
	friend Polynomial operator + (const Polynomial& poly1, const Polynomial& poly2);
	friend Polynomial operator + (const Polynomial& poly, const double& c);
	friend Polynomial operator + (const double& c, const Polynomial& poly);

	friend Polynomial operator - (const Polynomial& poly1, const Polynomial& poly2);
	friend Polynomial operator - (const Polynomial& poly, const double& c);
	friend Polynomial operator - (const double& c, const Polynomial& poly);

	friend Polynomial operator * (const Polynomial& poly1, const Polynomial& poly2);
	friend Polynomial operator * (const Polynomial& poly, const double& c);
	friend Polynomial operator * (const double& c, const Polynomial& poly);
private:
	int size = 0;
};

