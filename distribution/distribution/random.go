package distribution

import "math/rand"

type Random struct {
	length int
}

func (r Random) Generate() []float64 {
	dist := make([]float64, r.length)
	for i := range dist {
		dist[i] = rand.Float64()
	}
	return dist
}

func CreateRandomDistribution(length int) Distribution {
	return &Random{length: length}
}
