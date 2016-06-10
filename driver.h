/*
 * driver.h
 *
 *  Created on: Nov 27, 2014
 *      Author: joe--ngigi
 */
#include "systemc.h"
//#include<iostream>

using namespace std;


SC_MODULE(driver){
	sc_out<bool>d_a,d_b,d_carryin;

	void prc_drive_a(){
		sc_uint<3> count;
		count=0;
		//cout<<"outside while loop..."<<endl;
		while(1){
			//cout<<"running driver..."<<endl;
			if(count>7){
				count=0;
			}
			d_a=count[0];
			d_b=count[1];
			d_carryin=count[2];
			count++;
			wait(5,SC_NS);
		}
	}

	SC_CTOR(driver){
		SC_THREAD(prc_drive_a);
		cout<<"created driver..."<<endl;
	}
	};
