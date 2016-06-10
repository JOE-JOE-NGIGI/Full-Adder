/*
 * full_adder.h
 *
 *  Created on: Nov 20, 2014
 *      Author: joe--ngigi
 */

#ifndef FULL_ADDER_H_
#define FULL_ADDER_H_
#include "systemc.h"
#include"../../half_adder/SRC/half_adder.h"



SC_MODULE(full_adder){
	sc_in<bool>fa,fb,fcarryin;
	sc_out<bool>carryout,sum;
	sc_signal<bool> c1,c2,s1;
	void prc_full_adder(){
		carryout=c1|c2;

	}
	half_adder *half_adder1, *half_adder2;

	SC_CTOR(full_adder){

		half_adder1=new half_adder("half_adder1");
		half_adder1->a(fa);
		half_adder1->b(fb);
		half_adder1->c(c1);
		half_adder1->s(sum);

		half_adder2=new half_adder("half_adder2");
		(*half_adder2)(sum,fcarryin,s1,c2);
		/*half_adder l1("half_adder");
		half_adder l2("half_adder2");

		l1.a(fa);
		l1.b(fb);
		l1.c(c1);
		l1.s(s1);
		l2(s1,fcarryin,sum,c2);*/
		SC_METHOD(prc_full_adder);
		sensitive<<c1<<c2;
		//dont_initialize();
		}
};


#endif /* FULL_ADDER_H_ */
