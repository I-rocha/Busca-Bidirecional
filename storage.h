#pragma once
#include <stdio.h>
#include <vector>
#include "grafo.h"

class Storage {
public:
	std::vector<std::vector<Estado*>> hash;
	int push(Estado*);
	//int pop(Estado);
	int exist(Estado);
	Storage();
	void show();
};