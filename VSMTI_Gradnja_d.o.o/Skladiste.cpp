#include "Skladiste.h"

Skladiste::Skladiste() 
{
	UcitajXMLDokumente();
	UpisDokumenataUXML();
	IzracunStanjaArtikalaNaSkladistuIUpisUXML();
}

bool Skladiste::ProvjeriIntegerUnos(string unos)
{
	int is_num = 0,
		decimal_count = 0,
		user_converted_num;

	bool is_num_bool = false;

	if (unos[0] == '-') 
	{
		is_num++;
	}

	if (unos[0] == '0' && isdigit(unos[1])) 
	{
		is_num = 0;
	}
	else
	{
		for (int i = 0; i < unos.size(); i++)
		{
			if (isdigit(unos[i])) 
			{
				is_num++;
			}
			if (unos[i] == '.') 
			{
				decimal_count++;
			}
		}
	}

	if (decimal_count == 1)
	{
		is_num = 0;
	}

	if (is_num == unos.size())
	{
		stringstream str_stream_object(unos);
		str_stream_object >> user_converted_num;

		is_num_bool = true;

		return is_num_bool;
	}
	else
	{
		cout << "Ovaj unos prima samo brojeve!!" << endl;

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		is_num_bool = false;
		is_num = 0;
		decimal_count = 0;
		return is_num_bool;
	}
}

string Skladiste::GetDateTime()
{
	string sDateTime;
	time_t t;
	t = time(NULL);
	tm tlm;
	localtime_s(&tlm, &t);
	sDateTime = to_string(tlm.tm_year + 1900)
		+ "-"
		+ to_string(tlm.tm_mon + 1)
		+ "-"
		+ to_string(tlm.tm_mday)
		+ " "
		+ to_string(tlm.tm_hour)
		+ ":"
		+ to_string(tlm.tm_min)
		+ ":"
		+ to_string(tlm.tm_sec);
	return sDateTime;
}

void Skladiste::NovaPrimka()
{
	cin.clear();
	string sBrojArtikala = "";
	Dokument dok;
	bool is_num_bool = false;
	int rbr = 0;

	do
	{
		cout << "Za koliko razlicitih artikala trebate primku: ";
		cin >> sBrojArtikala;
		is_num_bool = ProvjeriIntegerUnos(sBrojArtikala);
		if (is_num_bool == true) 
		{
			if (stoi(sBrojArtikala) < 1)
			{
				cout << "Uneseni broj ne smije biti 0 ili manji od 0!!\n";
				is_num_bool = false;
			}
			else if (stoi(sBrojArtikala) > dok.m_vArtikli.size())
			{
				cout << "Uneseni broj ne smije biti veci od broja postojecih artikala!!\n";
				is_num_bool = false;
			}
		}
	} while (is_num_bool == false);

	int nArtikala = stoi(sBrojArtikala);
	int nSifra = 0;
	string SSifra;

	while (rbr < nArtikala)
	{
		is_num_bool = false;
		IspisArtikala();
		do
		{
			cout << "\nUnesi sifru " << rbr + 1 << ". artikla: ";
			cin >> SSifra;
			is_num_bool = ProvjeriIntegerUnos(SSifra);
			if (is_num_bool == true) 
			{
				if (stoi(SSifra) <= 0 || stoi(SSifra) > dok.m_vArtikli.size())
				{
					cout << "Nepostojeca sifra!!";
					is_num_bool = false;
				}
			}
		}while (is_num_bool == false);

		nSifra = stoi(SSifra);
		is_num_bool = false;
		
		double dUlaz = 0;
		string sUlaz;

		cout << "Nova primka: " << endl;
		do
		{
			cout << "Iznos ulaz: ";
			cin >> sUlaz;
			is_num_bool = ProvjeriIntegerUnos(sUlaz);
			if (is_num_bool == true) 
			{
				if (stoi(sUlaz) <= 0) 
				{
					cout << "Broj iznosa ulaza mora biti veci od 0!\n";
					is_num_bool = false;
				}
				else 
				{
					dUlaz = stoi(sUlaz);
					Primka temp("PRM", GetDateTime(), dUlaz, 0, nSifra);
					vDokumenti.push_back(temp);
				}
			}
		} while (is_num_bool == false);
		rbr++;
	}
}

