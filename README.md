# ETCode
Macros and data for fitting pT spectra. 
The macros within this file have different functions but all stem from a similar sequence of execution. Each function stems from this initial sequence:

root STARDattoRootv2.cpp
	This macro uploads all data for STAR pi,k,p,omega and eta into 		a root file, ALLSTAR.root. 

root STARLAMtoRootv2.cpp
	uploads all data for STAR lam and alam into a root file, 	STARLAM.root. 

After running these two macros, the data is available in two separate rootfiles and all other functions are ran from this point. There are 4 functions that can be ran after this and I have created .bash files to make execution easier. The four .bash files and their functions are detailed below:

1. fitcompare.bash – fits all histos in ALLSTAR.root and outputs parameters, fitting errors and ET to compfitResults.dat. Output is in Biswas format and can be plugged into final ET graph generator to produce plots from Biswas’s thesis. Produces fitted plots and saves them to fittedPlots51. Run Time ~ 1.5 hours

2. fitcompareavg.bash – fits all histos in ALLSTAR.root and outputs ET and N in tanner format. Averages results from each fit into avgfitResults.dat. Saves plots to fittedPlots55. Run time ~ 30 min.

3. fitcomparelam.bash – same as 1 but for STARLAM.root. Outputs to compfitLAMResults.dat. Saves fitted plots to fittedPlots51.

4. fitlamavg.bash – same as 2 but for STARLAM.root. Outputs to avgLAMResults.dat. Saves plots to fittedPlots56. 

Other macros and folders are described below:
fitBESData10.h – library created containing all fitting function and Nparts for each collisional energy at every centrality. This library is crucial to all fitting operations.
 
Paperplot.C- creates 3x3 plot of fitted spectra. 

Data- contains all data for each particle and centraility for collisonal energies; 7.7, 11.5, 19.6, 27,39,62.4,130 and 200 GeV. 


Example demonstrating how to produce averagefit results for Pi,k,p:

	cd/TannerETCode

	root STARDattoRootv2.cpp ~ 1 min.
	.q 
	source fitcompareavg.bash  ~ 90 mins. 

Plots are produced in fittedPlots56 and new data is outputted to avgfitResults.dat.
