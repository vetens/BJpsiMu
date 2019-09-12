//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Sep 11 16:27:40 2019 by ROOT version 6.12/07
// from TTree tree/tree
// found on file: data/in/Urs.root
//////////////////////////////////////////////////////////

#ifndef GenLevel_h
#define GenLevel_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>
#include <TH2.h>
#include <TStyle.h>
#include <TLorentzVector.h>
#include <TCanvas.h>
#include <THistPainter.h>
#include <TLegend.h>
#include <TH1D.h>
#include <TAxis.h>
#include <TLatex.h>

// Headers needed by this particular selector
#include <vector>

#include <map>

#include <string>

using namespace std;



class GenLevel : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
//   TTreeReaderValue<Int_t> genParticle_N = {fReader, "genParticle_N"};
   TTreeReaderArray<float> genParticle_pt = {fReader, "genParticle_pt"};
   TTreeReaderArray<float> genParticle_eta = {fReader, "genParticle_eta"};
   TTreeReaderArray<float> genParticle_phi = {fReader, "genParticle_phi"};
   TTreeReaderArray<float> genParticle_mass = {fReader, "genParticle_mass"};
   TTreeReaderArray<int> genParticle_pdgId = {fReader, "genParticle_pdgId"};
   TTreeReaderArray<int> genParticle_status = {fReader, "genParticle_status"};
//   TTreeReaderArray<int> genParticle_isPrompt = {fReader, "genParticle_isPrompt"};
//   TTreeReaderArray<int> genParticle_isDirectPromptTauDecayProduct = {fReader, "genParticle_isDirectPromptTauDecayProduct"};
//   TTreeReaderArray<int> genParticle_isDirectHardProcessTauDecayProductFinalState = {fReader, "genParticle_isDirectHardProcessTauDecayProductFinalState"};
//   TTreeReaderArray<int> genParticle_fromHardProcessFinalState = {fReader, "genParticle_fromHardProcessFinalState"};
   TTreeReaderArray<vector<int>> genParticle_mother = {fReader, "genParticle_mother"};
//   TTreeReaderArray<int> genParticle_nMoth = {fReader, "genParticle_nMoth"};
//   TTreeReaderArray<int> genParticle_nDau = {fReader, "genParticle_nDau"};
   TTreeReaderArray<vector<int>> genParticle_dau = {fReader, "genParticle_dau"};
