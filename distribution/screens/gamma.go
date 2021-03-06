package screens

import (
	"distribution/distribution"
	"distribution/utils"
	"fmt"
	"github.com/AllenDang/giu"
)

var (
	gammaMean      = float32(0.0)
	gammaDeviation = float32(0.0)
	gammaVariance  = float32(0.0)
	gammaLambda    = float32(1.0)
	gammaEta       = int32(1)
	gammaLength    = int32(100000)
	gammaSequence  []float64
)

func gammaInputs() giu.Widget {
	return giu.Column(
		giu.Row(
			giu.Label("Eta"),
			giu.InputInt(&gammaEta),
		),
		giu.Row(
			giu.Label("Lambda"),
			giu.InputFloat("Lambda", &gammaLambda),
		),
		giu.Row(
			giu.Label("Length"),
			giu.InputInt(&gammaLength),
		),
		giu.Button("Calculate").OnClick(func() {
			gamma := distribution.CreateGammaDistribution(int(gammaEta), float64(gammaLambda), int(gammaLength))
			gammaSequence = gamma.Generate()
			gammaMean = float32(utils.Mean(gammaSequence))
			gammaDeviation = float32(utils.Deviation(gammaSequence))
			gammaVariance = float32(utils.Variance(gammaSequence))
		}),
		giu.Row(giu.Label("Mean: "+fmt.Sprintf("%.2f", gammaMean))),
		giu.Row(giu.Label("Deviation: "+fmt.Sprintf("%.2f", gammaDeviation))),
		giu.Row(giu.Label("Variance: "+fmt.Sprintf("%.2f", gammaVariance))),
	)
}

func Gamma() *giu.TabItemWidget {
	gammaPlot := giu.Plot("Gamma distribution")
	gammaPlot.Size(-1, -1)
	seq, ticks := utils.Distribute(gammaSequence, 25)
	gammaPlotBar := giu.PlotBar("Gamma", seq)
	gammaPlot.XTicks(ticks, false)
	gammaPlot.Plots(gammaPlotBar)

	item := giu.TabItem("Gamma")
	item.Layout(gammaInputs(), gammaPlot)
	return item
}
