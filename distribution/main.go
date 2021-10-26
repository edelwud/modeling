package main

import (
	"distribution/screens"
	"github.com/AllenDang/giu"
)

func loop() {
	distributions := giu.TabBar()

	distributions.TabItems(
		screens.Exponential(),
		screens.Gamma(),
		screens.Gaussian(),
		screens.MaxTriangle(),
		screens.MinTriangle(),
		screens.Simpson(),
		screens.Uniform(),
	)

	giu.SingleWindow().Layout(
		distributions,
	)
}

func main() {
	wnd := giu.NewMasterWindow("Distribution", 400, 200, giu.MasterWindowFlagsMaximized)
	wnd.Run(loop)
}
