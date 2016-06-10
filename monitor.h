/*
 * monitor.h
 *
 *  Created on: Nov 20, 2014
 *      Author: joe--ngigi
 */
#include "systemc.h"
#include<iostream>

using namespace std;

SC_MODULE (monitor){
	sc_in<bool> m_a,m_b,m_carryin,m_sum,m_carryout;
	void prc_monitor(){
		cout<<"  At "<<sc_time_stamp()<<" input m_a m_b m_carryin is: "<<m_a<<m_b<<m_carryin<<" output m_s and m_carryout is: "<<m_sum<<m_carryout<<endl;
		}
	SC_CTOR(monitor){
		SC_METHOD(prc_monitor);
		sensitive<<m_a<<m_b<<m_carryin<<m_sum<<m_carryout;
		}
};
