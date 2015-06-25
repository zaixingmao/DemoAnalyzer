import FWCore.ParameterSet.Config as cms
import os

process = cms.Process("Demo")

# initialize MessageLogger and output report
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.threshold = 'INFO'
process.MessageLogger.categories.append('Demo')
process.MessageLogger.cerr.INFO = cms.untracked.PSet(
    limit = cms.untracked.int32(-1)
)
process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )


process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )


flists = []
flists.append([])
counter = 0
dirName = '/hdfs/store/mc/Phys14DR/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/MINIAODSIM/PU20bx25_tsg_PHYS14_25_V1-v2/00000/'                                                              
for iFile in os.listdir(dirName):                                                                                                                                                   
    fName = 'file://' + dirName + iFile                                                                                                                                             
    if len(flists[counter]) > 250:                                                                                                                                                  
        flists.append([])                                                                                                                                                           
        counter += 1                                                                                                                                                                
    flists[counter].append(fName)                                                                                                                                                   
print counter                                                                                                                                                                       



process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
          fileNames = cms.untracked.vstring(flists[0]),#'file:///hdfs/store/mc/Phys14DR/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/MINIAODSIM/PU20bx25_tsg_PHYS14_25_V1-v2/10000/6617651C-4977-E411-9156-3417EBE2F493.root'),
          eventsToProcess = cms.untracked.VEventRange('1:836:83514'),

)

process.demo = cms.EDAnalyzer('DemoAnalyzer'
)


process.p = cms.Path(process.demo)
