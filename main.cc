/*
 * main.cc
 *
 *  Created on: Nov 20, 2014
 *      Author: joe--ngigi
 */

#include "driver.h"
#include "full_adder.h"
#include "monitor.h"

int sc_main (int argc, char* argv[]){

	sc_set_time_resolution(1,SC_NS);

		sc_signal<bool>t_a, t_b, t_carryin, t_sum, t_carryout;
		sc_trace_file *tf;

		full_adder f1("fulladder");
	    f1.fa(t_a);
	    f1.fb(t_b);
	    f1.carryout(t_carryout);
	    f1.sum(t_sum);
	    f1.fcarryin(t_carryin);

		driver d("driver");
		d.d_a(t_a);
		d.d_b(t_b);
		d.d_carryin(t_carryin);

		monitor m1("monitor");
		m1.m_a(t_a);
		m1.m_b(t_b);
		m1.m_carryin(t_carryin);
		m1.m_sum(t_sum);
		m1.m_carryout(t_carryout);



		tf=sc_create_vcd_trace_file("f_adder_waveforms");
		sc_trace(tf,t_a,"t_a");
		sc_trace(tf,t_b,"t_b");
		sc_trace(tf,t_carryin,"t_carryin");
		sc_trace(tf,t_sum,"t_sum");
		sc_trace(tf,t_carryout,"t_carryout");
		cout<<"starting simulation"<<endl;

		cout<<"simulation time resolution: "<<sc_get_time_resolution()<<endl;
		sc_start(100,SC_NS);//start the simulation and run for 100 Ns
		sc_close_vcd_trace_file(tf);
		cout<<"simulation done"<<endl;
	return 0;
}





