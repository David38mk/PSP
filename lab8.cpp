#include <iostream>
using namespace std;

struct sostojki
{
    string ime;
    int masa;
};


class Kproizvodi
{
private:
    string ime;
    int brojS;
    int cena;
    sostojki *lista;
public:
    Kproizvodi(){
        ime = "Bekutan";
        cena = 318;
        brojS = 4;
        lista = new sostojki[brojS];
        lista[0].ime = "maslinovo maslo";
        lista[0].masa =20;
        lista[1].ime = "ekstrakt od kamilica";
        lista[1].masa =10;
        lista[2].ime="vitamin E";
        lista[2].masa =1;
        lista[3].ime = "Depantenol";
        lista[3].masa=20;
    }
    Kproizvodi(string i, int brS, int C, sostojki *l)
    {
        ime = i;
        brojS = brS;
        cena = C;
        lista = new sostojki[brojS];
        for(int i=0;i<brojS;i++)
        {
            lista[i].ime = l[i].ime;
            lista[i].masa = l[i].masa;
        }
    }
    Kproizvodi(const Kproizvodi &u)
    {
        ime = u.ime;
        brojS = u.brojS;
        cena = u.cena;
        lista = new sostojki[brojS];
        for(int i=0;i<brojS;i++)
        {
            lista[i].ime = u.lista[i].ime;
            lista[i].masa = u.lista[i].masa;
        }
    }
    ~Kproizvodi(){
        delete []lista;
    }
    sostojki getSostojka(int i)
    {
        return lista[i];
    }
    void pecati()
    {
        cout << ime << endl;
        cout <<"Broj na proizvodi: "<< brojS << endl;
        cout << "Cena: "<< cena << endl;
        cout << "Sostojki(ime i grami): " << endl;
        for(int i=0;i<brojS;i++)
        {
            cout <<lista[i].ime<< " " << lista[i].masa<< endl;
        }
    }
    void dodadiSostojka(sostojki &m){
        sostojki *pom = new sostojki[brojS+1];
        pom[0].ime=m.ime;
        pom[0].masa=m.masa;
        int k=0;
        for(int i=1;i<brojS+1;i++)
        {
            pom[i].ime = lista[k].ime;
            pom[i].masa = lista[k].masa;
            k++;
        }
        brojS++;
        delete []lista;
        lista= new sostojki[brojS];
        for(int i=0;i<brojS;i++)
        {
            lista[i]=pom[i];
        }
        delete []pom;
    }
    void brisiSostojka(sostojki &m){
        sostojki *pom = new sostojki[brojS-1];
        int k=0;
        for(int i=0;i<brojS;i++)
        {
            if(lista[i].ime!= m.ime && lista[i].masa !=m.masa)
            {
                pom[k]=lista[i];
                k++;    
            }
        }
        cout << "da" << endl;
        delete []lista;
        brojS--;
        lista = new sostojki[brojS];
        for(int i=0;i<brojS;i++)
        {
            lista[i] = pom[i];
        }
        delete []pom;
    }
};


int main()
{
    Kproizvodi Proizvod;
    sostojki sostojka;
    sostojka.ime = "Ketanol";
    sostojka.masa = 45;
    Proizvod.dodadiSostojka(sostojka);
    Proizvod.pecati();
    Proizvod.brisiSostojka(sostojka);
    Proizvod.pecati();
    return 0;
}