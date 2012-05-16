#include<iostream>
#include<fstream>
#include<cmath>

int main()
{
	std::ofstream salida("julia_set.dat");
	double Xi1,Xi,Yi1,Yi,A=0.62;
	int indice,iterations;
	
	std::cout << "\nInitial condition (X0)?: ";
	std::cin >> Xi;
	std::cout << Xi;
	

	std::cout << "\nInitial condition (Y0)?: ";
	std::cin >> Yi;
	std::cout << Yi;
	
	std::cout << "\n Parameter (A=0.62)?: ";
	std::cin >> A;

	std::cout << "\nNumber of points?: ";
	std::cin >> iterations;
	std::cout << iterations << std::endl;

	salida << Xi << " " << Yi << "\n";

	for(indice=0;indice<iterations;indice++)
	{
		Xi1 = pow(Xi,2)-pow(Yi,2);
		Yi1 = 2*Xi*Yi+A;	
		
		salida << Xi1 << " " << Yi1 << "\n";

		std::cout << Xi1 << " " << Yi1 << "\n";

		Xi=Xi1;
		Yi=Yi1;
	}
	
}
