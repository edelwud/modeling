package distribution

import "math"

type Gamma struct {
	eta    int
	length int
	param  float64
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
		gamma[i] = -1 / g.param * math.Log(total)
	}

	return gamma
}

func CreateGammaDistribution(eta int, param float64, length int) Distribution {
	return &Gamma{
		eta:    eta,
		length: length,
		param:  param,
	}
}