//   TTreeReaderArray<float> genParticle_tauvispt = {fReader, "genParticle_tauvispt"};
//   TTreeReaderArray<float> genParticle_tauviseta = {fReader, "genParticle_tauviseta"};
//   TTreeReaderArray<float> genParticle_tauvisphi = {fReader, "genParticle_tauvisphi"};
//   TTreeReaderArray<float> genParticle_tauvismass = {fReader, "genParticle_tauvismass"};
//   TTreeReaderArray<int> genParticle_taudecay = {fReader, "genParticle_taudecay"};
//   TTreeReaderValue<Float_t> lheV_pt = {fReader, "lheV_pt"};
//   TTreeReaderValue<Float_t> lheHT = {fReader, "lheHT"};
//   TTreeReaderValue<Int_t> lheNj = {fReader, "lheNj"};
//   TTreeReaderValue<Int_t> lheNb = {fReader, "lheNb"};
//   TTreeReaderValue<Int_t> lheNl = {fReader, "lheNl"};
//   TTreeReaderValue<Float_t> lheV_mass = {fReader, "lheV_mass"};
//   TTreeReaderValue<Float_t> genWeight = {fReader, "genWeight"};
//   TTreeReaderValue<Float_t> genFacWeightUp = {fReader, "genFacWeightUp"};
//   TTreeReaderValue<Float_t> genFacWeightDown = {fReader, "genFacWeightDown"};
//   TTreeReaderValue<Float_t> genRenWeightUp = {fReader, "genRenWeightUp"};
//   TTreeReaderValue<Float_t> genRenWeightDown = {fReader, "genRenWeightDown"};
//   TTreeReaderValue<Float_t> genFacRenWeightUp = {fReader, "genFacRenWeightUp"};
//   TTreeReaderValue<Float_t> genFacRenWeightDown = {fReader, "genFacRenWeightDown"};
//   TTreeReaderValue<Float_t> qScale = {fReader, "qScale"};
//   TTreeReaderValue<Float_t> PDF_rms = {fReader, "PDF_rms"};
//   TTreeReaderArray<float> PDF_x = {fReader, "PDF_x"};
//   TTreeReaderArray<float> PDF_xPDF = {fReader, "PDF_xPDF"};
//   TTreeReaderArray<int> PDF_id = {fReader, "PDF_id"};
//   TTreeReaderValue<Int_t> genJetAK4_N = {fReader, "genJetAK4_N"};
//   TTreeReaderArray<float> genJetAK4_pt = {fReader, "genJetAK4_pt"};
//   TTreeReaderArray<float> genJetAK4_eta = {fReader, "genJetAK4_eta"};
//   TTreeReaderArray<float> genJetAK4_mass = {fReader, "genJetAK4_mass"};
//   TTreeReaderArray<float> genJetAK4_phi = {fReader, "genJetAK4_phi"};
//   TTreeReaderArray<float> genJetAK4_e = {fReader, "genJetAK4_e"};
//   TTreeReaderArray<float> genJetNoNuAK4_pt = {fReader, "genJetNoNuAK4_pt"};
//   TTreeReaderArray<float> genJetNoNuAK4_mass = {fReader, "genJetNoNuAK4_mass"};
//   TTreeReaderArray<float> genJetNoNuAK4_e = {fReader, "genJetNoNuAK4_e"};
//   TTreeReaderValue<Int_t> genJetAK8_N = {fReader, "genJetAK8_N"};
//   TTreeReaderArray<float> genJetAK8_pt = {fReader, "genJetAK8_pt"};
//   TTreeReaderArray<float> genJetAK8_eta = {fReader, "genJetAK8_eta"};
//   TTreeReaderArray<float> genJetAK8_mass = {fReader, "genJetAK8_mass"};
//   TTreeReaderArray<float> genJetAK8_phi = {fReader, "genJetAK8_phi"};
//   TTreeReaderArray<float> genJetAK8_e = {fReader, "genJetAK8_e"};
//   TTreeReaderArray<float> genJetAK8_prunedmass = {fReader, "genJetAK8_prunedmass"};
//   TTreeReaderArray<float> genJetAK8_softdropmass = {fReader, "genJetAK8_softdropmass"};
//   TTreeReaderArray<pair<string,bool>> HLT_isFired = {fReader, "HLT_isFired"};
//   TTreeReaderArray<float> triggerObject_pt = {fReader, "triggerObject_pt"};
//   TTreeReaderArray<float> triggerObject_eta = {fReader, "triggerObject_eta"};
//   TTreeReaderArray<float> triggerObject_phi = {fReader, "triggerObject_phi"};
//   TTreeReaderArray<float> triggerObject_mass = {fReader, "triggerObject_mass"};
//   TTreeReaderArray<string> triggerObject_lastname = {fReader, "triggerObject_lastname"};
//   TTreeReaderArray<pair<string,vector<string> >> triggerObject_filterLabels = {fReader, "triggerObject_filterLabels"};
//   TTreeReaderArray<vector<int>> triggerObject_firedTrigger = {fReader, "triggerObject_firedTrigger"};
//   TTreeReaderArray<vector<float>> triggerObject_filterIDs = {fReader, "triggerObject_filterIDs"};
//   TTreeReaderValue<Bool_t> passFilter_HBHE_ = {fReader, "passFilter_HBHE"};
//   TTreeReaderValue<Bool_t> passFilter_HBHELoose_ = {fReader, "passFilter_HBHELoose"};
//   TTreeReaderValue<Bool_t> passFilter_HBHETight_ = {fReader, "passFilter_HBHETight"};
//   TTreeReaderValue<Bool_t> passFilter_HBHEIso_ = {fReader, "passFilter_HBHEIso"};
//   TTreeReaderValue<Bool_t> passFilter_CSCHalo_ = {fReader, "passFilter_CSCHalo"};
//   TTreeReaderValue<Bool_t> passFilter_CSCTightHalo2015_ = {fReader, "passFilter_CSCTightHalo2015"};
//   TTreeReaderValue<Bool_t> passFilter_HCALlaser_ = {fReader, "passFilter_HCALlaser"};
//   TTreeReaderValue<Bool_t> passFilter_ECALDeadCell_ = {fReader, "passFilter_ECALDeadCell"};
//   TTreeReaderValue<Bool_t> passFilter_GoodVtx_ = {fReader, "passFilter_GoodVtx"};
//   TTreeReaderValue<Bool_t> passFilter_TrkFailure_ = {fReader, "passFilter_TrkFailure"};
//   TTreeReaderValue<Bool_t> passFilter_EEBadSc_ = {fReader, "passFilter_EEBadSc"};
//   TTreeReaderValue<Bool_t> passFilter_ECALlaser_ = {fReader, "passFilter_ECALlaser"};
//   TTreeReaderValue<Bool_t> passFilter_TrkPOG_ = {fReader, "passFilter_TrkPOG"};
//   TTreeReaderValue<Bool_t> passFilter_TrkPOG_manystrip_ = {fReader, "passFilter_TrkPOG_manystrip"};
//   TTreeReaderValue<Bool_t> passFilter_TrkPOG_toomanystrip_ = {fReader, "passFilter_TrkPOG_toomanystrip"};
//   TTreeReaderValue<Bool_t> passFilter_TrkPOG_logError_ = {fReader, "passFilter_TrkPOG_logError"};
//   TTreeReaderValue<Bool_t> passFilter_METFilters_ = {fReader, "passFilter_METFilters"};
//   TTreeReaderValue<Bool_t> passFilter_CSCTightHaloTrkMuUnvetoFilter_ = {fReader, "passFilter_CSCTightHaloTrkMuUnvetoFilter"};
//   TTreeReaderValue<Bool_t> passFilter_globalTightHalo2016_ = {fReader, "passFilter_globalTightHalo2016"};
//   TTreeReaderValue<Bool_t> passFilter_globalSuperTightHalo2016_ = {fReader, "passFilter_globalSuperTightHalo2016"};
//   TTreeReaderValue<Bool_t> passFilter_HcalStripHalo_ = {fReader, "passFilter_HcalStripHalo"};
//   TTreeReaderValue<Bool_t> passFilter_chargedHadronTrackResolution_ = {fReader, "passFilter_chargedHadronTrackResolution"};
//   TTreeReaderValue<Bool_t> passFilter_muonBadTrack_ = {fReader, "passFilter_muonBadTrack"};
//   TTreeReaderValue<Bool_t> flag_badMuons_ = {fReader, "flag_badMuons"};
//   TTreeReaderValue<Bool_t> flag_duplicateMuons_ = {fReader, "flag_duplicateMuons"};
//   TTreeReaderValue<Bool_t> flag_nobadMuons_ = {fReader, "flag_nobadMuons"};
//   TTreeReaderArray<float> METraw_et = {fReader, "METraw_et"};
//   TTreeReaderArray<float> METraw_phi = {fReader, "METraw_phi"};
//   TTreeReaderArray<float> METraw_sumEt = {fReader, "METraw_sumEt"};
//   TTreeReaderArray<float> MET_corrPx = {fReader, "MET_corrPx"};
//   TTreeReaderArray<float> MET_corrPy = {fReader, "MET_corrPy"};
//   TTreeReaderArray<float> MET_et = {fReader, "MET_et"};
//   TTreeReaderArray<float> MET_phi = {fReader, "MET_phi"};
//   TTreeReaderArray<float> MET_puppi_et = {fReader, "MET_puppi_et"};
//   TTreeReaderArray<float> MET_puppi_phi = {fReader, "MET_puppi_phi"};
//   TTreeReaderArray<float> MET_sumEt = {fReader, "MET_sumEt"};
//   TTreeReaderArray<float> MET_JetEnUp = {fReader, "MET_JetEnUp"};
//   TTreeReaderArray<float> MET_JetEnDown = {fReader, "MET_JetEnDown"};
//   TTreeReaderArray<float> MET_JetResUp = {fReader, "MET_JetResUp"};
//   TTreeReaderArray<float> MET_JetResDown = {fReader, "MET_JetResDown"};
//   TTreeReaderArray<float> MET_UnclusteredEnUp = {fReader, "MET_UnclusteredEnUp"};
//   TTreeReaderArray<float> MET_UnclusteredEnDown = {fReader, "MET_UnclusteredEnDown"};
//   TTreeReaderArray<float> MET_significance = {fReader, "MET_significance"};
//   TTreeReaderArray<float> MET_cov00 = {fReader, "MET_cov00"};
//   TTreeReaderArray<float> MET_cov10 = {fReader, "MET_cov10"};
//   TTreeReaderArray<float> MET_cov11 = {fReader, "MET_cov11"};
//   TTreeReaderValue<Int_t> EVENT_event = {fReader, "EVENT_event"};
//   TTreeReaderValue<Int_t> EVENT_run = {fReader, "EVENT_run"};
//   TTreeReaderValue<Int_t> EVENT_lumiBlock = {fReader, "EVENT_lumiBlock"};
//   TTreeReaderArray<float> nPuVtxTrue = {fReader, "nPuVtxTrue"};
//   TTreeReaderArray<int> nPuVtx = {fReader, "nPuVtx"};
//   TTreeReaderArray<int> bX = {fReader, "bX"};
//   TTreeReaderValue<Int_t> PV_N = {fReader, "PV_N"};
//   TTreeReaderValue<Bool_t> PV_filter = {fReader, "PV_filter"};
//   TTreeReaderArray<float> PV_chi2 = {fReader, "PV_chi2"};
//   TTreeReaderArray<float> PV_ndof = {fReader, "PV_ndof"};
//   TTreeReaderArray<float> PV_rho = {fReader, "PV_rho"};
//   TTreeReaderArray<float> PV_z = {fReader, "PV_z"};
//   TTreeReaderArray<float> BeamSpot_x0 = {fReader, "BeamSpot_x0"};
//   TTreeReaderArray<float> BeamSpot_y0 = {fReader, "BeamSpot_y0"};
//   TTreeReaderArray<float> BeamSpot_z0 = {fReader, "BeamSpot_z0"};
//   TTreeReaderArray<int> IsJpsiMu = {fReader, "IsJpsiMu"};
//   TTreeReaderArray<int> IsJpsiEle = {fReader, "IsJpsiEle"};
//   TTreeReaderArray<float> Jpsi_mu1_pt = {fReader, "Jpsi_mu1_pt"};
//   TTreeReaderArray<float> Jpsi_mu1_eta = {fReader, "Jpsi_mu1_eta"};
//   TTreeReaderArray<float> Jpsi_mu1_phi = {fReader, "Jpsi_mu1_phi"};
//   TTreeReaderArray<int> Jpsi_mu1_ch = {fReader, "Jpsi_mu1_ch"};
//   TTreeReaderArray<int> Jpsi_mu1_isLoose = {fReader, "Jpsi_mu1_isLoose"};
//   TTreeReaderArray<int> Jpsi_mu1_isTight = {fReader, "Jpsi_mu1_isTight"};
//   TTreeReaderArray<int> Jpsi_mu1_isPF = {fReader, "Jpsi_mu1_isPF"};
//   TTreeReaderArray<int> Jpsi_mu1_isGlobal = {fReader, "Jpsi_mu1_isGlobal"};
//   TTreeReaderArray<int> Jpsi_mu1_isTracker = {fReader, "Jpsi_mu1_isTracker"};
//   TTreeReaderArray<int> Jpsi_mu1_isSoft = {fReader, "Jpsi_mu1_isSoft"};
//   TTreeReaderArray<float> Jpsi_mu2_pt = {fReader, "Jpsi_mu2_pt"};
//   TTreeReaderArray<float> Jpsi_mu2_eta = {fReader, "Jpsi_mu2_eta"};
//   TTreeReaderArray<float> Jpsi_mu2_phi = {fReader, "Jpsi_mu2_phi"};
//   TTreeReaderArray<int> Jpsi_mu2_ch = {fReader, "Jpsi_mu2_ch"};
//   TTreeReaderArray<float> Jpsi_mu2_isLoose = {fReader, "Jpsi_mu2_isLoose"};
//   TTreeReaderArray<float> Jpsi_mu2_isTight = {fReader, "Jpsi_mu2_isTight"};
//   TTreeReaderArray<float> Jpsi_mu2_isPF = {fReader, "Jpsi_mu2_isPF"};
//   TTreeReaderArray<float> Jpsi_mu2_isGlobal = {fReader, "Jpsi_mu2_isGlobal"};
//   TTreeReaderArray<float> Jpsi_mu2_isTracker = {fReader, "Jpsi_mu2_isTracker"};
//   TTreeReaderArray<float> Jpsi_mu2_isSoft = {fReader, "Jpsi_mu2_isSoft"};
//   TTreeReaderArray<float> Jpsi_mu3_pt = {fReader, "Jpsi_mu3_pt"};
//   TTreeReaderArray<float> Jpsi_mu3_eta = {fReader, "Jpsi_mu3_eta"};
//   TTreeReaderArray<float> Jpsi_mu3_phi = {fReader, "Jpsi_mu3_phi"};
//   TTreeReaderArray<int> Jpsi_mu3_ch = {fReader, "Jpsi_mu3_ch"};
//   TTreeReaderArray<float> Jpsi_mu3_isLoose = {fReader, "Jpsi_mu3_isLoose"};
//   TTreeReaderArray<float> Jpsi_mu3_isTight = {fReader, "Jpsi_mu3_isTight"};
//   TTreeReaderArray<float> Jpsi_mu3_isPF = {fReader, "Jpsi_mu3_isPF"};
//   TTreeReaderArray<float> Jpsi_mu3_isGlobal = {fReader, "Jpsi_mu3_isGlobal"};
//   TTreeReaderArray<float> Jpsi_mu3_isTracker = {fReader, "Jpsi_mu3_isTracker"};
//   TTreeReaderArray<float> Jpsi_mu3_isSoft = {fReader, "Jpsi_mu3_isSoft"};
//   TTreeReaderArray<float> Jpsi_mu3_x = {fReader, "Jpsi_mu3_x"};
//   TTreeReaderArray<float> Jpsi_mu3_y = {fReader, "Jpsi_mu3_y"};
//   TTreeReaderArray<float> Jpsi_mu3_z = {fReader, "Jpsi_mu3_z"};
//   TTreeReaderArray<float> Jpsi_mu3_isopt03 = {fReader, "Jpsi_mu3_isopt03"};
//   TTreeReaderArray<float> Jpsi_mu3_isopt04 = {fReader, "Jpsi_mu3_isopt04"};
//   TTreeReaderArray<float> Jpsi_mu3_isopt05 = {fReader, "Jpsi_mu3_isopt05"};
//   TTreeReaderArray<float> Jpsi_mu3_isopt06 = {fReader, "Jpsi_mu3_isopt06"};
//   TTreeReaderArray<float> Jpsi_mu3_isopt07 = {fReader, "Jpsi_mu3_isopt07"};
//   TTreeReaderArray<float> Jpsi_dr_mu3pf = {fReader, "Jpsi_dr_mu3pf"};
//   TTreeReaderArray<float> Jpsi_dx = {fReader, "Jpsi_dx"};
//   TTreeReaderArray<float> Jpsi_dy = {fReader, "Jpsi_dy"};
//   TTreeReaderArray<float> Jpsi_dz = {fReader, "Jpsi_dz"};
//   TTreeReaderArray<float> Jpsi_pt = {fReader, "Jpsi_pt"};
//   TTreeReaderArray<float> Jpsi_eta = {fReader, "Jpsi_eta"};
//   TTreeReaderArray<float> Jpsi_phi = {fReader, "Jpsi_phi"};
//   TTreeReaderArray<float> Jpsi_mass = {fReader, "Jpsi_mass"};
//   TTreeReaderArray<float> Jpsi_vtxprob = {fReader, "Jpsi_vtxprob"};
//   TTreeReaderArray<float> Jpsi_vtxz = {fReader, "Jpsi_vtxz"};
//   TTreeReaderArray<float> Jpsi_trimu_dx = {fReader, "Jpsi_trimu_dx"};
//   TTreeReaderArray<float> Jpsi_trimu_dy = {fReader, "Jpsi_trimu_dy"};
//   TTreeReaderArray<float> Jpsi_trimu_dz = {fReader, "Jpsi_trimu_dz"};
//   TTreeReaderArray<float> Jpsi_trimu_pt = {fReader, "Jpsi_trimu_pt"};
//   TTreeReaderArray<float> Jpsi_trimu_eta = {fReader, "Jpsi_trimu_eta"};
//   TTreeReaderArray<float> Jpsi_trimu_phi = {fReader, "Jpsi_trimu_phi"};
   TTreeReaderArray<float> Jpsi_trimu_mass = {fReader, "Jpsi_trimu_mass"};
