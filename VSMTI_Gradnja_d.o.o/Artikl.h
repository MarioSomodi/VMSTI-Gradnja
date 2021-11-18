#pragma once
#include <vector>
#include <string>

using namespace std;

class Artikl
{
public:
	Artikl(int sA, string nA, string JMJ, double cA);
	~Artikl();
	int VratiSifru();
	string VratiNaziv();
	string VratiJMJ();
	double VratiCijenu();
private:
	int m_nSifraArtikla;
	string m_sNazivArtikla;
	string m_sJMJ;
	double m_dCijenaArtikla;
};

