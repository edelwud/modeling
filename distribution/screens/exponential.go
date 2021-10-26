package screens

import (
	"distribution/distribution"
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
	expoPlotBar := giu.PlotBar("Exponential", expoSequence)
	expoPlot.Plots(expoPlotBar)

	item := giu.TabItem("Exponential")
	item.Layout(expoInputs(), expoPlot)
	return item
}