//   TTreeReaderArray<float> Jpsi_trimu_vtxprob = {fReader, "Jpsi_trimu_vtxprob"};
//   TTreeReaderArray<float> Jpsi_trimu_vtxz = {fReader, "Jpsi_trimu_vtxz"};
//   TTreeReaderArray<float> Jpsi_PV_x = {fReader, "Jpsi_PV_x"};
//   TTreeReaderArray<float> Jpsi_PV_y = {fReader, "Jpsi_PV_y"};
//   TTreeReaderArray<float> Jpsi_PV_z = {fReader, "Jpsi_PV_z"};
//   TTreeReaderArray<float> Jpsi_flightSig3D = {fReader, "Jpsi_flightSig3D"};
//   TTreeReaderArray<float> Jpsi_flightLength3D = {fReader, "Jpsi_flightLength3D"};
//   TTreeReaderArray<float> Jpsi_flightLengthErr3D = {fReader, "Jpsi_flightLengthErr3D"};
//   TTreeReaderArray<float> Jpsi_flightSig2D = {fReader, "Jpsi_flightSig2D"};
//   TTreeReaderArray<float> Jpsi_flightLength2D = {fReader, "Jpsi_flightLength2D"};
//   TTreeReaderArray<float> Jpsi_flightLengthErr2D = {fReader, "Jpsi_flightLengthErr2D"};
//   TTreeReaderArray<float> Jpsi_trimu_flightSig3D = {fReader, "Jpsi_trimu_flightSig3D"};
//   TTreeReaderArray<float> Jpsi_trimu_flightLength3D = {fReader, "Jpsi_trimu_flightLength3D"};
//   TTreeReaderArray<float> Jpsi_trimu_flightLengthErr3D = {fReader, "Jpsi_trimu_flightLengthErr3D"};
//   TTreeReaderArray<float> Jpsi_trimu_flightSig2D = {fReader, "Jpsi_trimu_flightSig2D"};
//   TTreeReaderArray<float> Jpsi_trimu_flightLength2D = {fReader, "Jpsi_trimu_flightLength2D"};
//   TTreeReaderArray<float> Jpsi_trimu_flightLengthErr2D = {fReader, "Jpsi_trimu_flightLengthErr2D"};


   GenLevel(TTree * /*tree*/ =0) { }
   virtual ~GenLevel() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   double deltarlimit = 0.4;
   double mumass = 0.1056583745;
