#pragma once
#ifndef OP_NODE_H
#define OP_NODE_H
//#include "stdafx.h"
//#include <vector>
using namespace std;
//#include <boost/ptr_container/ptr_vector.hpp>
//#include <boost/utility.hpp>
//enum {NUM,OP,SYM};

class node{
public:
	char type;
	bool on;
	int arity_float;
	int arity_bool;
	float value;
	float* valpt;
	string varname;
	int c; // complexity
	bool intron; // behavioral intron declaration (used in getComplexity())
	char return_type;
	node() {type=0; on=1; arity_float=0; arity_bool=0; intron = true;return_type='f';}
	//node(int set) {type=set;on=1;}
	//operator with specified arity
	node(char stype,int sarity){type=stype; arity_float=sarity;arity_bool=0; on=1; setComplexity(); intron = true;return_type='f';}
	//operator with arity lookup
	node(char stype)
	{
		type=stype;
		if (type=='s' || type=='c' || type=='e' || type=='l' || type=='q'){
			arity_float = 1; 
			arity_bool=0;		
			return_type='f';
		}
		else if (type=='+' || type=='-' || type=='*' || type=='/' || type=='^'){
			arity_float=2;
			arity_bool=0;
			return_type='f';
		}
		else if (type=='<' || type=='>' || type=='{' || type=='}' || type=='='){
			arity_float=2;
			arity_bool=0;
			return_type='b';
		}
		else if (type=='&' || type=='|' ){
			arity_float = 0;
			arity_bool = 2;
			return_type='b';
		}
		else if (type=='!'){
			arity_float=0;
			arity_bool=1;
			return_type='b';
		}
		else if (type=='i'){
			arity_bool=1;
			arity_float=1;
			return_type='f';
		}
		else if (type=='t'){
			arity_bool=1;
			arity_float=2;
			return_type='f';
		}
		else{
			std::cerr << "error in op_node: node type not specified";
			throw;
		}
		on=1;
		// assign complexity
		setComplexity();
		intron = true;
	}
	//number
	node(float svalue){type='n'; value=svalue; on=1; arity_float=0;arity_bool=0; c=1;intron = 0;return_type='f';}
	//variable
	node(string& vname){type='v';varname=vname;on=1;arity_float=0;arity_bool=0; c=1;intron = 0;return_type='f';}
	int arity()
	{
		return arity_float + arity_bool;
	}
	//set pointer for variables
	void setpt(float* set)
	{
		if (set==NULL)
			cout<<"bad set";
		valpt=set;
	}
	~node() {}
private:
	void setComplexity()
	{
		// assign complexity
		if (type=='i' || type=='t') 
			c = 5;
		else if (type=='e' || type=='l' || type=='^') 
			c = 4; 
		else if (type=='s' || type=='c' ) 
			c = 3;
		else if (type=='/' || type=='q' || type=='<' || type=='>' || type=='{' || type=='}' || type=='&' || type=='|') 
			c = 2;
		else 
			c = 1;
	}
};


#endif