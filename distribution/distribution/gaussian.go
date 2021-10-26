package distribution

import "math"

type Gaussian struct {
	mean   float64
	std    float64
	n      int
	length int
}

func (g Gaussian) Generate() []float64 {
	randGen := CreateRandomDistribution(g.n)
	gaussian := make([]float64, g.length)

	for i := range gaussian {
		randDist := randGen.Generate()
		sum := 0.0
		for j := range randDist {
			sum += randDist[j]
		}
		gaussian[i] = g.mean + g.std*math.Sqrt(12/float64(g.n))*(sum-float64(g.n)/2)
	}

	return gaussian
}

func CreateGaussianDistribution(mean float64, std float64, n int, length int) Distribution {
	return &Gaussian{
		mean:   mean,
		std:    std,
		n:      n,
		length: length,
	}
}
