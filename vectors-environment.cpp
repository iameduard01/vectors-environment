#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Vector{
    int n; //numnar elemente vector
    std::vector <int> my_vector;

public:
    //constructor default
    Vector(){
        n=0;
    }
    //constructor pentru initializarea cu un numar dat pe toate componentele (primeste ca parametru numarul respectiv si numarul componentelor);
    Vector(int nr_init, int nr_comp){ //constructor initializare cu valoare pe toate componentele 
        for(int i = 0; i < nr_comp; i++)
            my_vector.push_back(nr_init);
        n = nr_comp;
    }
    //constructori pentru initializare cu un vector dat
    Vector(int nr_componente, vector <int> vector_initializare){ //constructor de initializare cu un alt vector
        for(int i = 0; i < vector_initializare.size(); i++)
            my_vector.push_back(vector_initializare[i]);
        n = nr_componente;
    }
    //construcor de copiere
    Vector(const Vector& ob){
        n = ob.n;
        for(int i = 0; i < ob.n; i++)
            my_vector.push_back(ob.my_vector[i]);
    }
    //metoda publice pentru citire
    void citire(){
        int na;
        cout << "Introduceti numarul de elemente: " << '\n';
        cin >> na;
        n = na;
        for(int i = 0; i < n; i++){
            int nr;
            cout << "Introduceti elementul: " << '\n';
            cin >> nr;
            my_vector.push_back(nr);
        }  
    }
    //metoda publice pentru afisare
    void afisare(){
        for(int i = 0; i < my_vector.size(); i++)
            cout << my_vector[i] << " " ;
    }
    //metoda publica pentru reactualizarea numarului de componente si initializarea componentelor cu un numar dat (primeste ca parametru numarul respectiv si numarul componentelor);
    void reactualizare(int nr_componente, int nr_dat){
        my_vector.resize(nr_componente);
        for(int i = 0; i < my_vector.size(); i++)
            my_vector[i] = nr_dat;
        n = nr_componente;
    }
    //metoda-operator public de atribuire =;
    Vector operator=(const Vector& ob){ // se copiaza in a si returnam a'u
        n = ob.n; // n'u pentru obiectu curent ( copiez n'u lu ob)
        my_vector.clear(); // stergem vectoru pentru a putea copia ob.vector
        for(int i = 0; i < ob.n; i++)
            my_vector.push_back(ob.my_vector[i]);
        return *this; // obiectu pentru care apelez yo. '*this'
    }
    //aflarea elementului maxim
    int element_maxim(){
        int max = INT_MIN;
        for (int i = 0; i < my_vector.size(); i++)
        {
            if(my_vector[i] > max)
                max = my_vector[i];
        }
            return max;//iterator, dereferentiere '*'
        //return *max_element(my_vector.begin() , my_vector.end());//iterator, dereferentiere '*'
    }
    friend Vector operator+(const Vector& ob1 , const Vector& ob2);
    friend Vector operator-(const Vector& ob1 , const Vector& ob2);
    friend Vector operator+=(Vector& ob1 , Vector& ob2);
    friend Vector operator-=(Vector& ob1, Vector& ob2);
    friend bool operator==(Vector& ob1 , Vector& ob2);
    friend bool operator!=(Vector& ob1 , Vector& ob2);
    friend int lenght(Vector);
    friend bool acceasi_dimensiune(Vector , Vector);
    int get_n(){
        return n;
    }
    //destructor
    ~Vector(){

    }
};
vector <Vector> objects;
//lungimea
int lenght(Vector ob){
    return ob.n;
}
bool acceasi_dimensiune(Vector ob1, Vector ob2){
    if(ob1.my_vector.size() != ob2.my_vector.size()){
        cout << "error 404___VECTORII NU AU ACEEASI DIMENSIUNE! :( MA) ";
        return false;
    }
    return true;
}
Vector operator+(const Vector& ob1, const Vector& ob2){
    Vector rezultat(ob1.n , ob1.my_vector);
    for(int i = 0; i < rezultat.my_vector.size(); i++)
        rezultat.my_vector[i] += ob2.my_vector[i];
    return rezultat;
}
Vector operator-(const Vector& ob1, const Vector& ob2){
    Vector rezultat(ob1.n , ob1.my_vector);
    for(int i = 0; i < rezultat.my_vector.size(); i++)
        rezultat.my_vector[i] -= ob2.my_vector[i];
    return rezultat;
}
Vector operator+=(Vector& ob1, Vector& ob2){
    ob1 = ob1 + ob2;
    return ob1;
}
Vector operator-=(Vector& ob1, Vector& ob2){
    ob1 = ob1 - ob2;
    return ob1;
}
bool operator==(Vector& ob1, Vector& ob2){
    if( !acceasi_dimensiune(ob1, ob2) )
        return false;
    for(int i = 0; i < ob1.my_vector.size(); i++)
        if ( ob1.my_vector[i] != ob2.my_vector[i] )
            return false;
    return true;   
}
bool operator!=(Vector& ob1, Vector& ob2){
    if ( ob1 == ob2 )
        return false;
    return true;
}
void maximul(){
    for (int i = 0; i < objects.size(); i++){
        cout << "Maximul din vectorul " << i + 1 << " este: ";
        cout << objects[i].element_maxim() << '\n';
    }
}
Vector suma(){
    Vector suma(objects[0]);
    for(int i = 1; i <objects.size(); i++){
        if (acceasi_dimensiune(suma, objects[i]))
            suma += objects[i];
        else{
            suma.reactualizare(0 , 0);
            return suma;
        }
    }
    return suma;
}
void lungimea(){
    for (int i = 0; i < objects.size(); i++){
        cout << "Lungimea din vectorul " << i + 1 << " este: " << lenght(objects[i]) << '\n';
    }
}
void meniu(){
    cout << "       ///.PROGRAMUL RUZEALA PENTRU COMENZILE DISPONIBILE:" << '\n';
    cout << "                        COMMAND_1: citire" << '\n';
    cout << "                        COMMAND_2: suma" << '\n';
    cout << "                        COMMAND_3: maximul" << '\n';
    cout << "                        COMMAND_4: lungime" << '\n';
    cout << "                        COMMAND_5: stop" << '\n';
}
void citire(){
    int nr_vectori;
    cout << "Numarul de vectori de citit: " << '\n';
    cin >> nr_vectori;
    for( int i = 0; i < nr_vectori; i++ ){
            Vector ob_vect;
            cout << "Vectorul " << i+1 << '\n';
            ob_vect.citire();
            objects.push_back(ob_vect);
        }
}
void bucla(){
    meniu();
    while (true){
        string s;
        cout << "Introduceti comanda: " << '\n';
        cin >> s;
        if (s == "stop")
            break;
        if (s == "suma"){
            if (suma().get_n()){
                cout << "Suma lor este: ";
                suma().afisare();
            }
            cout << '\n';            
        }
        if(s == "citire")
            citire();
        if(s == "maxim")
            maximul();
        if (s == "lungime"){
            lungimea();
            
        }

    }
}
int main(){
    bucla();
}

