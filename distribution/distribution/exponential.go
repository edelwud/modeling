package distribution

import "math"

type Exponential struct {
	length int
	param  float64
}

func (e Exponential) Generate() []float64 {
	randDist := CreateRandomDistribution(e.length)
	rand := randDist.Generate()

	exp := make([]float64, e.length)

	for i := range exp {
		exp[i] = -1 / e.param * math.Log(rand[i])
	}

	return exp
}

func CreateExponentialDistribution(param float64, length int) Distribution {
	return &Exponential{
		length: length,
		param:  param,
	}
}
