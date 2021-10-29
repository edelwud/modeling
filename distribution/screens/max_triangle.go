package screens

import (
	"distribution/distribution"
	"distribution/utils"
	"fmt"
	"github.com/AllenDang/giu"
)

var (
	maxTriangleMean      = float32(0.0)
	maxTriangleDeviation = float32(0.0)
	maxTriangleVariance  = float32(0.0)
	maxTriangleA         = float32(1.0)
	maxTriangleB         = float32(2.0)
	maxTriangleLength    = int32(100000)
	maxTriangleSequence  []float64
)

func maxTriangleInputs() giu.Widget {
	return giu.Column(
		giu.Row(
			giu.Label("A"),
			giu.InputFloat("A", &maxTriangleA),
		),
		giu.Row(
			giu.Label("B"),
			giu.InputFloat("B", &maxTriangleB),
		),
		giu.Row(
			giu.Label("Length"),
			giu.InputInt(&maxTriangleLength),
		),
		giu.Button("Calculate").OnClick(func() {
			maxTriangle := distribution.CreateMaxTriangleDistribution(float64(maxTriangleA), float64(maxTriangleB), int(maxTriangleLength))
			maxTriangleSequence = maxTriangle.Generate()
			maxTriangleMean = float32(utils.Mean(maxTriangleSequence))
			maxTriangleDeviation = float32(utils.Deviation(maxTriangleSequence))
			maxTriangleVariance = float32(utils.Variance(maxTriangleSequence))
		}),
		giu.Row(giu.Label("Mean: "+fmt.Sprintf("%.2f", maxTriangleMean))),
		giu.Row(giu.Label("Deviation: "+fmt.Sprintf("%.2f", maxTriangleDeviation))),
		giu.Row(giu.Label("Variance: "+fmt.Sprintf("%.2f", maxTriangleVariance))),
	)
}

func MaxTriangle() *giu.TabItemWidget {
	maxTrianglePlot := giu.Plot("Max triangle distribution")
	maxTrianglePlot.Size(-1, -1)
	seq, ticks := utils.Distribute(maxTriangleSequence, 25)
	maxTrianglePlotBar := giu.PlotBar("Max triangle", seq)
	maxTrianglePlot.XTicks(ticks, false)
	maxTrianglePlot.Plots(maxTrianglePlotBar)

	item := giu.TabItem("Max triangle")
	item.Layout(maxTriangleInputs(), maxTrianglePlot)
	return item
}
