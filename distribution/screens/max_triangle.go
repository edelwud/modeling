package screens

import (
	"distribution/distribution"
	"github.com/AllenDang/giu"
)

var (
	maxTriangleA        = float32(2.0)
	maxTriangleB        = float32(1.0)
	maxTriangleLength   = int32(1000)
	maxTriangleSequence []float64
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
		}),
	)
}

func MaxTriangle() *giu.TabItemWidget {
	maxTrianglePlot := giu.Plot("Max triangle distribution")
	maxTrianglePlot.Size(-1, -1)
	maxTrianglePlotBar := giu.PlotBar("Max triangle", maxTriangleSequence)
	maxTrianglePlot.Plots(maxTrianglePlotBar)

	item := giu.TabItem("Max triangle")
	item.Layout(maxTriangleInputs(), maxTrianglePlot)
	return item
}
