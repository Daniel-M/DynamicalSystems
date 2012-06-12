#include<iostream>
#include<fstream>
#include<cmath>
// MathGL Headers
#include<mgl/mgl.h>
#include <mgl/mgl_zb.h>
#include <mgl/mgl_eps.h>
#include <mgl/mgl_data.h>


int main()
{

	std::ofstream salida("ikeda_map.dat");
	double Xi1,Xi,Yi1,Yi,th;
	double alfa,beta,gama,mu;
	int indice,iterations;
	
	std::cout << "\nInitial condition (X0=0)?: ";
	std::cin >> Xi;
	std::cout << Xi;
	

	std::cout << "\nInitial condition (Y0=0)?: ";
	std::cin >> Yi;
	std::cout << Yi;
	
	std::cout << "\n Parameter (alpha=6)?: ";
	std::cin >> alfa ;
	std::cout << alfa;

	std::cout << "\n Parameter (beta=0.4)?: ";
	std::cin >> beta ;
	std::cout << beta;
		
	std::cout << "\n Parameter (gamma=1)?: ";
	std::cin >> gama ;
	std::cout << gama;

	std::cout << "\n Parameter (mu=0.9)?: ";
	std::cin >>  mu ;
	std::cout << mu;

	std::cout << "\nNumber of points?: ";
	std::cin >> iterations;
	std::cout << iterations << std::endl;

	salida << Xi << "\t" << Yi << "\n";

	for(indice=0;indice<iterations;indice++)
	{

		th  = beta - alfa/(1+pow(Xi,2)+pow(Yi,2));
		Xi1 = gama + mu*(Xi*cos(th)-Yi*sin(th));
		Yi1 = mu*(Xi*sin(th)+Yi*cos(th));	

		salida << Xi1 << "\t" << Yi1 << "\n";

//		std::cout << Xi1 << "\t" << Yi1 << "\n";
		
		Xi=Xi1;
		Yi=Yi1;
	}

// Here one uses MathGL for generate Graphics!

    char parametros[100];
    char parametroa[20];
    char parametrob[20];
    char parametrog[20];
    char parametrou[20];
    char parametrop[30];
    
//     sprintf(parametros,"Ikeda Map Parameters\n a=%.3lfm\n b=%.3lf\n g=%.3lf\n u=%.3lf",alfa,beta,gama,mu);
    	
	sprintf(parametroa,"\\alpha = %.3lf",alfa);
	sprintf(parametrob,"\\beta = %.3lf",beta);
	sprintf(parametrog,"\\gamma = %.3lf",gamma);
	sprintf(parametrou,"\\mu = %.3lf",mu);
	sprintf(parametrop,"Points = %i",iterations);
    
    mglGraph *gr = new mglGraphZB;


	mglData y("ikeda_map.dat");
	mglData xdat=y.SubData(0), ydat=y.SubData(1);
	
	gr->SetSize(1200,900);
	gr->Transparent=false;
	gr->XRange(xdat);	gr->YRange(ydat); // for v.1.*
//gr->SetRanges(xdat,ydat); // for v.2.*
	gr->Box();
	
	gr->Alpha(false);
	gr->Light(true);
	gr->SetMarkSize(0.0005);
	gr->Title("Ikeda Map");
	
// 	gr->AddLegend(parametros,"b");
	
	gr->AddLegend(parametrou," ");
	gr->AddLegend(parametrog," ");
	gr->AddLegend(parametrob," ");
	gr->AddLegend(parametroa," ");
	gr->AddLegend(parametrop," ");
	gr->AddLegend("Ikeda Map Parameters","");
	gr->Legend(0,0,2.3);
	
	gr->Plot(xdat,ydat,"r#o "); 
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	gr->WritePNG("ikeda-mgl.png");
	delete gr;
    return 0;
/*	
    mglGraph *greps = new mglGraphPS;

	
	greps->SetSize(1200,900);
	greps->Transparent=false;
	greps->XRange(xdat);	greps->YRange(ydat); // for v.1.*
//gr->SetRanges(xdat,ydat); // for v.2.*
	greps->Box();

	greps->Alpha(true);
	greps->Plot(xdat,ydat,"r. "); 
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    greps->WriteEPS("ikeda-mgl.eps");
	delete greps;
    return 0;*/
	
}
