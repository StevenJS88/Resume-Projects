//---------------------------------------------------------------------
// Name:    Steven Storkson
// Project: 
//
// Purpose: Prog2
//
//---------------------------------------------------------------------
#include "Catalog.h"

#ifdef CATALOG_TEST
#include <fstream>
using namespace std;

ifstream cin_redirect("P2.IN");
ofstream cout_redirect("P2.OUT");
#define cin cin_redirect
#define cout cout_redirect
#endif

Catalog::Catalog() {
}

Catalog::Catalog(const Catalog& orig) {
}

Catalog::~Catalog() {
}