// candidate b daughters

 static const int jpsipdgid = 443;
 static const int muonpdgid = 13;
 static const int pipluspdgid = 211;
 static const int kpluspdgid = 321;
// candidate b's

  static const int b0pdgid = 511;
  static const int bpluspdgid = 521;
  static const int bspdgid = 531;
  static const int bcpdgid = 541;

   vector<int> outvec = {muonpdgid, pipluspdgid, kpluspdgid};

   vector<int> Bvec = {b0pdgid, bpluspdgid, bspdgid, bcpdgid};

// gen level B masses

   TH1D* b0mass = new TH1D("b0mass", "Gen Level B^{0} Mass", 40, 0, 8);
   TH1D* bpmass = new TH1D("bpmass", "Gen Level B^{+} Mass", 40, 0, 8);
   TH1D* bsmass = new TH1D("bsmass", "Gen Level B_{s}^{0} Mass", 40, 0, 8);
   TH1D* bcmass = new TH1D("bcmass", "Gen Level B_{c}^{+} Mass", 40, 0, 8);

// reco level visible B masses

   TH1D* trimu = new TH1D("trimu", "B Meson Mass (GeV)", 40, 0, 8);
   TH1D* b0trimu = new TH1D("b0trimu", "B^{0} decay at Gen Level", 40, 0, 8);
   TH1D* bptrimu = new TH1D("bptrimu", "B^{+} decay at Gen Level", 40, 0, 8);
   TH1D* bstrimu = new TH1D("bstrimu", "B_{s}^{0} decay at Gen Level", 40, 0, 8);
   TH1D* bctrimu = new TH1D("bctrimu", "B_{c}^{+} decay at Gen Level", 40, 0, 8);

// reco level trimuon mass tagged by X (misid muon candidate)

   TH1D* mutrimu = new TH1D("mutrimu", "B->J/#psi+mu^{#pm}+#nu_{#mu}+X at Gen Level", 40, 0, 8);
   TH1D* pitrimu = new TH1D("pitrimu", "B->J/#psi+#pi^{#pm}+X at Gen Level", 40, 0, 8);
   TH1D* ktrimu = new TH1D("ktrimu", "B->J/#psi+K^{#pm}+X at Gen Level", 40, 0, 8);

// dummy histograms

   TH1D* dummy1 = new TH1D("dummy1", "dummy histo 1`", 40, 0, 8);
   TH1D* dummy2 = new TH1D("dummy2", "dummy histo 2`", 40, 0, 8);

   ClassDef(GenLevel,0);

};

#endif

#ifdef GenLevel_cxx
void GenLevel::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t GenLevel::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef GenLevel_cxx
