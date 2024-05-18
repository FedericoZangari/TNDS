#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include "TApplication.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TCanvas.h"
#include <string>

using namespace std;

class Posizione {

    public:
  
        Posizione() { m_x = 0 ; m_y = 0 ; m_z = 0; } ;

        Posizione( double x, double y, double z ) { m_x = x; m_y=y ; m_z=z ; } ;

        double getDistance() const { return sqrt( m_x*m_x + m_y * m_y + m_z * m_z ) ;  } ;
        
        double GetX() const { return m_x ; } ;
        double GetY() const { return m_y ; } ;
        double GetZ() const { return m_z ; } ;

        double getDistance ( Posizione p ) const {     return sqrt(pow(GetX()-p.GetX(),2) + pow(GetY()-p.GetY(),2) + pow(GetZ()-p.GetZ(),2));};
        void printPositions() { cout << "Posizione : x = " << m_x << " y = " << m_y << " z = " << m_z << endl; }; 

        friend std::istream& operator>>(std::istream& is , Posizione& p ) {
            string tmp;
            std::getline(is, tmp, ',');
            p.m_x = std::stod(tmp);
            getline(is, tmp, ',');
            p.m_y = stod(tmp);
            getline(is, tmp, '\n');
            p.m_z = stod(tmp);
            return is;
        }

    private:

        double m_x, m_y, m_z ;

};

template <typename T> void bestpath (T start, T end){
    Posizione ref(0,0,0);
    for (auto it = start; it!= end; it ++){
        sort(it, end, [&] (Posizione i, Posizione j) { return i.getDistance(ref) < j.getDistance(ref); } );
        ref = *it;
    }
}

int main(int argc, char** argv){
    if ( argc < 2 ) {
  		cout << "Uso del programma : " << argv[0] << " <filename> " << endl;
    	return -1 ;
	}  
  
	TApplication app("app",0,0);

    char * filename = argv[1];
    vector<Posizione> v;

    ifstream i(filename);
    Posizione p;
    while(!i.eof()){
        i >> p;
        v.push_back(p);
    }

    for(auto it=v.begin(); it != v.end(); it++) it->printPositions();

    bestpath<vector<Posizione>::iterator>(v.begin(), v.end());

    cout << "sorted" << endl;
    for(auto it=v.begin(); it != v.end(); it++) it->printPositions();

    TCanvas c ("cammino", "cammino");
	TGraph g;
    g.SetPoint(0, 0,0  );
    int counter = 1;
    for ( auto it = v.begin() ; it != v.end() ; it++ ) {    
        g.SetPoint(counter, (*it).GetX(), (*it).GetY() );
        counter++;
    }
    

	g.Draw("ALP");
	g.SetMarkerColor(kBlue);
    g.SetMarkerSize(1);
    g.SetMarkerStyle(43);
    g.SetLineColor(kAzure);
	g.SetTitle("Cammino minimo");
	g.GetXaxis()->SetTitle("x") ;
	g.GetYaxis()->SetTitle("y") ;

	app.Run();
    return 0;
}