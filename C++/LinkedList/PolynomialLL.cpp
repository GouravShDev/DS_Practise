#include <iostream>
using namespace std;

class Term{
public:
    int coeff;
    int power;
    Term *next;

    Term(int coeff,int power){
        this->coeff = coeff;
        this->power = power;
        this->next = NULL;
    }
    Term(){
        this->next = NULL;
    }
};

class Poly{
    Term *firstTerm = NULL;

public:
    int solv(int x);
    void add(int coeff, int exp);
    void display();
    void revDisplay();

private:
    void recD(Term *p){
        if(p){
            recD(p->next);
            if(p->next) cout<<" + ";
            cout<<p->coeff<<"x"<<p->power;
            
        }
        
    }
};

int Poly::solv(int x){
    return 1;
}
void Poly::add(int coeff, int exp){
    if(firstTerm){
        Term *term = new Term(coeff, exp);
        term->next = firstTerm;
        firstTerm = term;
    }else{
        firstTerm = new Term(coeff, exp);
    }
}
void Poly::display(){
    Term *p = firstTerm;
    while(p){
        cout<<p->coeff<<"x"<<p->power;
        p = p->next;
        if(p) cout<<" + ";
    }
}
void Poly::revDisplay(){
    recD(firstTerm);
}

int main(){
    int numOfTerms, coeff, exp;
    Poly polynomial;
    cin>>numOfTerms;
    while(numOfTerms--){
        cin>>coeff>>exp;
        polynomial.add(coeff, exp);
    }
    //polynomial.display();
    polynomial.revDisplay();
    return 0;
}