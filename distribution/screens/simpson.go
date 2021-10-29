package screens

import (
	"distribution/distribution"
	"distribution/utils"
	"fmt"
	"github.com/AllenDang/giu"
)

var (
	simpsonMean      = float32(0.0)
	simpsonDeviation = float32(0.0)
	simpsonVariance  = float32(0.0)
	simpsonA         = float32(2.0)
	simpsonB         = float32(1.0)
	simpsonLength    = int32(100000)
	simpsonSequence  []float64
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
			simpsonMean = float32(utils.Mean(simpsonSequence))
			simpsonDeviation = float32(utils.Deviation(simpsonSequence))
			simpsonVariance = float32(utils.Variance(simpsonSequence))
		}),
		giu.Row(giu.Label("Mean: "+fmt.Sprintf("%.2f", simpsonMean))),
		giu.Row(giu.Label("Deviation: "+fmt.Sprintf("%.2f", simpsonDeviation))),
		giu.Row(giu.Label("Variance: "+fmt.Sprintf("%.2f", simpsonVariance))),
	)
}

func Simpson() *giu.TabItemWidget {
	simpsonPlot := giu.Plot("Simpson distribution")
	simpsonPlot.Size(-1, -1)
	seq, ticks := utils.Distribute(simpsonSequence, 25)
	simpsonPlotBar := giu.PlotBar("Simpson", seq)
	simpsonPlot.XTicks(ticks, false)
	simpsonPlot.Plots(simpsonPlotBar)

	item := giu.TabItem("Simpson")
	item.Layout(simpsonInputs(), simpsonPlot)
	return item
}
