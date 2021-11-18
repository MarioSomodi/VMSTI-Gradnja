#pragma once
#include <vector>
#include "Artikl.h"
#include "tinyxml2.h"
#include <iostream>

using namespace std;
class Dokument
{
public:
	Dokument();
	Dokument(string tD, string dD, double iU, double iI, int sOA);
	~Dokument();
	string VratiTip();
	string VratiDatum();
	double VratiIznosUlaza();
	double VratiIznosIzlaza();
	int VratiSifruOdabranogArtikla();
	vector<Artikl*> m_vArtikli;
protected:
	bool UcitajXMLArtikle();
	string m_sTipDokumenta;
	string m_sDatumDokumenta;
	double m_dIznosUlaz;
	double m_dIznosIzlaz;
	int m_nSifraOdabranogArtikla;
};