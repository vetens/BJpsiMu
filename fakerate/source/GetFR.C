#include "FakeRates.h"
#include <TDirectory.h>

int main() {
TFile *file = new TFile("$DATAIN");
FakeRates* fr = new FakeRates();
gDirectory->cd("ntuplizer");
TTree* tree = (TTree*)gDirectory->Get("tree");
tree->Process(fr);
}
