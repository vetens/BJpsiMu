#define GenLevel_cxx
// The class definition in GenLevel.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("GenLevel.C")
// root> T->Process("GenLevel.C","some options")
// root> T->Process("GenLevel.C+")
//


#include "GenLevel.h"
using namespace std;

void GenLevel::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
}

void GenLevel::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t GenLevel::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // When processing keyed objects with PROOF, the object is already loaded
   // and is available via the fObject pointer.
   //
   // This function should contain the \"body\" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

   fReader.SetEntry(entry);
   GetEntry(entry);

// Get the number of unique B's that appear in the event. Not counting B0->B0bar & hc as decays, 
// which is the only B decay which would have just one daughter. Also, only interested in Bs for
// whom one of the daughters is a J/psi.
// Store the Gen Level B masses to a histogram for lookin at later
// Now, for each reco jpsi, we fill the trimu reco histogram, then look through each gen. 
// if there is a generator where B->j/psi+x, we fill the reco trimu mass histo for that b. 
// if X=mu+x, we also fill a reco trimu mass histo. Otherwise if X=k+x or pi+x, we compare the highest pt
// pi and k from the event at gen level. If the pi has higher pt we fill our pi histo with the reco
// trimu mass, and if the k has a higher pt we fill our k histo with the reco trimu mass

for (int iJpsi=0; iJpsi<(int)Jpsi_trimu_mass.GetSize(); iJpsi++) {
    trimu->Fill(Jpsi_trimu_mass.At(iJpsi));
    for (int iGen=0; iGen<(int)genParticle_pdgId.GetSize(); iGen++) {
               bool kpi = 0;
               if (TMath::Abs(genParticle_pdgId.At(iGen))==Bvec[0]) {
                  b0mass->Fill(genParticle_mass.At(iGen));
                  for (int iDau = 0; iDau<(int)genParticle_dau.At(iGen).size(); iDau++) {
                      if ( genParticle_dau.At(iGen).at(iDau) == jpsipdgid ) {
                         b0trimu->Fill(Jpsi_trimu_mass.At(iJpsi));
                         for (int iDau2 = 0; iDau2<(int)genParticle_dau.At(iGen).size(); iDau2++) {
                             if (TMath::Abs(genParticle_dau.At(iGen).at(iDau2)) == muonpdgid) {
                                mutrimu->Fill(Jpsi_trimu_mass.At(iJpsi));
                                kpi = 0;
                                break;
                                }
                             else if (TMath::Abs(genParticle_dau.At(iGen).at(iDau2)) == pipluspdgid || TMath::Abs(genParticle_dau.At(iGen).at(iDau2)) == kpluspdgid) {
                                kpi = 1;
                                }
                              }
                         }
                      }
                  }
               else if (TMath::Abs(genParticle_pdgId.At(iGen))==Bvec[1]) {
                       bpmass->Fill(genParticle_mass.At(iGen));
                  for (int iDau = 0; iDau<(int)genParticle_dau.At(iGen).size(); iDau++) {
                      if ( genParticle_dau.At(iGen).at(iDau) == jpsipdgid ) {
                         bptrimu->Fill(Jpsi_trimu_mass.At(iJpsi));
                         for (int iDau2 = 0; iDau2<(int)genParticle_dau.At(iGen).size(); iDau2++) {
                             if (TMath::Abs(genParticle_dau.At(iGen).at(iDau2)) == muonpdgid) {
                                mutrimu->Fill(Jpsi_trimu_mass.At(iJpsi));
                                kpi = 0;
                                break;
                                }
                             else if (TMath::Abs(genParticle_dau.At(iGen).at(iDau2)) == pipluspdgid || TMath::Abs(genParticle_dau.At(iGen).at(iDau2)) == kpluspdgid) {
                                kpi = 1;
                                }
                              }
                         }
                       }
                      }
               else if (TMath::Abs(genParticle_pdgId.At(iGen))==Bvec[2]) {
                       bsmass->Fill(genParticle_mass.At(iGen));
                  for (int iDau = 0; iDau<(int)genParticle_dau.At(iGen).size(); iDau++) {
                      if ( genParticle_dau.At(iGen).at(iDau) == jpsipdgid ) {
                         bstrimu->Fill(Jpsi_trimu_mass.At(iJpsi));
                         for (int iDau2 = 0; iDau2<(int)genParticle_dau.At(iGen).size(); iDau2++) {
                             if (TMath::Abs(genParticle_dau.At(iGen).at(iDau2)) == muonpdgid) {
                                mutrimu->Fill(Jpsi_trimu_mass.At(iJpsi));
                                kpi = 0;
                                break;
                                }
                             else if (TMath::Abs(genParticle_dau.At(iGen).at(iDau2)) == pipluspdgid || TMath::Abs(genParticle_dau.At(iGen).at(iDau2)) == kpluspdgid) {
                                kpi = 1;
                                }
                              }
                         }
                       }
                      }
               else if (TMath::Abs(genParticle_pdgId.At(iGen))==Bvec[3]) {
                       bcmass->Fill(genParticle_mass.At(iGen));
                  for (int iDau = 0; iDau<(int)genParticle_dau.At(iGen).size(); iDau++) {
                      if ( genParticle_dau.At(iGen).at(iDau) == jpsipdgid ) {
                         bctrimu->Fill(Jpsi_trimu_mass.At(iJpsi));
                         for (int iDau2 = 0; iDau2<(int)genParticle_dau.At(iGen).size(); iDau2++) {
                             if (TMath::Abs(genParticle_dau.At(iGen).at(iDau2)) == muonpdgid) {
                                mutrimu->Fill(Jpsi_trimu_mass.At(iJpsi));
                                kpi = 0;
                                break;
                                }
                             else if (TMath::Abs(genParticle_dau.At(iGen).at(iDau2)) == pipluspdgid || TMath::Abs(genParticle_dau.At(iGen).at(iDau2)) == kpluspdgid) {
                                kpi = 1;
                                }
                              }
                         }
                       }
                      }
               if (kpi) {
                  double kpt = 0; 
                  double pipt = 0;
                  for (int iGen2 = 0; iGen2<(int)genParticle_pdgId.GetSize(); iGen2++) {
                      if (TMath::Abs(genParticle_pdgId.At(iGen2)) == pipluspdgid && genParticle_pt.At(iGen2) > pipt) {
                         pipt = genParticle_pt.At(iGen2);
                         }
                      else if (TMath::Abs(genParticle_pdgId.At(iGen2)) == kpluspdgid && genParticle_pt.At(iGen2) > kpt) {
                         kpt = genParticle_pt.At(iGen2);
                         }
                      }
                  if (kpt>pipt) {ktrimu->Fill(Jpsi_trimu_mass.At(iJpsi));}
                  else {pitrimu->Fill(Jpsi_trimu_mass.At(iJpsi));}
                  }
               }
        }

   return kTRUE;
}

