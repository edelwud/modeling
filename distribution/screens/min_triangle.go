package screens

import (
	"distribution/distribution"
	"github.com/AllenDang/giu"
)

var (
	minTriangleA        = float32(1.0)
	minTriangleB        = float32(1)
	minTriangleLength   = int32(1000)
	minTriangleSequence []float64
)

func minTriangleInputs() giu.Widget {
	return giu.Column(
		giu.InputFloat("A", &minTriangleA),
		giu.InputFloat("B", &minTriangleB),
		giu.InputInt(&minTriangleLength),
		giu.Button("Calculate").OnClick(func() {
			minTriangle := distribution.CreateMinTriangleDistribution(float64(minTriangleA), float64(minTriangleB), int(minTriangleLength))
			minTriangleSequence = minTriangle.Generate()
		}),
	)
}

func MinTriangle() *giu.TabItemWidget {
	minTrianglePlot := giu.Plot("Min triangle distribution")
	minTrianglePlot.Size(-1, -1)
	minTrianglePlotBar := giu.PlotBar("Min triangle", minTriangleSequence)
	minTrianglePlot.Plots(minTrianglePlotBar)

	item := giu.TabItem("Min triangle")
	item.Layout(minTriangleInputs(), minTrianglePlot)
	return item
}
