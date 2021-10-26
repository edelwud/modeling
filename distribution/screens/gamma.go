package screens

import (
	"distribution/distribution"
	"distribution/utils"
	"github.com/AllenDang/giu"
)

var (
	gammaParam    = float32(1.0)
	gammaEta      = int32(1)
	gammaLength   = int32(1000)
	gammaSequence []float64
)

func gammaInputs() giu.Widget {
	return giu.Column(
		giu.Row(
			giu.Label("Eta"),
			giu.InputInt(&gammaEta),
		),
		giu.Row(
			giu.Label("Parameter"),
			giu.InputFloat("parameter", &gammaParam),
		),
		giu.Row(
			giu.Label("Length"),
			giu.InputInt(&gammaLength),
		),
		giu.Button("Calculate").OnClick(func() {
			gamma := distribution.CreateGammaDistribution(int(gammaEta), float64(gammaParam), int(gammaLength))
			gammaSequence = gamma.Generate()
		}),
	)
}

func Gamma() *giu.TabItemWidget {
	gammaPlot := giu.Plot("Gamma distribution")
	gammaPlot.Size(-1, -1)
	seq, ticks := utils.Distribute(gammaSequence, 25)
	gammaPlotBar := giu.PlotBar("Gamma", seq)
	gammaPlot.XTicks(ticks, false)
	gammaPlot.Plots(gammaPlotBar)

	item := giu.TabItem("Gamma")
	item.Layout(gammaInputs(), gammaPlot)
	return item
}
