#include "GenLevel.h"
#include <TDirectory.h>

int main() {
TFile *file = new TFile("$DATAIN");
GenLevel* gl = new GenLevel();
gDirectory->cd("ntuplizer");
TTree* tree = (TTree*)gDirectory->Get("tree");
tree->Process(gl);
}