void Skladiste::NovaIzdatnica()
{
	string sBrojArtikala;
	bool is_num_bool = false;
	Dokument dok;
	do
	{
		cout << "Za koliko razlicitih artikala trebate izdatnicu: ";
		cin >> sBrojArtikala;
		is_num_bool = ProvjeriIntegerUnos(sBrojArtikala);
		if (is_num_bool == true)
		{
			if (stoi(sBrojArtikala) < 1)
			{
				cout << "Uneseni broj ne smije biti 0 ili manji od 0!!\n";
				is_num_bool = false;
			}
			else if (stoi(sBrojArtikala) > dok.m_vArtikli.size())
			{
				cout << "Uneseni broj ne smije biti veci od broja postojecih artikala!!\n";
				is_num_bool = false;
			}
		}
	} while (is_num_bool == false);

	int nArtikala = stoi(sBrojArtikala);
	int rbr = 0;
	string SSifra;
	int nSifra = 0;

	while (rbr < nArtikala)
	{
		is_num_bool = false;
		IspisArtikala();
		do
		{
			cout << "\nUnesi sifru " << rbr + 1 << ". artikla: ";
			cin >> SSifra;
			is_num_bool = ProvjeriIntegerUnos(SSifra);
			if (is_num_bool == true)
			{
				if (stoi(SSifra) <= 0 || stoi(SSifra) > dok.m_vArtikli.size())
				{
					cout << "Nepostojeca sifra!!";
					is_num_bool = false;
				}
			}
		} while (is_num_bool == false);

		nSifra = stoi(SSifra);
		is_num_bool = false;

		double dIzlaz = 0;
		string sIzlaz;

		cout << "Nova izdatnica: " << endl;

		do
		{
			cout << "Iznos izlaz: ";
			cin >> sIzlaz;
			is_num_bool = ProvjeriIntegerUnos(sIzlaz);
			if (is_num_bool == true)
			{
				if (stoi(sIzlaz) <= 0)
				{
					cout << "Broj iznosa ulaza mora biti veci od 0!\n";
					is_num_bool = false;
				}
				else
				{
					dIzlaz = stoi(sIzlaz);
					tinyxml2::XMLDocument oDoc;
					XMLError oResult = oDoc.LoadFile("artikli_dokumenta.xml");
					if (oResult != XML_SUCCESS)
					{
						cout << "Greška u XML datoteci!" << endl;
					}
					XMLElement* oRoot = oDoc.FirstChildElement("artikliDokumenata");
					XMLElement* dokument = oRoot->FirstChildElement("artikl");
					bool nadenArtikal = false, nedovoljan = false;
					for (dokument = oRoot->FirstChildElement("artikl"); dokument != NULL; dokument = dokument->NextSiblingElement())
					{
						int sifraArtikla = stoi(dokument->Attribute("sifraArtikla"));
						int stanjeKolicina = stoi(dokument->Attribute("stanjeKolicina"));
						if (nSifra == sifraArtikla)
						{
							if (stanjeKolicina < dIzlaz)
							{
								cout << "Nije moguce napraviti izdatnicu za odabrani artikal posto ga nema toliko na skladistu!" << endl;
								nedovoljan = true;
								is_num_bool = false;
							}
							nadenArtikal = true;
						}
					}
					if (nadenArtikal == false)
					{
						cout << "Nije moguce napraviti izdatnicu za odabrani artikal posto ga trenutno uopce nemamo na skladistu!" << endl;
						nedovoljan = true;
						is_num_bool = false;
					}
					if (nedovoljan == false)
					{
						Izdatnica Izd("IZD", GetDateTime(), 0, dIzlaz, nSifra);
						vDokumenti.push_back(Izd);
					}
				}
			}
		} while (is_num_bool == false);
		rbr++;
	}
}

