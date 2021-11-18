#pragma once
#include "Dokument.h"
class Izdatnica :
	public Dokument
{
public:
	Izdatnica(string tD, string dD, double iU, double iI, int sOA);
	~Izdatnica();
};

