package screens

import (
	"distribution/distribution"
	"distribution/utils"
	"fmt"
	"github.com/AllenDang/giu"
)

var (
	expoMean      = float32(0.0)
	expoDeviation = float32(0.0)
	expoVariance  = float32(0.0)
	expoLambda    = float32(1.0)
	expoLength    = int32(100000)
	expoSequence  []float64
)

func expoInputs() giu.Widget {
	return giu.Column(
		giu.Row(
			giu.Label("Lambda"),
			giu.InputFloat("Lambda", &expoLambda),
		),
		giu.Row(
			giu.Label("Length"),
			giu.InputInt(&expoLength),
		),
		giu.Button("Calculate").OnClick(func() {
			expo := distribution.CreateExponentialDistribution(float64(expoLambda), int(expoLength))
			expoSequence = expo.Generate()
			expoMean = float32(utils.Mean(expoSequence))
			expoDeviation = float32(utils.Deviation(expoSequence))
			expoVariance = float32(utils.Variance(expoSequence))
		}),
		giu.Row(giu.Label("Mean: "+fmt.Sprintf("%.2f", expoMean))),
		giu.Row(giu.Label("Deviation: "+fmt.Sprintf("%.2f", expoDeviation))),
		giu.Row(giu.Label("Variance: "+fmt.Sprintf("%.2f", expoVariance))),
	)
}

func Exponential() *giu.TabItemWidget {
	expoPlot := giu.Plot("Exponential distribution")
	expoPlot.Size(-1, -1)
	seq, ticks := utils.Distribute(expoSequence, 25)
	expoPlotBar := giu.PlotBar("Exponential", seq)
	expoPlot.XTicks(ticks, false)
	expoPlot.Plots(expoPlotBar)

	item := giu.TabItem("Exponential")
	item.Layout(expoInputs(), expoPlot)
	return item
}
