#pragma once
#include<iostream> 
#include<list> 

using namespace std;

class Screen
{
private:

public:
	virtual void Print() = 0;
	void Clear();
};

