import FWCore.ParameterSet.Config as cms

from flashgg.MicroAOD.flashggGenDiPhotons_cfi import flashggGenDiPhotons
from flashgg.MicroAOD.flashggSelectedGenDiPhotons_cfi import flashggSelectedGenDiPhotons
from flashgg.MicroAOD.flashggSortedGenDiPhotons_cfi import flashggSortedGenDiPhotons

flashggGenDiPhotonsSequence = cms.Sequence(flashggGenDiPhotons*flashggSelectedGenDiPhotons*flashggSortedGenDiPhotons)

