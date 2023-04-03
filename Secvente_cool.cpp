#include<iostream>
#include<vector>
/*Se consideră un șir A format din N elemente naturale nenule. 
Numim secvență de lungime K a șirului A orice succesiune de elemente consecutive din șir de forma Ai, Ai+1, ..., Ai+K-1.
O secvență o numim secvență cool dacă elementele care o compun sunt distincte și pot fi rearanjate astfel încât să alcătuiască o secvență continuă de numere consecutive. 
De exemplu, considerând șirul 
A = (3, 1, 6, 8, 4, 5, 6, 7, 4, 3, 4), atunci secvența (8, 4, 5, 6, 7) este o secvență cool deoarece conține elemente distincte ce pot fi rearanjate astfel încât să alcătuiască șirul de numere consecutive 4, 5, 6, 7, 8, pe când secvențele (4, 3, 4), (6, 7, 4, 3) nu sunt considerate secvențe cool.
Cerință:
    Pentru o valoare dată K să se verifice dacă secvența A1, A2 ... AK este secvență cool. 
    Dacă secvența este cool, atunci se va afișa cea mai mare valoare ce aparține secvenței. 
    Dacă secvența nu este cool, atunci se va afișa numărul elementelor distincte din secvența 
A1, A2, ..., AK, adică numărul elementelor care apar o singură dată.
Date de intrare:
    Se citesc N și K de la tastatură care vor determina numărul de elemente din sir respectiv lungimea secvenței cool de verificat.
Exemple:
INPUT:
7 4
6 4 5 7 8 3 5
OUTPUT: 
7
Secvența 6 4 5 7 este cool.
Valoarea maximă din secvență este 7
INPUT:
7 6
6 4 5 7 5 4 3
OUTPUT:
2
Secvența 6 4 5 7 5 4 nu este secvență cool. Numărul valorilor distincte din secvență este 2. Valorile distincte sunt: 6, 7 */


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
    /*for (int i=0; i<Secventa.size(); i++)//util pt debug/explicatii
        {
            std::cout<<Secventa[i]<<" ";
        }
    std::cout<<std::endl;*/
    
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
        //std::cout<<"Elementele distincte din secventa sunt ";
        for (int i=0; i<Subsecventa.size(); i++)
        {
            for(int j=0; j<Subsecventa.size(); j++)
            {
                if(Subsecventa[i]!=Subsecventa[j]) //
                distinct=true;
                else if (i!=j) //pt a nu face comparatia elementelor de pe aceeasi pozitie pt ca oricum nu sunt distincte(echivalent cu if(Subsecventa[i]==Subsecventa[j]) && i!=j)                   
                {
                distinct=false;
                break;
                }
            }
            if(distinct==true)
            {
            nr_elem_distincte++; // se incrementeaza nr de elem distincte
            //std::cout<<Subsecventa[i]<<" ";
            }
        }
        std::cout<<"Numarul de elemente distincte este "<<nr_elem_distincte<<std::endl;
    }
    
}

int main()
{
    /*std::vector<int> vector1={5, 6, 7, 8, 8, 8};
    std::vector<int> vector2={2, 1, 3, 4, 5};
    Reordonare_secventa(vector1);
    std::cout<<Reordonare_secventa(vector1)<<std::endl;
    std::cout<<Reordonare_secventa(vector2)<<std::endl;
    Secventa_cool(vector1,0);
    Secventa_cool(vector2,1);*/

    int dim,k,element; // variabila element se fol pt introducerea de la tast a vectorului
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

    /*for(int i=0; i<Secventa.size(); i++)
    {
        std::cout<<Secventa[i];
    }
    std::cout<<std::endl; */

    for(int i=0; i<=dim-k; i++) // dim-k=numarul de subsiruri care se pot forma dintr-un sir
    {
        for(int j=0; j<k; j++)
        {
        Subsecventa.push_back(Secventa[i+j]); //creem subsecventele
        }
        isCool_subsecventa=Reordonare_secventa(Subsecventa); // reordonam subsecventa si returnam "isCool = true/false"
        Secventa_cool(Subsecventa, isCool_subsecventa);  //afisare maxim daca secv este cool / 
        //afisare nr de elem distincte daca secv nu este cool - pt secventa Neordonata
        
        
        
        Subsecventa.clear();  // stergem toate elem pt urm iteratie
        
    }
}