bool Skladiste::UcitajXMLDokumente() 
{
	vDokumenti.clear();
	tinyxml2::XMLDocument oDoc;
	XMLError oResult = oDoc.LoadFile("dokumenti.xml");
	if (oResult != XML_SUCCESS)
	{
		cout << "Greška u XML datoteci!" << endl;
		return false;
	}
	XMLElement* oRoot = oDoc.FirstChildElement("dokumenti");
	if (oRoot == nullptr) return false;
	XMLElement* dokument = oRoot->FirstChildElement("dokument");
	if (dokument == nullptr) return false;
	for (dokument = oRoot->FirstChildElement("dokument"); dokument != NULL; dokument = dokument->NextSiblingElement())
	{
		string tipDokumenta = dokument->Attribute("tipDokumenta");
		string datumDokumenta = dokument->Attribute("datumDokumenta");
		int iznosUlaz = stoi(dokument->Attribute("iznosUlaz"));
		int iznosIzlaz = stoi(dokument->Attribute("iznosIzlaz"));
		int sifraOdabranogArtikla = stoi(dokument->Attribute("sifraOdabranogArtikla"));
		if (tipDokumenta == "IZD")
		{
			Izdatnica Izd(tipDokumenta, datumDokumenta, iznosUlaz, iznosIzlaz, sifraOdabranogArtikla);
			vDokumenti.push_back(Izd);
		}
		else if (tipDokumenta == "PRM")
		{
			Primka Prm(tipDokumenta, datumDokumenta, iznosUlaz, iznosIzlaz, sifraOdabranogArtikla);
			vDokumenti.push_back(Prm);
		}
	}
	return true;
}

void Skladiste::IspisArtikala()
{
	Dokument dokument;
	vector<Artikl*>::iterator itArtikli;

	for (itArtikli = dokument.m_vArtikli.begin(); itArtikli != dokument.m_vArtikli.end(); ++itArtikli)
	{
		cout << "Sifra artikla: " << (*itArtikli)->VratiSifru() << endl;
		cout << "Naziv artikla: " << (*itArtikli)->VratiNaziv() << endl;
		cout << "==============================================" << endl;
	}
}