void GenLevel::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void GenLevel::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

TFile genlevel("$DATAOUT/genlevel.root", "RECREATE");

genlevel.cd();

TCanvas* xcompare = new TCanvas("xcompare", "xcompare", 1);

trimu->SetLineColor(kBlack);
trimu->GetXaxis()->SetTitle("m (GeV)");
trimu->GetYaxis()->SetTitle("Number of Events");
mutrimu->SetLineColor(kViolet);
pitrimu->SetLineColor(kTeal);
ktrimu->SetLineColor(kOrange);

auto legendxcompare = new TLegend();
legendxcompare->SetHeader("Legend", "C");
legendxcompare->AddEntry(trimu, "Total");
legendxcompare->AddEntry(mutrimu, "B->J/#psi+#mu^{#pm}+#nu+X");
legendxcompare->AddEntry(pitrimu, "B->J/#psi+#pi^{#pm}+X");
legendxcompare->AddEntry(ktrimu, "B->J/#psi+K^{#pm}+X");

xcompare->cd();
trimu->Draw();
mutrimu->Draw("SAME");
pitrimu->Draw("SAME");
ktrimu->Draw("SAME");
legendxcompare->Draw("SAME");
xcompare->Write();

TCanvas* bcompare = new TCanvas("mucompare", "mucompare", 1);

b0trimu->SetLineColor(kRed);
bptrimu->SetLineColor(kCyan);
bstrimu->SetLineColor(kBlue);
bctrimu->SetLineColor(kYellow);
b0mass->SetLineColor(kRed);
b0mass->SetLineStyle(10);
bpmass->SetLineColor(kCyan);
bpmass->SetLineStyle(10);
bsmass->SetLineColor(kBlue);
bsmass->SetLineStyle(10);
bcmass->SetLineColor(kYellow);
bcmass->SetLineStyle(10);

dummy1->SetLineColor(kBlack);
dummy1->SetLineStyle(10);
dummy2->SetLineColor(kBlack);

auto legendbcompare = new TLegend();
legendbcompare->SetHeader("Legend", "C");
legendbcompare->AddEntry(dummy2, "Reco Visible Mass");
legendbcompare->AddEntry(dummy1, "Gen Level Mass");
legendbcompare->AddEntry(trimu, "Total");
legendbcompare->AddEntry(b0trimu, "B^{0}");
legendbcompare->AddEntry(bptrimu, "B^{#pm}");
legendbcompare->AddEntry(bstrimu, "B_{s}^{0}");
legendbcompare->AddEntry(bctrimu, "B_{c}^{#pm}");

bcompare->cd();
trimu->Draw();
b0trimu->Draw("SAME");
bptrimu->Draw("SAME");
bstrimu->Draw("SAME");
bctrimu->Draw("SAME");
b0mass->Draw("SAME");
bpmass->Draw("SAME");
bsmass->Draw("SAME");
bcmass->Draw("SAME");
legendbcompare->Draw("SAME");
bcompare->Write();


genlevel.Write();
}
