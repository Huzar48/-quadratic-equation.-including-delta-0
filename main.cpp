#include <iostream>
#include <stdexcept>
#include <cmath>


using namespace std;
/*zaprojektowac klase ktora pozwoli wyznaczyc
wartosc rownania kwadratowego postaci ax^2+bx+c=0
dla delta>0, delta=0, delta<0*/

class rownanie{
    double A;
    double B;
    double C;
    double delta;
    double sqrt_delta; 
    double x1;
    double x2;

    public:
       rownanie(){ //konstruktor
            A=0;
            B=0;
            C=0;
            delta=0;
            sqrt_delta=0;
            x1=0;
            x2=0;
        }; 

    void WprowadzDane(){ //metoda do zbierania danych wejściowych i weryfikacji ich typu

    try{
        cin.exceptions(std::istream::failbit); //zebranie danych do weryfikacji
        
        cout<<"Podaj wartosci w formacie int"<<endl;
        cout<<"Podaj A: ";
        cin>>A;
        if(A==0){
            throw std::invalid_argument("A=0, zatem funkcja nie jest kwadratowa"); //wyrzuć błąd w przypadku podania A=0
        }
        cout<<endl;
        cout<<"Podaj B: ";
        cin>>B;
        cout<<endl;
        cout<<"Podaj C: ";
        cin>>C;
        cout<<endl;
        
    }

        catch(std::ios_base::failure & fail){ //"zlapanie błędnej zmiennej"
        cin.clear(); //wyczyszczenie zmiennych w przypadku wykrycia błędnej zmiennej
        cout<<"Podales zmienna innego typu niz int"<<endl;
    }
    };

    void WypiszDane(){ //metoda wypisująca dane podane przez użytkownika
        cout<<"A="<<A<<" "<<"B="<<B<<" "<<"C="<<C<<endl;
    }

    friend class sprawdz; //deklaracja przyjazni do klasy sprawdz
    friend void zatwierdzDane(rownanie & obiekt); //deklaracja przyjazni do funkcji zatiwerdz dane
    friend class delta; //deklaracja przyjazni do klasy delta
    friend void delta_dzial(rownanie & obiekt); //deklaracja przyjazni do funkcji zatiwerdz dane
    friend void delta_zero(rownanie & obiekt); //deklaracja przyjazni do funkcji zatiwerdz dane
    friend void delta_dod(rownanie & obiekt); //deklaracja przyjazni do funkcji zatiwerdz dane
    friend void delta_uj(rownanie & obiekt); //deklaracja przyjazni do funkcji zatiwerdz dane

};

class sprawdz{ //klasa  mająca na celu potwierdzenie przez użytkownika poprawności danych

    char YN;

    public: sprawdz(){  
         char YN = 'Y';
    };

     public: void zatwierdzDane(rownanie & obiekt){ //metoda potwierdza 
        cout<<"Dane sa poprawne? (Y/N)"<<endl;
        cin>>YN;
            if(YN == 'Y'|| YN=='y'){
                obiekt.WypiszDane();
            }
            else if(YN == 'N'|| YN=='n'){
                obiekt.WprowadzDane();
                obiekt.WypiszDane();
            }
            else{
                throw std::invalid_argument("Nie to miales wpisac (-.-)"); //wyrzuć błąd w przypadku podania innej wartości niż oczekiwana
            }
    };
};

class delta { //klasa zajmująca się obsługą delty
     public: void delta_dzial(rownanie & obiekt){
            obiekt.delta=(obiekt.B*obiekt.B)-4*obiekt.A*obiekt.C; //liczenie delty
           
            cout<<"Delta jest rowna: "<<obiekt.delta<<endl;

             if(obiekt.delta>0){ //delta>0
                cout<<"Delta > 0"<<endl; 
                obiekt.sqrt_delta=sqrt(obiekt.delta);
                cout<<"Pierwiastek z delty jest rowny: "<<obiekt.sqrt_delta<<endl;
            
                    obiekt.x1=(-obiekt.B+obiekt.sqrt_delta)/(2*obiekt.A);
                    obiekt.x2=(-obiekt.B-obiekt.sqrt_delta)/(2*obiekt.A);
                    cout<<"Rownianie to ma dwa pierwiastki : "<<obiekt.x1<<" i "<<obiekt.x2<<endl;
            }
            else if(obiekt.delta==0){ //delta=0
                cout<<"Delta = 0"<<endl;
                obiekt.x1=(-obiekt.B)/(2*obiekt.A);
                cout<<"Rownianie to ma jeden pierwiasek: "<<obiekt.x1<<endl;
            }
            else{ //delta<0 zespolone
                    obiekt.delta=-1*(obiekt.delta);

                    cout<<"Pierwiastek z delty jest rowny: "<<obiekt.delta<<"j"<<endl;
                    cout<<"Delta < 0"<<endl;
                        
                    double z1_1=(-sqrt(obiekt.delta))/(2*obiekt.A);
                    double z1_2=(-obiekt.B)/(2*obiekt.A);
                    cout<<"Pierwsza liczba zespolona to: "<<z1_2;
                        if(z1_1>0){
                            cout<<" + "<<abs(z1_1)<<"j"<<endl;
                        }
                        else{
                            cout<<" - "<<abs(z1_1)<<"j"<<endl;
                        }

                    double z2_1=(sqrt(obiekt.delta))/(2*obiekt.A);
                    double z2_2=(-obiekt.B)/(2*obiekt.A);
                    cout<<"Pierwsza liczba zespolona to: "<<z2_2;
                    if(z2_1>0){
                            cout<<" + "<<abs(z2_1)<<"j"<<endl;
                        }
                        else{
                            cout<<" - "<<abs(z2_1)<<"j"<<endl;
                        }
            }
        };
       
};

int main()
{
    rownanie nowe;
        nowe.WprowadzDane();

    sprawdz idk;
         idk.zatwierdzDane(nowe);
    
    delta dzial;
        dzial.delta_dzial(nowe);
     return 0;
}
