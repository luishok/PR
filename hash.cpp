#include <stdio.h>
#include <iostream>
using namespace std;
int tam = 3;
class empleado{
    private:
        int ci;
        string name;
        int idE;
        int llave;
    public:
    empleado();
    ~empleado();
    int hashfunction(int key);
    void llenar(string n, int c, int id);
    void buscar(int key);
    void print();
    int showkey();
};
empleado::empleado(){
    ci = 0;
    name = " ";
    idE = 0;
    llave = 0;
}

int empleado::hashfunction(int key){
    return key % tam;
}
int empleado::showkey(){
    return llave;
}
void empleado::llenar(string n, int c, int id){
    llave = hashfunction(id);
    name = n;
    idE = id;
    ci = c;
}
void empleado::print(){
    cout << endl << "Nombre: " << name << endl;
    cout << "Numero de Cedula: " << ci << endl;
    cout << "Numero de Empleado: " << idE << endl; 
    cout << "Llave: " << llave << endl; 
}
empleado::~empleado(){
}

int main(){
    empleado prueba[tam];
    int fl = 0;
    string nombre = " ";
    int cedula = 0;
    int nroemple = 0;
    empleado aux;
    do{  
        cout << "\n--BIENVENIDO AL MENU--\nSeleccione una opcion con los numeros indicados";
        cout << "\n1)Agregar Empleados\n2)Buscar un Empleado por su numero de Empleado";
        cout << "\n3)Mostrar Empleados\n0)Salir"<< endl;
        cin >> fl;
        system("clear");
        switch(fl){
        
        case 1:
            system("clear");
            for(int i = 0; i < tam ; i++){
                cout << endl <<"Empleado Numero "<< i+1 << endl;
                cout << "=====================" << endl;
                cout << "Ingresa El Nombre: ";
                cin >> nombre;
                cout << "Ingresa su Cedula: ";
                cin >> cedula;
                cout << "Ingresa su Numero de Empleado: ";
                cin >> nroemple;
                prueba[i].llenar(nombre, cedula, nroemple);
            }
            for(int i = 0; i < tam; i++){
                for(int j; j < tam-i; j++){
                    if(prueba[j].showkey() > prueba[j+1].showkey()){
                        aux=prueba[j];
                        prueba[j] = prueba[j+1];
                        prueba[j+1] = aux;
                    }
                }
            }
            break;
        case 2:
            system("clear");
            int auxC;
            cout << "Busca un empleado por su cedula: ";
            cin >> auxC;
            for(int i = 0; i < tam; i++){
                if(prueba[i].showkey() == prueba[0].hashfunction(auxC)){
                    cout << "El empleado que estabas buscando es:" << endl;
                    prueba[i].print();
                }
            }
            
            break;
        case 3:
            system("clear");
            cout << "=====Mostrando Todos los Empleados======" << endl;
            for(int i = 0; i < tam; i++){
                prueba[i].print();
                cout << endl;
            }            
            break;
        
        default:
            break;
        }

    }while(fl!=0);

    
    return 0;
}
