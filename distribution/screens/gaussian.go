package screens

import (
	"distribution/distribution"
	"distribution/utils"
	"fmt"
	"github.com/AllenDang/giu"
)

var (
	gaussMean2     = float32(0.0)
	gaussDeviation = float32(0.0)
	gaussVariance  = float32(0.0)
	gaussMean      = float32(1.0)
	gaussStd       = float32(1.0)
	gaussN         = int32(6)
	gaussLength    = int32(100000)
	gaussSequence  []float64
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
			gaussMean2 = float32(utils.Mean(gaussSequence))
			gaussDeviation = float32(utils.Deviation(gaussSequence))
			gaussVariance = float32(utils.Variance(gaussSequence))
		}),
		giu.Row(giu.Label("Mean: "+fmt.Sprintf("%.2f", gaussMean2))),
		giu.Row(giu.Label("Deviation: "+fmt.Sprintf("%.2f", gaussDeviation))),
		giu.Row(giu.Label("Variance: "+fmt.Sprintf("%.2f", gaussVariance))),
	)
}

func Gaussian() *giu.TabItemWidget {
	gaussPlot := giu.Plot("Gaussian distribution")
	gaussPlot.Size(-1, -1)
	seq, ticks := utils.Distribute(gaussSequence, 25)
	gaussPlotBar := giu.PlotBar("Gaussian", seq)
	gaussPlot.XTicks(ticks, false)
	gaussPlot.Plots(gaussPlotBar)

	item := giu.TabItem("Gaussian")
	item.Layout(gaussInputs(), gaussPlot)
	return item
}