void Skladiste::IzracunStanjaArtikalaNaSkladistuIUpisUXML()
{
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLDocument doc1;
	XMLDeclaration* decl = doc.NewDeclaration();
	decl->SetValue("xml version='1.0' encoding='utf-8'");
	doc.InsertEndChild(decl);
	XMLElement* root = doc.NewElement("artikliDokumenata");
	doc.InsertAfterChild(decl, root);
	Dokument dokument;
	vector<Dokument>::iterator itDokumenti;
	vector<Artikl*>::iterator itArtikli;
	XMLError oResult = doc1.LoadFile("artikli_dokumenta.xml");
	if (oResult != XML_SUCCESS)
	{
		cout << "Greška u XML datoteci!" << endl;
	}
	XMLElement* oRoot = doc1.FirstChildElement("artikliDokumenata");
	double kolicinaIzlaz = 0, iznosIzlaz = 0, kolicinaUlaz = 0, iznosUlaz = 0;
	for (itArtikli = dokument.m_vArtikli.begin(); itArtikli != dokument.m_vArtikli.end(); ++itArtikli)
	{
		for (itDokumenti = vDokumenti.begin(); itDokumenti != vDokumenti.end(); ++itDokumenti)
		{
			if ((*itArtikli)->VratiSifru() == itDokumenti->VratiSifruOdabranogArtikla())
			{
				if (itDokumenti->VratiTip() == "IZD")
				{
					kolicinaIzlaz += itDokumenti->VratiIznosIzlaza();
				}
				else if (itDokumenti->VratiTip() == "PRM")
				{
					kolicinaUlaz += itDokumenti->VratiIznosUlaza();
				}
			}
		}
		for (XMLElement* dokument1 = oRoot->FirstChildElement("artikl"); dokument1 != NULL; dokument1 = dokument1->NextSiblingElement())
		{
			int sifraArtikla = stoi(dokument1->Attribute("sifraArtikla"));
			double pIznosUlaz = stoi(dokument1->Attribute("iznosUlaz"));
			double pIznosIzlaz = stoi(dokument1->Attribute("iznosIzlaz"));
			double pkolicinaIzlaz = stoi(dokument1->Attribute("kolicinaIzlaz"));
			double pkolicinaUlaz = stoi(dokument1->Attribute("kolicinaUlaz"));
			double pCijena = stoi(dokument1->Attribute("pCijena"));
			double pStanjeCijena = stoi(dokument1->Attribute("stanjeCijena"));
			if (sifraArtikla == (*itArtikli)->VratiSifru())
			{
				if ((*itArtikli)->VratiCijenu() == pCijena)
				{
					iznosIzlaz = (*itArtikli)->VratiCijenu() * kolicinaIzlaz;
				}
				else
				{
					iznosIzlaz = (pCijena * pkolicinaIzlaz) + ((*itArtikli)->VratiCijenu() * (abs(kolicinaIzlaz - pkolicinaIzlaz)));
				}

				if ((*itArtikli)->VratiCijenu() == pCijena)
				{
					iznosUlaz = (*itArtikli)->VratiCijenu() * kolicinaUlaz;
				}
				else
				{
					iznosUlaz = (pCijena * pkolicinaUlaz) + ((*itArtikli)->VratiCijenu() * (abs(kolicinaUlaz - pkolicinaUlaz)));
				}
			}
		}
		double stanjeKolicina = kolicinaUlaz - kolicinaIzlaz;
		double stanjeCijena = iznosUlaz - iznosIzlaz;
		XMLElement* child = doc.NewElement("artikl");
		child->SetAttribute("sifraArtikla", (*itArtikli)->VratiSifru());
		child->SetAttribute("stanjeKolicina", stanjeKolicina);
		child->SetAttribute("kolicinaIzlaz", kolicinaIzlaz);
		child->SetAttribute("kolicinaUlaz", kolicinaUlaz);
		child->SetAttribute("iznosIzlaz", iznosIzlaz);
		child->SetAttribute("iznosUlaz", iznosUlaz);
		child->SetAttribute("stanjeCijena", stanjeCijena);
		child->SetAttribute("pCijena", (*itArtikli)->VratiCijenu());
		root->InsertEndChild(child);
		kolicinaIzlaz = 0, iznosIzlaz = 0, kolicinaUlaz = 0, iznosUlaz = 0;
	}
	doc.SaveFile("artikli_dokumenta.xml");
}

void Skladiste::IspisStanjaSkladista()
{
	vector<Artikl*>::iterator itArtikli;
	Dokument dokument;
	tinyxml2::XMLDocument doc1;
	XMLError oResult = doc1.LoadFile("artikli_dokumenta.xml");
	if (oResult != XML_SUCCESS)
	{
		cout << "Greška u XML datoteci!" << endl;
	}
	XMLElement* oRoot = doc1.FirstChildElement("artikliDokumenata");
	for (itArtikli = dokument.m_vArtikli.begin(); itArtikli != dokument.m_vArtikli.end(); ++itArtikli) 
	{
		for (XMLElement* dokument1 = oRoot->FirstChildElement("artikl"); dokument1 != NULL; dokument1 = dokument1->NextSiblingElement())
		{
			int sifraArtikla = stoi(dokument1->Attribute("sifraArtikla"));
			if (sifraArtikla == (*itArtikli)->VratiSifru()) 
			{
				double pIznosUlaz = stoi(dokument1->Attribute("iznosUlaz"));
				double stanjeKolicina = stoi(dokument1->Attribute("stanjeKolicina"));
				double pIznosIzlaz = stoi(dokument1->Attribute("iznosIzlaz"));
				double pkolicinaIzlaz = stoi(dokument1->Attribute("kolicinaIzlaz"));
				double pkolicinaUlaz = stoi(dokument1->Attribute("kolicinaUlaz"));
				double pCijena = stoi(dokument1->Attribute("pCijena"));
				double pStanjeCijena = stoi(dokument1->Attribute("stanjeCijena"));

				cout << "Sifra artikla: " << (*itArtikli)->VratiSifru() << endl;
				cout << "Naziv artikla: " << (*itArtikli)->VratiNaziv() << endl;
				cout << "JMJ: " << (*itArtikli)->VratiJMJ() << endl;
				cout << "Cijena: " << (*itArtikli)->VratiCijenu() << "kn" << endl;
				cout << "Kolicina ulaz: " << pkolicinaUlaz << (*itArtikli)->VratiJMJ() << endl;
				cout << "Iznos ulaz: " << pIznosUlaz << "kn" << endl;
				cout << "Kolicina izlaz: " << pkolicinaIzlaz << (*itArtikli)->VratiJMJ() << endl;
				cout << "Iznos izlaz: " << pIznosIzlaz << "kn" << endl;
				cout << "Stanje kolicina: " << stanjeKolicina << (*itArtikli)->VratiJMJ() << endl;
				cout << "Stanje cijena: " << pStanjeCijena << "kn" << endl;
				cout << "==============================================" << endl;
			}
		}
	}
	IzracunStanjaArtikalaNaSkladistuIUpisUXML();
}

