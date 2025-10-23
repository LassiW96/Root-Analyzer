/////////////////////////////////////////////////////////////////////////
// Plot class source file
//
/////////////////////////////////////////////////////////////////////////

# include "TGraph.h"
# include "TCanvas.h"
# include "TSpline.h"

# include "GeneratePlots.h"

void GeneratePlots::PlotWaveForms(const std::string& branch, int nEvents)
{
    auto it = branchData.find(branch);
    const BranchData& arr = it->second;
    std::cout << "\nBuffer name: " << arr.name 
              << " type: " << arr.type << std::endl;

    for (int i = 0; i < nEvents; i++) {
        if (arr.bufferD.empty() && arr.bufferF.empty()) {
            std::cerr << "Error: Empty buffer!\n";
            return;
        }

        TGraph *graph1 = new TGraph();
        for (int j = 0; j < arr.ndata; j++) {
            graph1->SetPoint(graph1->GetN(), j, arr.bufferD[j]);
        }    

        // Drawing
        TCanvas *c = new TCanvas(Form("c%d", i), Form("Event%i", i), 800, 600);
        
        graph1->SetMarkerStyle(20);
        graph1->SetMarkerColor(kRed);
        graph1->SetMarkerSize(0.8);

        graph1->SetTitle(Form("Waveform for Event %d;Sample Index;ADC Counts", i));
        graph1->Draw("AP");

        // Splines fit
        TSpline3 *spline1 = new TSpline3("spline1", graph1);

        spline1->SetLineColor(kRed);
        spline1->Draw("SAME");
    }
}
