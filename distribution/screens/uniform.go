package screens

import (
	"distribution/distribution"
	"github.com/AllenDang/giu"
)

var (
	uniformA        = float32(1.0)
	uniformB        = float32(1)
	uniformLength   = int32(1000)
	uniformSequence []float64
)

func uniformInputs() giu.Widget {
	return giu.Column(
		giu.InputFloat("A", &uniformA),
		giu.InputFloat("B", &uniformB),
		giu.InputInt(&uniformLength),
		giu.Button("Calculate").OnClick(func() {
			uniform := distribution.CreateUniformDistribution(float64(uniformA), float64(uniformB), int(uniformLength))
			uniformSequence = uniform.Generate()
		}),
	)
}

func Uniform() *giu.TabItemWidget {
	uniformPlot := giu.Plot("Uniform distribution")
	uniformPlot.Size(-1, -1)
	uniformPlotBar := giu.PlotBar("Uniform", uniformSequence)
	uniformPlot.Plots(uniformPlotBar)

	item := giu.TabItem("Uniform")
	item.Layout(uniformInputs(), uniformPlot)
	return item
}
