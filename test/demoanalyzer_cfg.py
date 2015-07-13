import FWCore.ParameterSet.Config as cms
import os

flists = []
flists.append([])
counter = 0
dirName = '/hdfs/store/mc/Phys14DR/VBF_HToTauTau_M-125_13TeV-powheg-pythia6/MINIAODSIM/PU20bx25_tsg_PHYS14_25_V1-v2/10000/'                                                              
for iFile in os.listdir(dirName):                                                                                                                                                   
    fName = 'file://' + dirName + iFile                                                                                                                                             
    if len(flists[counter]) > 250:                                                                                                                                                  
        flists.append([])                                                                                                                                                           
        counter += 1                                                                                                                                                                
    flists[counter].append(fName)                                                                                                                                                   
print counter                                                                                                                                                                       


process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
                                # replace 'myfile.root' with the source file you want to use
                                fileNames = cms.untracked.vstring(flists[0]),
          eventsToProcess = cms.untracked.VEventRange('1:3050:304989', '1:3247:324687', '1:4248:424773'),
                            )

process.demo = cms.EDAnalyzer('DemoAnalyzer'
                              )


process.p = cms.Path(process.demo)
