#include "Artikl.h"
#include <iostream>

Artikl::Artikl(int sA, string nA, string JMJ, double cA)
{
	m_nSifraArtikla = sA;
	m_sNazivArtikla = nA;
	m_sJMJ = JMJ;
	m_dCijenaArtikla = cA;
};

int Artikl::VratiSifru()
{
	return m_nSifraArtikla;
};

string Artikl::VratiNaziv()
{
	return m_sNazivArtikla;
};

string Artikl::VratiJMJ()
{
	return m_sJMJ;
};

double Artikl::VratiCijenu()
{
	return m_dCijenaArtikla;
};

Artikl::~Artikl()
{
};