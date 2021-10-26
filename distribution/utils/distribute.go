package utils

import (
	"fmt"
	"github.com/AllenDang/giu"
	"math"
)

func FindMinMax(sequence []float64) (float64, float64) {
	max := -math.MaxFloat64
	min := math.MaxFloat64

	for _, value := range sequence {
		if value > max {
			max = value
		}
		if value < min {
			min = value
		}
	}

	return min, max
}

func Distribute(sequence []float64, intervals int) ([]float64, []giu.PlotTicker) {
	min, max := FindMinMax(sequence)
	delta := max - min
	period := delta / float64(intervals)

	dist := make([]float64, intervals+1)
	labels := make([]giu.PlotTicker, intervals+1)
	j := 0

	for i := min; i <= max; i += period {
		for _, value := range sequence {
			if value >= i && value < i+period {
				dist[j]++
			}
		}
		labels[j].Label = fmt.Sprintf("(%.1f, %.1f)", i, i+period)
		labels[j].Position = float64(j)
		j++
	}

	return dist, labels
}
