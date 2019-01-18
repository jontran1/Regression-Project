//============================================================================
// Name        : Regression.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <random>
#include <chrono>

using namespace std;

int main() {

	float Bo = 1.5153826319218533;
	float B1 = 1.8317853546849383;
	float Jons_SD = 1.7050382335228091;

	std::default_random_engine generator;
 	srand (1352795693);



	std::normal_distribution<float> distribution(0,Jons_SD);
	double x = 0;


	float number;
	float x_average = 0;
	float y_average = 0;
	int n = 100;
	float x_holder [100];
	float y_holder [100];

	float x_sample [10];
	float y_sample [10];
	float x_sameple_average = 0;
	float y_sameple_average = 0;


	int sample_index = 0;

	double y = 0;
   	 	for(int i = 0; i < n; i++){
  	 		number = distribution(generator);
  	 		x = ((double) rand() / (RAND_MAX));
   	 		y =  Bo + B1*(x) +number;
   	 		x_holder[i]=x;
   	 		y_holder[i]=y;


   	 		//Random numbers to create a sample of ten.
			if((i+1)%10==0 && i != 0){
				x_sample[sample_index] = x;
				y_sample[sample_index] = y;
				x_sameple_average+=x;
				y_sameple_average+=y;
				++sample_index;
			}

   	 		cout<<x<<"		"<<y<<endl;
   	 		x_average+=x;
   	    	y_average+=y;
   	    	if(i==n-1){
   	    		x_average/=n;
   	    		y_average/=n;
   	    	}
   	 	}
   	 	cout<<"\n"<<endl;
   	 	float Sxx = 0;
   	 	float Sxy = 0;

   	 	float SStotal = 0;
   	 	float SSreg = 0;
   	 	float SSerr = 0;
   	 	float SStot = 0;
   	 	for(int i = 0 ; i < n ; i++){
    	 		Sxx += (x_holder[i]-x_average)*(x_holder[i]-x_average);
   	 		Sxy += (x_holder[i]-x_average)*(y_holder[i]-y_average);
     	 	}

   	 	float b1 = 0;
   	 	float bo = 0;

   	 	b1 = Sxy/Sxx;
   	 	bo = y_average - b1*x_average;
   	 	cout<<"This is Bo: "<<bo<<endl;
   	 	cout<<"This is B1: "<<b1<<endl;
   	 	cout<<"Below is the regression formula for the population"<<endl;
   	 	cout<<"y = "<<bo<<" + "<<b1<<"x"<<endl;



   	 	x_sameple_average/=10;
   	 	y_sameple_average/=10;

   	 	Sxx = 0;
   	 	Sxy = 0;
   	 	SSerr = 0;


   	 	for(int i = 0 ; i < 10 ; i++){
   	 		Sxx += (x_sample[i]-x_sameple_average)*(x_sample[i]-x_sameple_average);
   	 		Sxy += (x_sample[i]-x_sameple_average)*(y_sample[i]-y_sameple_average);
   	 		SStotal +=(y_sample[i]-y_sameple_average)*(y_sample[i]-y_sameple_average);
     	 }

   	 	b1 = 0;
   	 	bo = 0;
   	 	b1 = Sxy/Sxx;
   	 	cout<<"Sxx "<<Sxx<<endl;

   	 	SSreg = b1*b1*Sxx;
   	 	bo = y_sameple_average - b1*x_sameple_average;
   	 	cout<<"This is Bo: "<<bo<<endl;
   	 	cout<<"This is B1: "<<b1<<endl;
   	 	cout<<"SStotal is : "<<SStotal<<endl;
   	 	cout<<"SSreg is: "<<SSreg<<endl;
   	 	cout<<"Below is the regression formula for the sample"<<endl;
   	 	cout<<"y = "<<bo<<" + "<<b1<<"x"<<endl;


 	  return 0;
}
