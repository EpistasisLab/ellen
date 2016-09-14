// header file for ind struct
#pragma once
#ifndef DATA_H
#define DATA_H

using namespace std;


//typedef exprtk::parser_error::type error_t;

struct Data {


	vector<string> label; // variables corresponding to those defined in parameters 
	vector<vector<float> > vals; //2D vector of all data, can be accessed data[row][column]
	//vector<vector<float>> FEvals;
	//fitness estimator vector

	//vector<float> dattovar;
	vector<float> target;
	//unordered_map <string,float*> datatable;
	//mymap.
	/*mymap.insert(pair<string,int*>("alpha",10));
	mymap.insert(pair<string,int>("beta",20));
	mymap.insert(pair<string,int>("G1",30));*/

	// variables for lexicase selection
	vector<vector<float> > targetlex;
	vector<vector<vector<float> > > lexvals;
	//vector<int> lexicase;
	string target_var; //target variable

	Data(){}
	void clear()
	{
		label.clear();
		vals.clear();
		//dattovar.clear();
		target.clear();
		//datatable.clear();
	}
	/*void mapdata()
	{
		for (unsigned int i=0;i<label.size(); ++i)
			datatable.insert(pair<string,float*>(label[i],&dattovar[i]));
	}*/
	~Data() 
	{
		//I think the data pointed to by the map should be destroyed
		//in here (datatable) as well as the pointer, since both are contained within the class.
		//therefore this deletion is unecessary. also no news are called.
		/*for (unordered_map<string,float*>::iterator i = datatable.begin(); i != datatable.end();++i)
		{
			delete (*i).second;
		}
		datatable.clear();*/
	}
};

#endif
