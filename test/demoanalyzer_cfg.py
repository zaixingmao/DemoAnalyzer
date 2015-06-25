import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
                                # replace 'myfile.root' with the source file you want to use
                                fileNames = cms.untracked.vstring('file:///hdfs/store/mc/Phys14DR/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/MINIAODSIM/PU20bx25_tsg_PHYS14_25_V1-v2/10000/6617651C-4977-E411-9156-3417EBE2F493.root'),
          eventsToProcess = cms.untracked.VEventRange('1:2647:264697'),
                            )

process.demo = cms.EDAnalyzer('DemoAnalyzer'
                              )


process.p = cms.Path(process.demo)
