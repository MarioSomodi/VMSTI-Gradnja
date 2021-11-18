#include "Dokument.h"

using namespace tinyxml2;

Dokument::Dokument() 
{
	this->UcitajXMLArtikle();
}

Dokument::Dokument(string tD, string dD, double iU, double iI, int sOA)
{
	m_sTipDokumenta = tD;
	m_sDatumDokumenta = dD;
	m_dIznosUlaz = iU;
	m_dIznosIzlaz = iI;
	m_nSifraOdabranogArtikla = sOA;
	this->UcitajXMLArtikle();
};

bool Dokument::UcitajXMLArtikle() 
{
	this->m_vArtikli.clear();
	tinyxml2::XMLDocument oDoc;
	XMLError oResult = oDoc.LoadFile("sifrarnik_artikli.xml");
	if (oResult != XML_SUCCESS)
	{
		cout << "Greška u XML datoteci!" << endl;
		return false;
	}
	XMLElement* oRoot = oDoc.FirstChildElement("dataset");
	if (oRoot == nullptr) return false;
	XMLElement* artikli = oRoot->FirstChildElement("artikl");
	if (artikli == nullptr) return false;
	for (artikli = oRoot->FirstChildElement("artikl"); artikli != NULL; artikli = artikli->NextSiblingElement())
	{
		int nSifraArtikla = stoi(artikli->Attribute("sifraArtikla"));
		string sNazivArtikla = artikli->Attribute("nazivArtikla");
		string sJMJ = artikli->Attribute("JMJ");
		double dCijenaArtikla = stod(artikli->Attribute("cijenaArtikla"));
		this->m_vArtikli.push_back(new Artikl(nSifraArtikla, sNazivArtikla, sJMJ, dCijenaArtikla));
	}
	return true;
}

string Dokument::VratiTip()
{
	return m_sTipDokumenta;
}

string Dokument::VratiDatum()
{
	return m_sDatumDokumenta;
}

double Dokument::VratiIznosUlaza()
{
	return m_dIznosUlaz;
}

double Dokument::VratiIznosIzlaza()
{
	return m_dIznosIzlaz;
}

int Dokument::VratiSifruOdabranogArtikla() 
{
	return m_nSifraOdabranogArtikla;
}

Dokument::~Dokument()
{
};