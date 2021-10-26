package distribution

import "math/rand"

type MaxTriangle struct {
	a      float64
	b      float64
	length int
}

func (t MaxTriangle) Generate() []float64 {
	maxTriangle := make([]float64, t.length)

	for i := range maxTriangle {
		x := rand.Float64()
		y := rand.Float64()
		value := 0.0

		if x >= y {
			value = x
		} else {
			value = y
		}

		maxTriangle[i] = t.a + (t.b-t.a)*value
	}

	return maxTriangle
}

func CreateMaxTriangleDistribution(a float64, b float64, length int) Distribution {
	return &MaxTriangle{
		a:      a,
		b:      b,
		length: length,
	}
}
