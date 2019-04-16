#include <iostream>

using namespace std;

class Graf
{
protected:
    int nr_noduri;
public:
        //virtual int Arce()=0;
        void alocareGraf();
        Graf();
        Graf(int nr_n);
        Graf(const Graf &gr);
        ~Graf();
        void operator=(const Graf &gr);
        friend istream& operator>>(std::istream& in, Graf &gr);
        friend ostream& operator<<(std::ostream& out, Graf &gr);
};
Graf::Graf()
{
    this->nr_noduri=0;
}
Graf::Graf(int nr_n)
{
    this->nr_noduri=nr_n;
    alocareGraf();
}
Graf::Graf(const Graf &gr)
{
    this->nr_noduri=gr.nr_noduri;
    alocareGraf();
}
void Graf::alocareGraf()
{
    this->nr_noduri=0;
}
Graf::~Graf()
{
    delete &nr_noduri;
}
void Graf::operator=(const Graf &gr)
{
    this->nr_noduri=gr.nr_noduri;
    alocareGraf();
}
std::istream& operator >>(std::istream& in, Graf &gr)
{
    int nr=0;
    in>>nr;
    gr.nr_noduri=nr;
    return in;
}
std::ostream& operator <<(std::ostream& out, Graf &gr)
{
    out<<gr.nr_noduri;
    return out;
}
class Matrice: Graf
{
protected:
    int **a;
public:
        void alocareMatrice();
        friend istream& operator>>(std::istream& in, Matrice &mat);
        friend ostream& operator<<(std::ostream& out, Matrice &mat);
        Matrice();
        Matrice(int nr_n)
        {
            this->nr_noduri=nr_n;
            this->alocareMatrice();
        };
        Matrice(const Matrice &mat);
        ~Matrice();
        void operator=(const Matrice &mat);
};
Matrice::Matrice()
{
    this->nr_noduri=0;
    this->a=0;
}
Matrice::Matrice(const Matrice &mat)
{
    this->nr_noduri=mat.nr_noduri;
    this->alocareGraf();
    this->a=mat.a;
    this->alocareMatrice();
}
void Matrice::alocareMatrice()
{
 a=new int*[nr_noduri];
    for(int i=0;i<nr_noduri;i++)
        a[i]=new int[nr_noduri];
    for(int i=0;i<nr_noduri;i++)
        for(int j=0;j<nr_noduri;j++)
            a[i][j]=0;
}
void Matrice::operator=(const Matrice &mat)
{
    this->nr_noduri=mat.nr_noduri;
    alocareGraf();
    this->a=mat.a;
    alocareMatrice();
}
Matrice::~Matrice()
{
    delete []a;
}
std::istream& operator >>(std::istream &in,Matrice &mat)
{

    int nr=0;
    for(int i=0;i<mat.nr_noduri;i++)
    {
        for(int j=0;j<mat.nr_noduri;j++)
        {
            in>>nr;
            mat.a[i][j]=nr;
        }
    }
    return in;
}
std::ostream& operator <<(std::ostream &out,Matrice &mat)
{
        out<<mat;
    return out;
}
class Graf_complet: Graf
{
protected:
    int nr_muchii;
public:
    Graf_complet();
    Graf_complet(int nr_m);
    Graf_complet(const Graf_complet &gr);
    ~Graf_complet();
    void alocareGraf_complet();
    friend istream& operator>>(std::istream& in, Graf_complet &gr);
    friend ostream& operator<<(std::ostream& out, Graf_complet &gr);

};
Graf_complet::Graf_complet()
{
    this->nr_muchii=0;
    this->nr_noduri=0;
}
Graf_complet::Graf_complet(int nr_m)
{
    this->nr_muchii=nr_m;
    this->nr_noduri=2*this->nr_muchii+1;
    alocareGraf_complet();

}
Graf_complet::Graf_complet(const Graf_complet &gr)
{
    this->nr_muchii=gr.nr_muchii;
    alocareGraf_complet();
}
void Graf_complet::alocareGraf_complet()
{
    this->nr_muchii=0;
}
Graf_complet::~Graf_complet()
{
    delete &nr_muchii;
}
class Graf_antisimetric: Graf
{
protected:
     Matrice M;
public:
    Graf_antisimetric();
    Graf_antisimetric(Matrice mat);
    Graf_antisimetric(const Graf_antisimetric &mat);
    ~Graf_antisimetric();
    void operator=(const Graf_antisimetric &mat);
    void alocareGraf_antisimetric();
    friend istream& operator>>(std::istream& in, Graf_antisimetric &mat);
    friend ostream& operator<<(std::ostream& out, Graf_antisimetric &mat);


};
Graf_antisimetric::Graf_antisimetric()
{
    this->nr_noduri=0;
    this->M=0;
}
Graf_antisimetric::Graf_antisimetric(Matrice mat)
{
          this->M=mat;
            this->alocareGraf_antisimetric();
}
Graf_antisimetric::Graf_antisimetric(const Graf_antisimetric &mat)
{
    this->M=mat.M;
    alocareGraf_antisimetric();
}
void Graf_antisimetric::alocareGraf_antisimetric()
{
    this->M=0;
}
Graf_antisimetric::~Graf_antisimetric()
{
    delete &M;
}
std::istream& operator >>(std::istream &in,Graf_antisimetric &mat)
{
    in>>mat;
    return in;
}
std::ostream& operator<<(std::ostream& out, Graf_antisimetric &mat)
{
    out<<mat;
    return out;
}
void Graf_antisimetric::operator=(const Graf_antisimetric &mat)
{
    this->M=mat.M;
    alocareGraf_antisimetric();
}
class Graf_turneu: Graf_complet, Graf_antisimetric
{
protected:
    int nr_muchii;
    Matrice M;
public:
    Graf_turneu();
    Graf_turneu(int nr_m, Matrice mat);
    Graf_turneu(const Graf_turneu &mat);
    void alocareGraf_turneu();
    ~Graf_turneu();
    void operator=(const Graf_turneu &mat);
    friend istream& operator>>(std::istream& in, Graf_turneu &mat);
    friend ostream& operator<<(std::ostream& out, Graf_turneu &mat);
};
Graf_turneu::Graf_turneu()
{
    this->nr_muchii=0;
    this->M=0;
}
Graf_turneu::Graf_turneu(int nr_m, Matrice mat)
{
    this->nr_muchii=nr_m;
    this->M=mat;
    alocareGraf_turneu();
}
Graf_turneu::Graf_turneu(const Graf_turneu &mat)
{
    this->nr_muchii=mat.nr_muchii;
    this->M=mat.M;
    alocareGraf_turneu();
}
void Graf_turneu::alocareGraf_turneu()
{
    this->M=0;
    this->nr_muchii=0;
    alocareGraf_antisimetric();
    alocareGraf_complet();
}
Graf_turneu::~Graf_turneu()
{
    delete &nr_muchii;
    delete &M;
}
std::istream& operator >>(std::istream &in,Graf_turneu &mat)
{
    in>>mat;
    return in;
}
std::ostream& operator<<(std::ostream& out, Graf_turneu &mat)
{
    out<<mat;
    return out;
}
void Graf_turneu::operator=(const Graf_turneu &mat)
{
    this->M=mat.M;
    this->nr_muchii=mat.nr_muchii;
    alocareGraf_turneu();
}
int main()
{

}
