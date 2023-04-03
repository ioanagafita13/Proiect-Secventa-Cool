#include<iostream>
#include<vector>



bool Reordonare_secventa(std::vector<int> Secventa)//functie pt a reordona un sir in ordine crescatoare
{
    int aux=0;
    bool consecutiv=false;
    for (int i=0; i<(Secventa.size())-1; i++) // i merge de la primul la penultimul
    {
        for(int j=i+1; j<Secventa.size(); j++)//j merge de la al doilea la ultimul
        {
            if(Secventa[i]>Secventa[j])
            {
            aux=Secventa[i]; 
            Secventa[i]=Secventa[j];   // interschimbam pozitiile lor folosind un param auxiliar
            Secventa[j]=aux;
            }
        }
    }
    
    
    for(int i=0; i<(Secventa.size())-1; i++)//parcurgerea sirului reordonat pt a afla elem consecutive (mergem pana la penultimul elem)
    {
        if (Secventa[i+1]==Secventa[i]+1) // daca al doilea elem = primul elem + 1, s.a.m.d
        {
            consecutiv=true; 
        }
        else
        {
            consecutiv=false;
            break;
        }
    }
    return consecutiv;
}

// Functie pt a afla secventa cool si a afisa maximul, iar in caz contrar nr de elem distincte:
void Secventa_cool(std::vector<int> Subsecventa, bool isCool)  
{
    int max=Subsecventa[0]; //initializam max cu prima val din subsecventa
    int nr_elem_distincte=0;
    bool distinct=false;
    std::cout<<"subsecventa este \n";
    for(int i=0; i<Subsecventa.size(); i++)
    { // operatorul trb sa introduca de la tast o subsecventa 
        std::cout<<Subsecventa[i];
    }
  
    std::cout<<std::endl;

// algoritm pt a cauta maximul din sir
    if(isCool==true) // daca secventa este cool, se afiseaza val maxima
    {
        for(int i=0; i<Subsecventa.size(); i++)
        {
            if(max<Subsecventa[i])
            max=Subsecventa[i];
        }
        std::cout<<"Maximul este "<<max<<std::endl;
    }
    else
    { 
        for (int i=0; i<Subsecventa.size(); i++)
        {
            for(int j=0; j<Subsecventa.size(); j++)
            {
                if(Subsecventa[i]!=Subsecventa[j]) //
                distinct=true;
                else if (i!=j) //(echivalent cu if(Subsecventa[i]==Subsecventa[j]) && i!=j)                   
                {
                distinct=false;
                break;
                }
            }
            if(distinct==true)
            {
            nr_elem_distincte++; // se incrementeaza nr de elem distincte
            
            }
        }
        std::cout<<"Numarul de elemente distincte este "<<nr_elem_distincte<<std::endl;
    }
    
}

int main()
{

    int dim,k,element; 
    bool isCool_subsecventa=false;
    std::vector<int> Secventa;
    std::vector<int> Subsecventa;
    std::cout<<" Introduceti dimensiunea vectorului.\n";
    std::cin>>dim;
    std::cout<<" Introduceti dimensiunea subsecventei de verificat.\n";
    std::cin>>k;

    std::cout<<"introduceti elementele vectorului\n";
    for (int i=0; i<dim; i++)
        {
            std::cin>>element;
            Secventa.push_back(element); // adaugam element cu element in vector
        }
    std::cout<<std::endl;


    for(int i=0; i<=dim-k; i++) // dim-k=numarul de subsiruri care se pot forma dintr-un sir
    {
        for(int j=0; j<k; j++)
        {
        Subsecventa.push_back(Secventa[i+j]); //creem subsecventele
        }
        isCool_subsecventa=Reordonare_secventa(Subsecventa); // reordonam subsecventa si returnam "isCool = true/false"
        Secventa_cool(Subsecventa, isCool_subsecventa);  //afisare maxim daca secv este cool / 
        //afisare nr de elem distincte daca secv nu este cool - pt secventa Neordonata
        
        
        
        Subsecventa.clear();  // stergem toate elem pt urmatoarea iteratie
        
    }
}