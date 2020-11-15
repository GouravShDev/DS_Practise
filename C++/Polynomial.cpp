#include <iostream>
#include <cmath>

using namespace std;

class Terms{

public:
    int coeff;
    int exp;
};

class Polynomial{
    int num;
    Terms *t;

public:
    Polynomial(int num){
        this->num = num;
        t = new Terms[num];
    }
    friend istream & operator >>(istream &is, Polynomial &p);
    friend ostream & operator <<(ostream &os, Polynomial &p);
    int solve(int x);
    Polynomial operator+(Polynomial pol);
};

istream & operator >>(istream &is, Polynomial &p){
    int i;
    for(i = 0; i< p.num; i++){
        cin>>p.t[i].coeff>>p.t[i].exp;
    }
    return is;
}

ostream & operator <<(ostream &os, Polynomial &p){
    int i;
    for(i=0 ; i <p.num; i++){
        cout<<p.t[i].coeff<<"x"<<p.t[i].exp;
        if(i != p.num - 1) cout<<" + ";
    }
    return os;
}

Polynomial Polynomial::operator+(Polynomial pol){
    int i,j,k;
    Polynomial *sum = new Polynomial(num + pol.num);
    i=j=k=0;

    while(i<num && j < pol.num){
        if(t[i].exp > pol.t[j].exp)
            sum->t[k++] = t[i++];
        else if(t[i].exp < pol.t[j].exp)
            sum->t[k++] = pol.t[j++];
        else{
            sum->t[k] = t[i];
            sum->t[k++].coeff = t[i++].coeff + pol.t[j++].coeff;
        }
    }
    for(;i<num;i++){
        sum->t[k++] = t[i++]; 
    }
    for(;j<pol.num;j++){
        sum->t[k++] = pol.t[j++];
    }
    sum->num = k;
    return *sum; 
     
}

int Polynomial::solve(int x){
    int i;
    int sum = 0;
    for(i=0; i < num; i++){
        sum = sum + t[i].coeff * pow(x,t[i].exp);
    }
    return sum;
}

int main(){
    Polynomial poly(4);
    Polynomial poly2(5);
    cout<<"Enter First Polynomial\n";
    cin>>poly;
    cout<<"Enter Second Polynomial\n";
    cin>>poly2;

    cout<<"First Polynomial\n";
    cout<<poly<<endl;
    cout<<"Second Polynomial\n";
    cout<<poly2<<endl;

    Polynomial sum = poly + poly2;
    cout<<"\nSum of Polynomial\n"<<sum;
    return 0;
}