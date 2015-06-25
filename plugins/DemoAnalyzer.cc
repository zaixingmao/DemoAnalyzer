// -*- C++ -*-
//
// Package:    Demo/DemoAnalyzer
// Class:      DemoAnalyzer
// 
/**\class DemoAnalyzer DemoAnalyzer.cc Demo/DemoAnalyzer/plugins/DemoAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Zaixing Mao
//         Created:  Wed, 24 Jun 2015 15:37:29 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"

#include "FWCore/Framework/interface/MakerMacros.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/PatCandidates/interface/Tau.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/MET.h"

#include "RecoTauTag/RecoTau/interface/PFTauDecayModeTools.h"


#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
//
// class declaration
//

class DemoAnalyzer : public edm::EDAnalyzer {
   public:
      explicit DemoAnalyzer(const edm::ParameterSet&);
      ~DemoAnalyzer();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

      //virtual void beginRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void endRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
      //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;

      // ----------member data ---------------------------
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
DemoAnalyzer::DemoAnalyzer(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed

}


DemoAnalyzer::~DemoAnalyzer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
DemoAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;

   edm::Handle<edm::View<pat::Tau> > taus;
   iEvent.getByLabel("slimmedTaus", taus);

   edm::PtrVector<pat::Tau> ptrs = taus->ptrVector();
   for(unsigned int i=0; i!= ptrs.size(); ++i){
        pat::Tau tau = *ptrs[i];
        std::cout<<"tau pt:  "<<tau.pt()<<std::endl;
        std::cout<<"tau eta: "<<tau.eta()<<std::endl;
        std::cout<<"tau phi: "<<tau.phi()<<std::endl;
        std::cout<<"tau iso: "<<tau.tauID("byCombinedIsolationDeltaBetaCorrRaw3Hits")<<std::endl;
        std::cout<<std::endl;
    }

   edm::Handle<edm::View<pat::Jet> > jets;
   iEvent.getByLabel("slimmedJets", jets);
   edm::PtrVector<pat::Jet> jetPtrs = jets->ptrVector();
   for(unsigned int i=0; i!= jetPtrs.size(); ++i){
        pat::Jet jet = *jetPtrs[i];
        std::cout<<"jet pt:  "<<jet.pt()<<std::endl;
        std::cout<<"jet eta: "<<jet.eta()<<std::endl;
        std::cout<<"jet phi: "<<jet.phi()<<std::endl;
        std::cout<<std::endl;
    }
   edm::Handle<edm::View<pat::MET> > mets;
   iEvent.getByLabel("slimmedMETs", mets);
   edm::PtrVector<pat::MET> metPtrs = mets->ptrVector();
   for(unsigned int i=0; i!= metPtrs.size(); ++i){
        pat::MET met = *metPtrs[i];
        std::cout<<"met:  "<<met.pt()<<std::endl;
        std::cout<<"met phi: "<<met.phi()<<std::endl;
        std::cout<<std::endl;
    }



#ifdef THIS_IS_AN_EVENT_EXAMPLE
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif
   
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
}


// ------------ method called once each job just before starting event loop  ------------
void 
DemoAnalyzer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
DemoAnalyzer::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
/*
void 
DemoAnalyzer::beginRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a run  ------------
/*
void 
DemoAnalyzer::endRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when starting to processes a luminosity block  ------------
/*
void 
DemoAnalyzer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a luminosity block  ------------
/*
void 
DemoAnalyzer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
DemoAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(DemoAnalyzer);
