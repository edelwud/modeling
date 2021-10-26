package screens

import (
	"distribution/distribution"
	"distribution/utils"
	"github.com/AllenDang/giu"
)

var (
	minTriangleA        = float32(2.0)
	minTriangleB        = float32(1.0)
	minTriangleLength   = int32(1000)
	minTriangleSequence []float64
)

func minTriangleInputs() giu.Widget {
	return giu.Column(
		giu.Row(
			giu.Label("A"),
			giu.InputFloat("A", &minTriangleA),
		),
		giu.Row(
			giu.Label("B"),
			giu.InputFloat("B", &minTriangleB),
		),
		giu.Row(
			giu.Label("Length"),
			giu.InputInt(&minTriangleLength),
		),
		giu.Button("Calculate").OnClick(func() {
			minTriangle := distribution.CreateMinTriangleDistribution(float64(minTriangleA), float64(minTriangleB), int(minTriangleLength))
			minTriangleSequence = minTriangle.Generate()
		}),
	)
}

func MinTriangle() *giu.TabItemWidget {
	minTrianglePlot := giu.Plot("Min triangle distribution")
	minTrianglePlot.Size(-1, -1)
	seq, ticks := utils.Distribute(minTriangleSequence, 25)
	minTrianglePlotBar := giu.PlotBar("Min triangle", seq)
	minTrianglePlot.XTicks(ticks, false)
	minTrianglePlot.Plots(minTrianglePlotBar)

	item := giu.TabItem("Min triangle")
	item.Layout(minTriangleInputs(), minTrianglePlot)
	return item
}
