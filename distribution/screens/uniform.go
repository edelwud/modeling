package screens

import (
	"distribution/distribution"
	"distribution/utils"
	"fmt"
	"github.com/AllenDang/giu"
)

var (
	uniformMean      = float32(0.0)
	uniformDeviation = float32(0.0)
	uniformVariance  = float32(0.0)
	uniformA         = float32(2.0)
	uniformB         = float32(1.0)
	uniformLength    = int32(100000)
	uniformSequence  []float64
)

func uniformInputs() giu.Widget {
	return giu.Column(
		giu.Row(
			giu.Label("A"),
			giu.InputFloat("A", &uniformA),
		),
		giu.Row(
			giu.Label("B"),
			giu.InputFloat("B", &uniformB),
		),
		giu.Row(
			giu.Label("Length"),
			giu.InputInt(&uniformLength),
		),
		giu.Button("Calculate").OnClick(func() {
			uniform := distribution.CreateUniformDistribution(float64(uniformA), float64(uniformB), int(uniformLength))
			uniformSequence = uniform.Generate()
			uniformMean = float32(utils.Mean(uniformSequence))
			uniformDeviation = float32(utils.Deviation(uniformSequence))
			uniformVariance = float32(utils.Variance(uniformSequence))
		}),
		giu.Row(giu.Label("Mean: "+fmt.Sprintf("%.2f", uniformMean))),
		giu.Row(giu.Label("Deviation: "+fmt.Sprintf("%.2f", uniformDeviation))),
		giu.Row(giu.Label("Variance: "+fmt.Sprintf("%.2f", uniformVariance))),
	)
}

func Uniform() *giu.TabItemWidget {
	uniformPlot := giu.Plot("Uniform distribution")
	uniformPlot.Size(-1, -1)
	seq, ticks := utils.Distribute(uniformSequence, 25)
	uniformPlotBar := giu.PlotBar("Uniform", seq)
	uniformPlot.XTicks(ticks, false)
	uniformPlot.Plots(uniformPlotBar)

	item := giu.TabItem("Uniform")
	item.Layout(uniformInputs(), uniformPlot)
	return item
}
