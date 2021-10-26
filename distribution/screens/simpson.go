package screens

import (
	"distribution/distribution"
	"github.com/AllenDang/giu"
)

var (
	simpsonA        = float32(2.0)
	simpsonB        = float32(1.0)
	simpsonLength   = int32(1000)
	simpsonSequence []float64
)

func simpsonInputs() giu.Widget {
	return giu.Column(
		giu.Row(
			giu.Label("A"),
			giu.InputFloat("A", &simpsonA),
		),
		giu.Row(
			giu.Label("B"),
			giu.InputFloat("B", &simpsonB),
		),
		giu.Row(
			giu.Label("Length"),
			giu.InputInt(&simpsonLength),
		),
		giu.Button("Calculate").OnClick(func() {
			simpson := distribution.CreateSimpsonDistribution(float64(simpsonA), float64(simpsonB), int(simpsonLength))
			simpsonSequence = simpson.Generate()
		}),
	)
}

func Simpson() *giu.TabItemWidget {
	simpsonPlot := giu.Plot("Simpson distribution")
	simpsonPlot.Size(-1, -1)
	simpsonPlotBar := giu.PlotBar("Simpson", simpsonSequence)
	simpsonPlot.Plots(simpsonPlotBar)

	item := giu.TabItem("Simpson")
	item.Layout(simpsonInputs(), simpsonPlot)
	return item
}
