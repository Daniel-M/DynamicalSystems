#include<iostream>
#include<fstream>
#include<cmath>

int main()
{
	std::ofstream salida("logistic-map.dat");
	double Xi1,Xi,A;
	int indice,iterations;
	
	std::cout << "\nInitial condition (X0)?: ";
	std::cin >> Xi;
	std::cout << Xi;

	std::cout << "\nParameter value (A)?: ";
	std::cin >> A;
	std::cout << A;

	std::cout << "\nNumber of points?: ";
	std::cin >> iterations;
	std::cout << iterations;

	salida << Xi << "\n";

	for(indice=0;indice<iterations;indice++)
	{
		Xi1=A*Xi*(1-Xi);
		salida << Xi1 << "\n";

		std::cout << Xi1 << std::endl;

		Xi=Xi1;
	}
	
}
