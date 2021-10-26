package distribution

import "math"

type Gamma struct {
	eta    int
	length int
	lambda float64
}

func (g Gamma) Generate() []float64 {
	randGen := CreateRandomDistribution(g.eta)
	gamma := make([]float64, g.length)

	for i := range gamma {
		randDist := randGen.Generate()
		total := 1.0
		for j := range randDist {
			total *= randDist[j]
		}
		gamma[i] = -1 / g.lambda * math.Log(total)
	}

	return gamma
}

func CreateGammaDistribution(eta int, lambda float64, length int) Distribution {
	return &Gamma{
		eta:    eta,
		length: length,
		lambda: lambda,
	}
}
