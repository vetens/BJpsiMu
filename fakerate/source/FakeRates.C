#define FakeRates_cxx
// The class definition in FakeRates.h has been generated automatically
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
// root> T.Process("FakeRates.C")
// root> T.Process("FakeRates.C","some options")
// root> T.Process("FakeRates.C+")
//


#include "FakeRates.h"
using namespace std;

void FakeRates::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
}

void FakeRates::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t FakeRates::Process(Long64_t entry)
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

for(int iJpsi=0; iJpsi<(int)Jpsi_mu3_pt.GetSize(); iJpsi++) {

TLorentzVector mu3;
mu3.SetPtEtaPhiM(Jpsi_mu3_pt.At(iJpsi),Jpsi_mu3_eta.At(iJpsi),Jpsi_mu3_phi.At(iJpsi),mumass);

for (int iGen=0; iGen<(int)genParticle_pdgId.GetSize(); iGen++) {
// find out if gen particle is the daughter of a B
    int isbdau = 0;
    for (unsigned int iB=0; iB<momvec.size(); iB++) {
        for (int iMom=0; iMom<(int)genParticle_mother.At(iGen).size(); iMom++) {
            if (TMath::Abs(genParticle_mother.At(iGen).at(iMom)) == momvec[iB]) {
               isbdau = 1;
               }
            }
        }
// If it's the daughter of a B and of status 1 (i.e. asymptotic), we check if it's a pi or k 
// and get its pT and eta. Then we see if it is a Delta R match with the reconstructed third muon. 
// If it is, then we save its pt and eta to our subset histograms, and calculate the resolution in
// pt and eta with the reco third muon.
    if (isbdau == 1 && genParticle_status.At(iGen) == 1) {
       if (TMath::Abs(genParticle_pdgId.At(iGen)) == PiPlusPDGID) {
          pipthist->Fill(genParticle_pt.At(iGen));    
          pietahist->Fill(genParticle_eta.At(iGen));    
          TLorentzVector pi;
          pi.SetPtEtaPhiM(genParticle_pt.At(iGen),genParticle_eta.At(iGen),genParticle_phi.At(iGen),genParticle_mass.At(iGen));
          if (pi.DeltaR(mu3) < DeltaRLimit) {
             pidrpthist->Fill(pi.Pt());
             pidretahist->Fill(pi.Eta());
             piptresohist->Fill((mu3.Pt()-pi.Pt())/pi.Pt());
             pietaresohist->Fill((mu3.Eta()-pi.Eta())/pi.Eta());
             piresvsp->Fill(mu3.Pt()/pi.Pt(),pi.Pt());
             }
          }
       else if (TMath::Abs(genParticle_pdgId.At(iGen)) == KPlusPDGID) {
          kpthist->Fill(genParticle_pt.At(iGen));    
          ketahist->Fill(genParticle_eta.At(iGen));    
          TLorentzVector k;
          k.SetPtEtaPhiM(genParticle_pt.At(iGen),genParticle_eta.At(iGen),genParticle_phi.At(iGen),genParticle_mass.At(iGen));
          if (k.DeltaR(mu3) < DeltaRLimit) {
             kdrpthist->Fill(k.Pt());
             kdretahist->Fill(k.Eta());
             kptresohist->Fill((mu3.Pt()-k.Pt())/k.Pt());
             ketaresohist->Fill((mu3.Eta()-k.Eta())/k.Eta());
             kresvsp->Fill(mu3.Pt()/k.Pt(),k.Pt());
             }
          }
       }
}
}
   return kTRUE;
}

void FakeRates::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed-> When running with PROOF SlaveTerminate() is called
   // on each slave server->

}

void FakeRates::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query-> It always runs on the client, it can be used to present
   // the results graphically or save the results to file->
piptfake = new TEfficiency(*pidrpthist,*pipthist);
piptfake->SetTitle("Per #pi fake rate for #pi^{#pm}:#mu in B->J/#psi+X; Generator p_{T} (GeV); Fake Rate");
pietafake = new TEfficiency(*pidretahist,*pietahist);
pietafake->SetTitle("Per #pi fake rate for #pi^{#pm}:#mu in B->J/#psi+X; Generator #eta (GeV); Fake Rate");
kptfake = new TEfficiency(*kdrpthist,*kpthist);
kptfake->SetTitle("Per K fake rate for K^{#pm}:#mu in B->J/#psi+X; Generator p_{T} (GeV); Fake Rate");
ketafake = new TEfficiency(*kdretahist,*ketahist);
ketafake->SetTitle("Per K fake rate for K^{#pm}:#mu in B->J/#psi+X; Generator #eta (GeV); Fake Rate");

TFile fakerates("$DATAOUT/fakerates.root", "RECREATE");

fakerates.cd();

piptfake->Write("piptfake");
pietafake->Write("pietafake");
kptfake->Write("kptfake");
ketafake->Write("ketafake");

//TCanvas* piptfr = new TCanvas("piptfr", "piptfr", 1);
//piptfr->Draw();
//piptfake->Draw("E1");
//piptfr->Write();
//TCanvas* pietafr = new TCanvas("pietafr", "pietafr", 1);
//pietafr->Draw();
//pietafake->Draw("E1");
//pietafr->Write();
//TCanvas* kptfr = new TCanvas("kptfr", "kptfr", 1);
//kptfr->Draw();
//kptfake->Draw("E1");
//kptfr->Write();
//TCanvas* ketafr = new TCanvas("ketafr", "ketafr", 1);
//ketafr->Draw();
//ketafake->Draw("E1");
//ketafr->Write();

TCanvas* piptreso = new TCanvas("piptreso", "piptreso", 1);
piptresohist->Draw("E1");
piptreso->Write();
TCanvas* pietareso = new TCanvas("pietareso", "pietareso", 1);
pietaresohist->Draw("E1");
pietareso->Write();
TCanvas* kptreso = new TCanvas("kptreso", "kptreso", 1);
kptresohist->Draw("E1");
kptreso->Write();
TCanvas* ketareso = new TCanvas("ketareso", "ketareso", 1);
ketaresohist->Draw("E1");
ketareso->Write();

TCanvas* piresvspcanv = new TCanvas("piresvspcanv", "piresvspcanv", 1);
piresvsp->GetXaxis()->SetTitle("p_{T}(#pi_{G})");
piresvsp->GetYaxis()->SetTitle("#frac{p_{T}(#mu_{R})}{p_{T}(#pi_{G})}");
piresvsp->Draw();
piresvspcanv->Write();
TCanvas* kresvspcanv = new TCanvas("kresvspcanv", "kresvspcanv", 1);
kresvsp->GetXaxis()->SetTitle("p_{T}(K_{G})");
kresvsp->GetYaxis()->SetTitle("#frac{p_{T}(#mu_{R})}{p_{T}(K_{G})}");
kresvsp->Draw();
kresvspcanv->Write();
fakerates.Write();
}
