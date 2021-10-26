package screens

import (
	"distribution/distribution"
	"distribution/utils"
	"github.com/AllenDang/giu"
)

var (
	expoParam    = float32(1.0)
	expoLength   = int32(1000)
	expoSequence []float64
)

func expoInputs() giu.Widget {
	return giu.Column(
		giu.Row(
			giu.Label("Parameter"),
			giu.InputFloat("parameter", &expoParam),
		),
		giu.Row(
			giu.Label("Length"),
			giu.InputInt(&expoLength),
		),
		giu.Button("Calculate").OnClick(func() {
			expo := distribution.CreateExponentialDistribution(float64(expoParam), int(expoLength))
			expoSequence = expo.Generate()
		}),
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