void Skladiste::UpisDokumenataUXML()
{
	vector<Dokument>::iterator itDokumenti;
	tinyxml2::XMLDocument doc;
	XMLDeclaration* decl = doc.NewDeclaration();
	decl->SetValue("xml version='1.0' encoding='utf-8'");
	doc.InsertEndChild(decl);
	XMLElement* root = doc.NewElement("dokumenti");
	doc.InsertAfterChild(decl, root);

	for (itDokumenti = vDokumenti.begin(); itDokumenti != vDokumenti.end(); ++itDokumenti)
	{
		XMLElement* child = doc.NewElement("dokument");
		child->SetAttribute("tipDokumenta", itDokumenti->VratiTip().data());
		child->SetAttribute("datumDokumenta", itDokumenti->VratiDatum().data());
		child->SetAttribute("iznosUlaz", itDokumenti->VratiIznosUlaza());
		child->SetAttribute("iznosIzlaz", itDokumenti->VratiIznosIzlaza());
		child->SetAttribute("sifraOdabranogArtikla", itDokumenti->VratiSifruOdabranogArtikla());
		root->InsertEndChild(child);
	}
	doc.SaveFile("dokumenti.xml");
}

void Skladiste::Izbornik()
{
	bool izlaz = false;
	while (izlaz == false)
	{
		bool odabir = false;
		int nIzbor = 0;
		string sIzbor = "";
		cout << "1 - Stanje Skladista\n"
			"2 - Nova Izdatnica\n"
			"3 - Nova Primka\n";
		do
		{
			cout << "Odabir: ";
			cin >> sIzbor;
			odabir = ProvjeriIntegerUnos(sIzbor);
			if (odabir == true) 
			{
				nIzbor = stoi(sIzbor);
				if (nIzbor < 1 || nIzbor > 3) 
				{
					cout << "Unjeli ste broj koji nepostoji na izborniku!! \n";
					odabir = false;
				}
			}
		} while (odabir == false);

		switch (nIzbor)
		{
		case 1:
		{
			system("cls");
			UpisDokumenataUXML();
			IspisStanjaSkladista();
			break;
		}
		case 2:
		{
			system("cls");
			NovaIzdatnica();
			UpisDokumenataUXML();
			IzracunStanjaArtikalaNaSkladistuIUpisUXML();
			break;
		}
		case 3:
		{
			system("cls");
			NovaPrimka();
			UpisDokumenataUXML();
			IzracunStanjaArtikalaNaSkladistuIUpisUXML();
			break;
		}
		default:
		{
			system("cls");
			cout << "Krivi Odabir!!" << endl;
			break;
		}
		}
		Sleep(1000);
		cout << "Pritisnite enter za ponovno otvaranje izbornika, a esc za zatvaranje programa!" << endl;
		bool pritisnuto = false;
		while (pritisnuto == false)
		{
			if (GetKeyState(VK_RETURN) & 0x8000)
			{
				system("cls");
				izlaz = false;
				pritisnuto = true;
			}
			if (GetKeyState(VK_ESCAPE) & 0x8000)
			{
				izlaz = true;
				pritisnuto = true;
			}
		}
	}
	UpisDokumenataUXML();
}

Skladiste::~Skladiste() 
{
}