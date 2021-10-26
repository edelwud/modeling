package distribution

import "math/rand"

type MinTriangle struct {
	a      float64
	b      float64
	length int
}

func (t MinTriangle) Generate() []float64 {
	minTriangle := make([]float64, t.length)

	for i := range minTriangle {
		x := rand.Float64()
		y := rand.Float64()
		value := 0.0

		if x >= y {
			value = y
		} else {
			value = x
		}

		minTriangle[i] = t.a + (t.b-t.a)*value
	}

	return minTriangle
}

func CreateMinTriangleDistribution(a float64, b float64, length int) Distribution {
	return &MinTriangle{
		a:      a,
		b:      b,
		length: length,
	}
}
