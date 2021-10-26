package screens

import (
	"distribution/distribution"
	"github.com/AllenDang/giu"
)

var (
	gaussMean     = float32(1.0)
	gaussStd      = float32(1.0)
	gaussN        = int32(6)
	gaussLength   = int32(1000)
	gaussSequence []float64
)

func gaussInputs() giu.Widget {
	return giu.Column(
		giu.Row(
			giu.Label("Mean"),
			giu.InputFloat("Mean", &gaussMean),
		),
		giu.Row(
			giu.Label("Std"),
			giu.InputFloat("parameter", &gaussStd),
		),
		giu.Row(
			giu.Label("N"),
			giu.InputInt(&gaussN),
		),
		giu.Row(
			giu.Label("Length"),
			giu.InputInt(&gaussLength),
		),
		giu.Button("Calculate").OnClick(func() {
			gauss := distribution.CreateGaussianDistribution(float64(gaussMean), float64(gaussStd), int(gaussN), int(gaussLength))
			gaussSequence = gauss.Generate()
		}),
	)
}

func Gaussian() *giu.TabItemWidget {
	gaussPlot := giu.Plot("Gaussian distribution")
	gaussPlot.Size(-1, -1)
	gaussPlotBar := giu.PlotBar("Gaussian", gaussSequence)
	gaussPlot.Plots(gaussPlotBar)

	item := giu.TabItem("Gaussian")
	item.Layout(gaussInputs(), gaussPlot)
	return item
}
