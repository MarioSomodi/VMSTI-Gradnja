#pragma once
#include "Dokument.h"
#include <iostream>
#include <string>
#include "Izdatnica.h"
#include "Primka.h"
#include <vector>
#include <ctime>
#define NOMINMAX
#include <Windows.h>
#include <ctype.h>
#include <sstream>
#include "tinyxml2.h"

using namespace tinyxml2;
using namespace std;


class Skladiste
{
public:
	Skladiste();
	~Skladiste();
	vector<Dokument> vDokumenti;
	void Izbornik();
private:
	string GetDateTime();
	void IzracunStanjaArtikalaNaSkladistuIUpisUXML();
	void NovaPrimka();
	void NovaIzdatnica();
	void IspisStanjaSkladista();
	void IspisArtikala();
	void UpisDokumenataUXML();
	bool UcitajXMLDokumente();
	bool ProvjeriIntegerUnos(string unos);
};

